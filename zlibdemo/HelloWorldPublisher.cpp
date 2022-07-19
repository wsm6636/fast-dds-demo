// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file HelloWorldPublisher.cpp
 *
 */

#include "HelloWorldPublisher.h"
#include <fastrtps/participant/Participant.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/Domain.h>

#include <thread>
#include <iostream>
#include <fstream>
#include "encode.h"
#include <stdlib.h>

#include "HelloWorldSubscriber.h"
#include <fastrtps/participant/Participant.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/Domain.h>
#include "HelloWorld.h"
#include <time.h>
#include <zlib.h>

using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;
time_t t;
HelloWorldPublisher mypub;

HelloWorldPublisher::HelloWorldPublisher()
    : mp_participant(nullptr)
    , mp_publisher(nullptr)
{
}

bool HelloWorldPublisher::init(const char* filename)
{
    std::ifstream  infile;
    std::string ss;
    infile.open(filename, std::ios::binary | std::ios::in);
    infile.seekg(0, std::ios_base::end);
    std::streampos sp = infile.tellg();
    int  size = sp;
    uLong tlen = sp;
    uLong blen = compressBound(tlen);	
    char* buffer = (char*)malloc(sizeof(char)*tlen);
    char* sentdata = (char*)malloc(sizeof(char)*blen);

    infile.seekg(0, std::ios_base::beg); 
    if (infile.is_open())
   		 {
			std::cout << "origin size : "<< size << std::endl;			
			infile.read(buffer,size);
			ss = base64_encode(buffer,size);
			std::cout << "encode size : "<< ss.length() << std::endl;
			buffer = (char*)ss.c_str();			
			compress((Bytef *)sentdata,&blen,(Bytef *)buffer, tlen);			
			std::cout << "compress size :"<< blen << std::endl;
  		  }

   		 infile.close();
    m_Hello.index(tlen);
    m_Hello.message("publish compress data");
    memcpy( m_Hello.data().data(),sentdata,tlen);
	
    ParticipantAttributes PParam;
    PParam.rtps.builtin.discovery_config.discoveryProtocol = DiscoveryProtocol_t::SIMPLE;
    PParam.rtps.builtin.discovery_config.use_SIMPLE_EndpointDiscoveryProtocol = true;
    PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationReaderANDSubscriptionWriter = true;
    PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationWriterANDSubscriptionReader = true;
    PParam.rtps.builtin.discovery_config.leaseDuration = c_TimeInfinite;
    PParam.rtps.setName("Participant_pub");
    mp_participant = Domain::createParticipant(PParam);

    if (mp_participant == nullptr)
    {
        return false;
    }
    //REGISTER THE TYPE

    Domain::registerType(mp_participant, &m_type);

    //CREATE THE PUBLISHER
    PublisherAttributes Wparam;
    Wparam.topic.topicKind = NO_KEY;
    Wparam.topic.topicDataType = "HelloWorld";
    Wparam.topic.topicName = "HelloWorldTopiccode";
    Wparam.topic.historyQos.kind = KEEP_LAST_HISTORY_QOS;
    Wparam.topic.historyQos.depth = 30;
    Wparam.topic.resourceLimitsQos.max_samples = 50;
    Wparam.topic.resourceLimitsQos.allocated_samples = 20;
    Wparam.times.heartbeatPeriod.seconds = 2;
    Wparam.times.heartbeatPeriod.nanosec = 200 * 1000 * 1000;
    Wparam.qos.m_reliability.kind = RELIABLE_RELIABILITY_QOS;
    mp_publisher = Domain::createPublisher(mp_participant, Wparam, (PublisherListener*)&m_listener);
    if (mp_publisher == nullptr)
    {
        return false;
    }

    return true;

}
bool HelloWorldPublisher::init(std::string mess)
{
    m_Hello.message(mess);  
     m_Hello.index(0);
    ParticipantAttributes PParam;
    PParam.rtps.builtin.discovery_config.discoveryProtocol = DiscoveryProtocol_t::SIMPLE;
    PParam.rtps.builtin.discovery_config.use_SIMPLE_EndpointDiscoveryProtocol = true;
    PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationReaderANDSubscriptionWriter = true;
    PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationWriterANDSubscriptionReader = true;
    PParam.rtps.builtin.discovery_config.leaseDuration = c_TimeInfinite;
    PParam.rtps.setName("Participant_pub");
    mp_participant = Domain::createParticipant(PParam);

    if (mp_participant == nullptr)
    {
        return false;
    }
    //REGISTER THE TYPE

    Domain::registerType(mp_participant, &m_type);

    //CREATE THE PUBLISHER
    PublisherAttributes Wparam;
    Wparam.topic.topicKind = NO_KEY;
    Wparam.topic.topicDataType = "HelloWorld";
    Wparam.topic.topicName = "HelloWorldTopicresult";
    Wparam.topic.historyQos.kind = KEEP_LAST_HISTORY_QOS;
    Wparam.topic.historyQos.depth = 30;
    Wparam.topic.resourceLimitsQos.max_samples = 50;
    Wparam.topic.resourceLimitsQos.allocated_samples = 20;
    Wparam.times.heartbeatPeriod.seconds = 2;
    Wparam.times.heartbeatPeriod.nanosec = 200 * 1000 * 1000;
    Wparam.qos.m_reliability.kind = RELIABLE_RELIABILITY_QOS;
    mp_publisher = Domain::createPublisher(mp_participant, Wparam, (PublisherListener*)&m_listener);
    if (mp_publisher == nullptr)
    {
        return false;
    }

    return true;

}
HelloWorldPublisher::~HelloWorldPublisher()
{
    // TODO Auto-generated destructor stub
    Domain::removeParticipant(mp_participant);
}

void HelloWorldPublisher::PubListener::onPublicationMatched(
        Publisher* /*pub*/,
        MatchingInfo& info)
{
    if (info.status == MATCHED_MATCHING)
    {
        n_matched++;
        firstConnected = true;
        std::cout << "Publisher matched" << std::endl;
    }
    else
    {
        n_matched--;
        std::cout << "Publisher unmatched" << std::endl;
    }
}

void HelloWorldPublisher::runThread(
        uint32_t samples,
        uint32_t sleep)
{
    if (samples == 0)
    {
        while (!stop)
        {
            if (publish(false))
            {
                std::cout << "Message: " << m_Hello.message() << "with data:" << m_Hello.data().data() << std::endl;
		std::cout << " with index: " << m_Hello.index() << " SENT" << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
        }
	
    }
    else
    {
        for (uint32_t i = 0; i < samples; ++i)
        {
            if (!publish())
            {
                --i;
            }
            else
            {

               std::cout << "Message: " << m_Hello.message() << "with data:" << m_Hello.data().data() << std::endl;
		std::cout << " with index: " << m_Hello.index() << " SENT" << std::endl;

            }
            std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
        }

    }

}

void HelloWorldPublisher::run(
        uint32_t samples,
        uint32_t sleep)
{
    stop = false;
    std::thread thread(&HelloWorldPublisher::runThread, this, samples, sleep);
    if (samples == 0)
    {
        std::cout << "samples == 0." << std::endl;

        stop = true;
    }
    else
    {
        std::cout << "Publisher running " << samples << " samples." << std::endl;
    }
    thread.join();
    
}


bool HelloWorldPublisher::publish(
        bool waitForListener)
{
    if (m_listener.firstConnected || !waitForListener || m_listener.n_matched > 0)
    {
        m_Hello.index(m_Hello.index() + 1);
	time(&t);
   	std::cout<<"pulisher t is "<< t <<std::endl;
        mp_publisher->write((void*)&m_Hello);
        return true;
    }
    return false;
}

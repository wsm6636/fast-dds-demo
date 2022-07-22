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
 * @file HelloWorldSubscriber.cpp
 *
 */

#include "SHMSubSubscriber.h"
#include <fastrtps/participant/Participant.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/Domain.h>
#include <fastdds/rtps/transport/shared_mem/SharedMemTransportDescriptor.h>
#include <fastdds/rtps/transport/UDPv4TransportDescriptor.h>

#include<sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;
using namespace eprosima::fastdds::rtps;
SHMSubSubscriber mysub;
int lastindex = 0;
int latency[61440];
int **flag;
SHMSubSubscriber::SHMSubSubscriber()
    : mp_participant(nullptr)
    , mp_subscriber(nullptr)
{
}

bool SHMSubSubscriber::init(int ** Flag)
{
    flag = Flag;
    ParticipantAttributes PParam;
    PParam.rtps.builtin.discovery_config.discoveryProtocol = DiscoveryProtocol_t::SIMPLE;
    PParam.rtps.builtin.discovery_config.use_SIMPLE_EndpointDiscoveryProtocol = true;
    PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationReaderANDSubscriptionWriter = true;
    PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationWriterANDSubscriptionReader = true;
    PParam.rtps.builtin.discovery_config.leaseDuration = c_TimeInfinite;
    PParam.rtps.setName("Participant_sub");

    // SharedMem transport configuration
    PParam.rtps.useBuiltinTransports = false;

    auto sm_transport = std::make_shared<SharedMemTransportDescriptor>();
    sm_transport->segment_size(2 * 1024 * 1024);
    PParam.rtps.userTransports.push_back(sm_transport);

    // UDP
    auto udp_transport = std::make_shared<UDPv4TransportDescriptor>();
    //udp_transport->interfaceWhiteList.push_back("127.0.0.1");
    PParam.rtps.userTransports.push_back(udp_transport);

    mp_participant = Domain::createParticipant(PParam);
    if (mp_participant == nullptr)
    {
        return false;
    }

    //REGISTER THE TYPE


    Domain::registerType(mp_participant, &m_type);
    //CREATE THE SUBSCRIBER
    SubscriberAttributes Rparam;
    Rparam.topic.topicKind = NO_KEY;
    Rparam.topic.topicDataType = "SHMDemo";
    Rparam.topic.topicName = "SHMDemoTopic";
    Rparam.topic.historyQos.kind = KEEP_LAST_HISTORY_QOS;
    Rparam.topic.historyQos.depth = 30;
    Rparam.topic.resourceLimitsQos.max_samples = 50;
    Rparam.topic.resourceLimitsQos.allocated_samples = 20;
    Rparam.qos.m_reliability.kind = RELIABLE_RELIABILITY_QOS;
    Rparam.qos.m_durability.kind = TRANSIENT_LOCAL_DURABILITY_QOS;

    mp_subscriber = Domain::createSubscriber(mp_participant, Rparam, (SubscriberListener*)&m_listener);

    if (mp_subscriber == nullptr)
    {
        return false;
    }


    return true;
}

SHMSubSubscriber::~SHMSubSubscriber()
{
    // TODO Auto-generated destructor stub
    Domain::removeParticipant(mp_participant);
}

void SHMSubSubscriber::SubListener::onSubscriptionMatched(
        Subscriber* /*sub*/,
        MatchingInfo& info)
{
    if (info.status == MATCHED_MATCHING)
    {
        n_matched++;
        std::cout << "Subscriber matched" << std::endl;
    }
    else
    {
        n_matched--;
        std::cout << "Subscriber unmatched" << std::endl;
	lastindex = m_sub->index();
	std::cout << "lastindex" << lastindex << std::endl;
	**flag = 1; 
    }
}

void SHMSubSubscriber::SubListener::onNewDataMessage(
        Subscriber* sub)
{
    timeval subtime;

    if (sub->takeNextData((void*)m_sub.get(), &m_info))
    {
        if (m_info.sampleKind == ALIVE)
        {
            this->n_samples++;
            gettimeofday(&subtime, 0);
	    latency[m_sub->index()] = subtime.tv_usec - m_sub->time() ;
            //std::cout << "index: " << m_sub->index() << " subtime: " << subtime.tv_usec << " latency: " << latency[m_sub->index()] <<  " RECEIVED" <<
            //        std::endl;
        }
    }
    
}

void SHMSubSubscriber::wfile(const char* filename)
{
    std::ofstream  outfile;
    outfile.open(filename,  std::ios::out); 
    long int sum = 0;
    double avg = 0;
    double max = 0;
    double min = 9999;
    long int err[100];
    long int errnu[100];
    int a=0;
    if (outfile.is_open())
	{
		outfile << "index " << "latency " <<"\r\n";
		for(int i=1;i<=lastindex ; i++){
     		outfile << i <<" ";
      		outfile << latency[i];
      		outfile << "\r\n";
		
			if(0 < latency[i]){
				sum += latency[i];		
			}else {
				err[a] = latency[i];
				errnu[a] = i;
				a++;
			}

			if (latency[i] > max) {
            			max = latency[i];
        			}
        		if ((0 < latency[i]) && (latency[i] < min)) {
            			min = latency[i];
        			}
		}
		avg = sum/lastindex;
		for(int b=0;b<a ; b++){
			//if(err[b]!=0)
				outfile	<< "err (" << errnu[b] << ")" << err[b] <<" ";
		}
		outfile << "\r\n";	
		outfile << "max=" << max <<" ";
		outfile << "min=" << min <<" ";
		outfile << "avg=" << avg <<"\r\n";
		outfile.close();
	}
    
    else std::cout << "could not load file " << std::endl;
		    
    
}

void SHMSubSubscriber::run()
{
    
    std::cout << "Subscriber running. Please press enter to stop the Subscriber" << std::endl;
    //std::cin.ignore();
    
}

void SHMSubSubscriber::run(
        uint32_t number)
{
    std::cout << "Subscriber running until " << number << "samples have been received" << std::endl;
    while (number > this->m_listener.n_samples)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

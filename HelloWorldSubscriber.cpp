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

#include "HelloWorldSubscriber.h"
#include <fastrtps/participant/Participant.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/Domain.h>

#include <iostream>
#include <fstream>
#include "decode.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

#include "HelloWorldPublisher.h"
#include <fastrtps/participant/Participant.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/Domain.h>

#include <time.h>
#include "HelloWorld.h"
using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;

const char* subfilename;
FILE *fp = NULL;
char buf[1024] = {0};
char result[10240] = {0};
time_t tt;
std::stringstream st;
int **pi;
std::string** ptimeresult; 
std::string** psubtime;

std::string subtt;
std::string subresult ;

HelloWorldSubscriber::HelloWorldSubscriber()
    : mp_participant(nullptr)
    , mp_subscriber(nullptr)
{
}
bool HelloWorldSubscriber::init()
{
 
    ParticipantAttributes PParam;
    PParam.rtps.builtin.discovery_config.discoveryProtocol = DiscoveryProtocol_t::SIMPLE;
    PParam.rtps.builtin.discovery_config.use_SIMPLE_EndpointDiscoveryProtocol = true;
    PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationReaderANDSubscriptionWriter = true;
    PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationWriterANDSubscriptionReader = true;
    PParam.rtps.builtin.discovery_config.leaseDuration = c_TimeInfinite;
    
    PParam.rtps.setName("Participant_sub");
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
    Rparam.topic.topicDataType = "HelloWorld";
    Rparam.topic.topicName = "HelloWorldTopicresult";
    Rparam.topic.historyQos.kind = KEEP_LAST_HISTORY_QOS;
    Rparam.topic.historyQos.depth = 30;
    Rparam.topic.resourceLimitsQos.max_samples = 50;
    Rparam.topic.resourceLimitsQos.allocated_samples = 20;
    Rparam.qos.m_reliability.kind = RELIABLE_RELIABILITY_QOS;
    Rparam.qos.m_durability.kind = TRANSIENT_LOCAL_DURABILITY_QOS;
    mp_subscriber = Domain::createSubscriber(mp_participant, Rparam, (SubscriberListener*)&m_listener);

    if (mp_subscriber == nullptr)
    {
	std::cout << "mp_subscriber false "<< std::endl;
        return false;
    }


    return true;
}


bool HelloWorldSubscriber::init(const char* filename, int ** pInt, std::string **ptime,std::string **psub)
{
    pi = pInt;
    subfilename = filename;
    ptimeresult = ptime;
    psubtime = psub;
    ParticipantAttributes PParam;
    PParam.rtps.builtin.discovery_config.discoveryProtocol = DiscoveryProtocol_t::SIMPLE;
    PParam.rtps.builtin.discovery_config.use_SIMPLE_EndpointDiscoveryProtocol = true;
    PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationReaderANDSubscriptionWriter = true;
    PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationWriterANDSubscriptionReader = true;
    PParam.rtps.builtin.discovery_config.leaseDuration = c_TimeInfinite;
    
    PParam.rtps.setName("Participant_sub");
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
    Rparam.topic.topicDataType = "HelloWorld";
    Rparam.topic.topicName = "HelloWorldTopiccode";
    Rparam.topic.historyQos.kind = KEEP_LAST_HISTORY_QOS;
    Rparam.topic.historyQos.depth = 30;
    Rparam.topic.resourceLimitsQos.max_samples = 50;
    Rparam.topic.resourceLimitsQos.allocated_samples = 20;
    Rparam.qos.m_reliability.kind = RELIABLE_RELIABILITY_QOS;
    Rparam.qos.m_durability.kind = TRANSIENT_LOCAL_DURABILITY_QOS;
    mp_subscriber = Domain::createSubscriber(mp_participant, Rparam, (SubscriberListener*)&m_listener);

    if (mp_subscriber == nullptr)
    {
	std::cout << "mp_subscriber false "<< std::endl;
        return false;
    }
    

    return true;
}

HelloWorldSubscriber::~HelloWorldSubscriber()
{
    // TODO Auto-generated destructor stub
    Domain::removeParticipant(mp_participant);
}

void HelloWorldSubscriber::SubListener::onSubscriptionMatched(
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
	
    }
}

void HelloWorldSubscriber::SubListener::onNewDataMessage(
        Subscriber* sub)
{
    std::ofstream  outfile;
    std::stringstream ss;

    std::string s;
    outfile.open(subfilename, std::ios::binary | std::ios::out); 

    if (sub->takeNextData((void*)&m_Hello, &m_info))
    {
        if (m_info.sampleKind == ALIVE)
        {
            this->n_samples++;
            // Print your structure data here.
           	if (outfile.is_open())
   		 {
				int size = m_Hello.index();
				ss << m_Hello.message();
				ss >> s;
				s = base64_decode(m_Hello.message());
				const char *p = s.c_str();				
				outfile.write(p, size);	
				std::cout << "received "<< std::endl;
  		 
		
   				outfile.close();
            	
		int stat = chmod(subfilename, S_IREAD | S_IWRITE | S_IEXEC);
		if (!stat)
     		 	std::cout << "chmod a+x "<< std::endl;
		time(&tt);
		st << tt;
		subtt = "subscriber tt is " + st.str();
		if( (fp = popen(subfilename, "r")) == NULL ) {
			std::cout << "popen error!" << std::endl;
   	 		}
			
		while (fgets(buf, sizeof(buf), fp)) {
        		strcat(result, buf);
    			}
			pclose(fp);
			subresult = "result is " + std::string(result);
			std::cout << "result:" <<  subresult << std::endl;
			if((!subresult.empty()) && (!subtt.empty())){
			**pi = 1;
                        **ptimeresult = subresult;
			**psubtime = subtt;						
			}
		}
		else
			std::cout << "outfile is null"<< std::endl;
	std::cout << "Message " << std::endl;
        std::cout << m_Hello.message() << std::endl;
        std::cout << " index " << m_Hello.index() << " RECEIVED" << std::endl;			
	
	}

    }

}

void HelloWorldSubscriber::run()
{
    std::cout << "Subscriber running. Please press enter to stop the Subscriber" << std::endl;
}

void HelloWorldSubscriber::runn()
{
    std::cout << "Subscriber running. Please press enter to stop the Subscriber" << std::endl;
    std::cin.ignore();
	
}
void HelloWorldSubscriber::run(
        uint32_t number)
{

    std::cout << "Subscriber running until " << number << "samples have been received" << std::endl;
    while (number > this->m_listener.n_samples)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}


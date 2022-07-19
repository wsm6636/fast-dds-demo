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
 * @file HelloWorld_main.cpp
 *
 */

#include "HelloWorldPublisher.h"
#include "HelloWorldSubscriber.h"

#include <fastrtps/Domain.h>
#include <fastrtps/log/Log.h>

using namespace eprosima;
using namespace fastrtps;
using namespace rtps;

static int i =0;
static std::string timeresult;
static std::string subtime;
int main(int argc, char** argv)
{
    std::cout << "Starting "<< std::endl;
    int type = 1;
    int count = 1;
    long sleep = 100;
    const char* pubfile;
    const char* subfile;
    if(argc > 1)
    {
        if(strcmp(argv[1],"publisher")==0)
        {
            type = 1;
            if (argc >= 3)
            {
                /*count = atoi(argv[2]);
                if (argc == 4)
                {
                    sleep = atoi(argv[3]);
                }*/
		pubfile = argv[2];
            }
        }
        else if(strcmp(argv[1],"subscriber")==0){
		type = 2;
		 if (argc >= 3)
            	{
			subfile = argv[2];
           	 }
	}
            
    }
    else
    {
        std::cout << "publisher OR subscriber argument needed" << std::endl;
        Log::Reset();
        return 0;
    }

    switch(type)
    {
        case 1:
            {
                HelloWorldPublisher mypub;
                if(mypub.init(pubfile))
                {
                    mypub.run(count, sleep);
                }
		HelloWorldSubscriber sub;
	       if(sub.init())
               {
		        sub.runn();
               }
                break;
            }
        case 2:
            {
		
                HelloWorldSubscriber mysub;          
	        int *pi = &i;
		std::string *ptime = &timeresult;
		std::string *psub = &subtime;

		 if(mysub.init(subfile,&pi,&ptime,&psub))
                {
		
		        mysub.run();
                }
		while(1)
                {
			std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
			std::cout << " sleep " << sleep << std::endl;
			if (i==1) {
				std::cout<<"found"<<i<<std::endl;
				
				break;
			}
		}
		HelloWorldPublisher mypub;
		std::string mess = timeresult + subtime;
                if(mypub.init(mess))
                {
                    mypub.run(1,100);
                }
                break;
            }
    }
    Domain::stopAll();
    Log::Reset();
    return 0;
}

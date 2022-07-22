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
 * @file SHMPub_main.cpp
 *
 */

#include "SHMPubPublisher.h"


#include <fastrtps/Domain.h>
#include <fastrtps/log/Log.h>

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
using namespace eprosima;
using namespace fastrtps;
using namespace rtps;

std::string rand_str(const int len)  
{

    std::string str;                
    char c;                     
    int i;                  
    for(i = 0 ; i < len ; i++)
    {
 
        c = 'a' + rand()%26;
        str.push_back(c);      
    }
    return str;                 
}

int main(
        int argc,
        char** argv)
{
    /*int fd = open("/sys/fs/cgroup/cpuset/isolated/cgroup.procs", O_WRONLY);
    if (fd < 0) {
        perror("Can't open cpuset file...\n");
        return 0;
    }
   
    write(fd, "0\n", 2);
    close(fd);*/

    std::cout << "Starting " << std::endl;
    int count = 60000;
    long sleep = 1;
    std::string str = rand_str(2000);
    if (argc > 1)
    {

        std::cout << "publisher, subscriber or both argument needed" << std::endl;
        Log::Reset();
        return 0;
    }
    SHMPubPublisher mypub;
    if (mypub.init())
    {
	for(int a=0 ; a<count ;a++){
        	mypub.publish(str);
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
	}

    }
           
        

    Domain::stopAll();
    Log::Reset();
    return 0;
}

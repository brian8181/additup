// File Name:  main.cpp
// Build Date: Sat Sep  7 12:20:36 AM CDT 2024
// Version:    0.0.1

#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>         /* for STDIN_FILENO */
#include <sys/select.h>     /* for pselect   */
#include <string>
#include <getopt.h>
#include "additup_ui.hpp"

int stdin_ready (int filedes)
{
        fd_set set;
        // declare/initialize zero timeout
#ifndef CYGWIN
        struct timespec timeout = { .tv_sec = 0 };
#else
        struct timeval timeout = { .tv_sec = 0 };
#endif
        // initialize the file descriptor set
        FD_ZERO(&set);
        FD_SET(filedes, &set);

        // check stdin_ready is ready on filedes
#ifndef CYGWIN
                return pselect(filedes + 1, &set, NULL, NULL, &timeout, NULL);
#else
                return select(filedes + 1, &set, NULL, NULL, &timeout);
#endif
}


int main(int argc, char* argv[])
{
	try
	{
		char* pipe_buff[sizeof(char*) * argc+1];
		if(stdin_ready(STDIN_FILENO))
		{
			std::string buffer;
			std::cin >> buffer;
			memcpy(pipe_buff, argv, sizeof(char*) * argc);
			pipe_buff[argc] = &buffer[0];
			++argc;
			return parse_options(argc, pipe_buff);
		}
		return parse_options(argc, argv);
	}
	catch(std::logic_error& ex)
	{
	 	std::cout << ex.what() << std::endl;
	}
}

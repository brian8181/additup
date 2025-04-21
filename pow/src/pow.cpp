//    File:       makefile
//    Date:       Sun Dec 15 05:46:02 PM CST 2024
//    Version:    0.0.1

#include <stdlib.h>
#include <unistd.h>         /* for STDIN_FILENO */
#include <sys/select.h>     /* for pselect   */
#include <getopt.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "bash_color.hpp"

using std::string;
using std::stringstream;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;

const string VERSION_STRING = "0.0.1";
const int DEFAULT_ARGC = 0;
const unsigned short VERBOSE          = 0x01;
const unsigned short DEFAULTS         = 0x00;
const unsigned short FIELDS           = 0x02;
unsigned short options = DEFAULTS;
char DELIMITER = ',';

static struct option long_options[] =
{
        {"verbose", no_argument, 0, 'v'},
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'r'},
};

unsigned short OPTION_FLAGS = DEFAULTS;

// Integer power: a^n
double int_pow(double base, int exp)
{
    double result = 1.0;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

// Nth root using binary search
double nth_root(double x, int n)
{
    double low = 0, high = x, mid;
    double eps = 1e-7;

    if (x < 1.0) high = 1.0;

    while ((high - low) > eps)
    {
        mid = (low + high) / 2.0;
        if (int_pow(mid, n) < x)
            low = mid;
        else
            high = mid;
    }
    return (low + high) / 2.0;
}

// a^(m/n)
double fractional_pow(double a, int m, int n)
{
    double powered = int_pow(a, m);      // a^m
    return nth_root(powered, n);         // (a^m)^(1/n)
}

// Taylor series for natural log ln(x), valid for 0.5 < x < 1.5
double ln(double x)
{
    if (x <= 0) return 0;  // ln undefined for <= 0
    double y = (x - 1) / (x + 1);
    double y2 = y * y;
    double result = 0.0;
    double term = y;
    int i;

    for (i = 1; i < 100; i += 2)
	{
        result += term / i;
        term *= y2;
    }

    return 2 * result;
}

// Taylor series for exp(x)
double exp_taylor(double x)
{
    double sum = 1.0;  // First term of series
    double term = 1.0;
    for (int i = 1; i < 50; i++)
	{
        term *= x / i;
        sum += term;
    }
    return sum;
}

// Real power a^b = exp(b * ln(a))
double real_pow(double a, double b)
{
    if (a <= 0) return 0; // ln(a) undefined
    double log_a = ln(a);
    double exp_result = exp_taylor(b * log_a);
    return exp_result;
}
void print_version()
{
	cout << VERSION_STRING << endl;
}

void print_help()
{
	cout	<< endl
			<< FMT_BOLD      << FMT_FG_GREEN << "Usage: " << FMT_RESET << endl
			<< FMT_BOLD      << /*~ "${APP_NAME}"         << ~*/ FMT_RESET << " "
			<< FMT_FG_BLUE   << "[-hvr][...]"             << FMT_RESET << " "
         												  <<  endl << endl;
}

int parse_options(int argc, char* argv[])
{
	int opt = 0;
	int option_index = 0;
	optind = 0;
	while ((opt = getopt_long(argc, argv, "hv ", long_options, &option_index)) != -1)
	{
		switch (opt)
		{
			case 'h':
				print_help();
			case 'v':
				print_version();
				return 0;
		}
	}

	if (argc < DEFAULT_ARGC) // not correct number of args
	{
		cerr << "Expected argument after options, -h for help" << endl;
		return -1;
	}

	string path = argv[0];   // get exe file path
	cout << argv[0] << endl;

    double x = 9.0;
    int m = 1;
    int n = 2;
    double result1 = fractional_pow(x, m, n);    // computes sqrt(9)
    printf("%f^(%d/%d) = %f\n", x, m, n, result1); // should print 3.000...


    double a = 5.0;
    double b = 1.414;  // approx sqrt(2)
    double result2 = real_pow(a, b);
    printf("%f^%f = %f\n", a, b, result2);

	return 0;
}

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
		if(stdin_ready(STDIN_FILENO))
		{
			std::string buffer;
			std::cin >> buffer;
			// add piped buffer to end of argv
			char* argvtmp[sizeof(char*) * argc+1];
			memcpy(argvtmp, argv, sizeof(char*) * argc);
			argvtmp[argc] = &buffer[0];
			argv = argvtmp;
			++argc;
		}
		return parse_options(argc, argv);
	}
	catch(std::logic_error& ex)
	{
	 	std::cout << ex.what() << std::endl;
	}
}
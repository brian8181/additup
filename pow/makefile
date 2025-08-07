# File:  ./makefile
# Date: Sat Apr 19 01:42:53 CDT 2025
# Version:    0.1.0

CXX=g++
CC=gcc
CXXFLAGS=-Wall -std=c++17 -DCYGWIN
CXXEXTRA=-fPIC
APP_NAME=pow
BLD=build
OBJ=build
SRC=src
DEBUG=1

ifdef DEBUG
	CXXFLAGS += -g -DDEBUG
endif

all: $(BLD)/pow $(BLD)/libpow.so $(BLD)/libpow.a

$(BLD):
	-echo testing ...
	#-if not exist $(BLD) mkdir "./$(BLD)"
	exit 1

$(BLD)/pow: $(OBJ)/pow.o #CCSK_PREREQUISTE#
	 $(CXX) $(CXXFLAGS) -o $(BLD)/pow $(OBJ)/pow.o #CCSK_PREREQUISTE#

$(BLD)/libpow.so: $(BLD)/pow.o
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) --shared $(BLD)/pow.o -o $(BLD)/libpow.so
	-chmod 755 $(BLD)/libpow.so

$(BLD)/libpow.a: $(BLD)/pow.o
	-ar rvs $(BLD)/libpow.a $(BLD)/pow.o
	-chmod 755 $(BLD)/libpow.a

$(OBJ)/pow.o: $(SRC)/pow.cpp
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) -c $(SRC)/pow.cpp -o $(OBJ)/pow.o

# $(OBJ)/pow1.o: $(SRC)/pow1.c
# 	$(CXX) $(CXXFLAGS) $(CXXEXTRA) -c $(SRC)/pow1.c -o $(OBJ)/pow1.o

# $(OBJ)/pow2.o: $(SRC)/pow2.c
# 	$(CXX) $(CXXFLAGS) $(CXXEXTRA) -c $(SRC)/pow2.c -o $(OBJ)/pow2.o


#CCSK_RULE#

.PHONY: all clean
clean:
	-rm -f $(OBJ)/*.
	-rm -f $(BLD)/*

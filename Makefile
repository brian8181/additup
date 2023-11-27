#// License:    None
#// File Name:  ./Makefile
#// Build Date: Tue Nov 14 04:08:48 PM CST 2023
#// Version:    0.0.1

CXX = g++
CXXFLAGS = -Wall -std=c++17 -DDEBUG -g
#CXXFLAGS = -Wall -std=c++17 -DDEBUG -DNO_SHOW -g
APPNAME = additup
BUILD = build
OBJ =  build
SRC = src

debug: all

all: additup

# all_no_show:
# 	CXXFLAGS+='-DNO_SHOW'

additup: additup.o main.o #@@PREREQUISTE@@
	 $(CXX) $(CXXFLAGS) $(BUILD)/additup.o $(BUILD)/main.o -o $(BUILD)/additup #@@CLASS_NAME@@

additup.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/additup.cpp -o $(BUILD)/additup.o
	
main.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/main.cpp -o $(BUILD)/main.o

#AUTO_INSERT_POINT_DO_NOT_REMOVE#

clean:
	-rm -f $(OBJ)/*.
	-rm -f $(BUILD)/*
	
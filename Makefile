#// License:    None
#// File Name:  ./Makefile
#// Build Date: Tue Nov 14 04:08:48 PM CST 2023
#// Version:    0.0.1

CXX = g++
CXXFLAGS = -Wall -std=c++17 -DDEBUG -g
#CXXFLAGS = -Wall -std=c++17 -DDEBUG -DNO_SHOW -g
BUILD = build
OBJ =  build
SRC = src

all: additup_ui

# all_no_show:
# 	CXXFLAGS+='-DNO_SHOW'

additup_ui: additup_ui.o additup.o main.o fixed_width.o #@@PREREQUISTE@@
	 $(CXX) $(CXXFLAGS) $(BUILD)/additup_ui.o $(BUILD)/additup.o $(BUILD)/main.o $(BUILD)/fixed_width.o -o $(BUILD)/additup_ui #@@CLASS_NAME@@

additup_ui.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/additup_ui.cpp -o $(BUILD)/additup_ui.o

additup.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/additup.cpp -o $(BUILD)/additup.o

fixed_width.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/fixed_width.cpp -o $(BUILD)/fixed_width.o
	
main.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/main.cpp -o $(BUILD)/main.o

#AUTO_INSERT_POINT_DO_NOT_REMOVE#

clean:
	-rm -f $(BUILD)/*
	
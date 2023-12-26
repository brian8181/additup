# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

# License:    None
# File Name:  ./Makefile
# Build Date: Tue Nov 14 04:08:48 PM CST 2023
# Version:    0.0.1

CXX = g++
CXXFLAGS = -Wall -std=c++20 -DDEBUG -g
#CXXFLAGS = -Wall -std=c++17 -DDEBUG -DNO_SHOW -g
BUILD = build
OBJ =  build
SRC = src
LDFLAGS = -static -llibfmt -L/usr/local/lib64/fmt
INCLUDES = -I/usr/local/include/fmt/

all: additup_ui

additup_ui: additup_ui.o additup.o main.o fixed_width.o #@@PREREQUISTE@@
	 $(CXX) $(CXXFLAGS) $(BUILD)/additup_ui.o $(BUILD)/additup.o $(BUILD)/main.o $(BUILD)/fixed_width.o /usr/local/lib64/libfmt.a -o $(BUILD)/additup_ui #@@CLASS_NAME@@

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
	
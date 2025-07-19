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
#CXXFLAGS = -Wall -std=c++20 -DDEBUG -g
CXXFLAGS=-Wall -std=c++17 -DDEBUG -DCYGWIN -g
#CXXFLAGS = -Wall -std=c++17 -DDEBUG -DNO_SHOW -g
BLD= build
OBJ= build
SRC= src
#LDFLAGS = -static -llibfmt -L/usr/local/lib64/fmt
LDFLAGS = -static -llibfmt -L/usr/local/lib/fmt
INCLUDES = -I/usr/local/include/fmt/

all: $(BLD)/test $(BLD)/additup_ui

$(BLD)/additup_ui: $(BLD)/additup_ui.o $(BLD)/additup.o $(BLD)/main.o $(BLD)/fixed_width.o $(BLD)/complex.o
	 $(CXX) $(CXXFLAGS) $(BLD)/additup_ui.o $(BLD)/additup.o $(BLD)/main.o $(BLD)/fixed_width.o $(BLD)/complex.o $(LDFLAGS) -o $(BLD)/additup_ui

$(BLD)/additup_ui.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/additup_ui.cpp -o $(BLD)/additup_ui.o

$(BLD)/additup.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/additup.cpp -o $(BLD)/additup.o

$(BLD)/fixed_width.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/fixed_width.cpp -o $(BLD)/fixed_width.o

$(BLD)/main.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/main.cpp -o $(BLD)/main.o

$(BLD)/complex.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/complex.cpp -o $(BLD)/complex.o

$(BLD)/units.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/units.cpp -o $(BLD)/units.o

$(BLD)/test: $(SRC)/test.cpp $(BLD)/additup.o
	$(CXX) $(CXXFLAGS) $(SRC)/test.cpp $(BLD)/additup.o -o $(BLD)/test

clean:
	-rm -f $(BLD)/*

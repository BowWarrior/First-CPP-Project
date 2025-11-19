CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

#can change this just to 'program' if on linux
TARGET = program.exe

#name of the c++ file:
SRC = firstCPP.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)


#	'rm -f $(TARGET)' for linux
clean:
	del $(TARGET)

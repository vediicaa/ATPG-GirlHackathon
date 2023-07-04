# Makefile

# Specify the compiler
CXX = g++

# Specify compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Specify the target executable name
TARGET = script

# Default target
all: $(TARGET)

# Compile the C++ file and create the executable
$(TARGET): $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

# Clean up the generated files
clean:
	rm -f $(TARGET)

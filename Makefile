# Compiler and flags
CC = gcc
CXX = g++
CFLAGS = -Wall -Iinclude -std=gnu17
CXXFLAGS = -Wall -Iinclude -std=c++17
LDFLAGS = -framework OpenGL -framework IOKit -framework Cocoa
LIBS = -L./libs/Mac -lGLEW -lglfw3

# Directories
SRC_DIRS = src fjs fss ftml
INCLUDE_DIR = include
BIN_DIR = bin

# Find all source files
C_SOURCES = $(shell find $(SRC_DIRS) -name '*.c')
CXX_SOURCES = $(shell find $(SRC_DIRS) -name '*.cc')

# Object files
C_OBJS = $(C_SOURCES:.c=.o)
CXX_OBJS = $(CXX_SOURCES:.cc=.o)
OBJS = $(C_OBJS) $(CXX_OBJS)

# Target executable
TARGET = $(BIN_DIR)/FrontyBrowser

# Default rule
all: $(TARGET)

# Link rule
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compile C sources
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Compile C++ sources
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean rule
clean:
	rm -f $(OBJS)
	rm -f $(TARGET)

# Clean build rule
clean_build: clean all

# Run rule
run: $(TARGET)
	rm ./src/main.o
	./$(TARGET)

.PHONY: all clean clean_build run

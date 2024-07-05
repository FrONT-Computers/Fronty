# Compiler and flags
CC = gcc
CXX = g++
OBJCXX = g++  # Objective-C++ compiler
CFLAGS = -Wall -Iinclude -std=gnu17
CXXFLAGS = -Wall -Iinclude -std=c++17
OBJCXXFLAGS = -Wall -Iinclude -std=c++17 -fobjc-arc  # Objective-C++ flags
LDFLAGS = -framework OpenGL -framework IOKit -framework Cocoa
LIBS = -L./libs/Mac -lGLEW -lglfw3

# Directories
SRC_DIRS = src fjs fss ftml
INCLUDE_DIR = include
BIN_DIR = bin

# Find all source files
C_SOURCES = $(shell find $(SRC_DIRS) -name '*.c')
CXX_SOURCES = $(shell find $(SRC_DIRS) -name '*.cc')
OBJCXX_SOURCES = $(shell find $(SRC_DIRS) -name '*.mm')

# Object files
C_OBJS = $(C_SOURCES:.c=.o)
CXX_OBJS = $(CXX_SOURCES:.cc=.o)
OBJCXX_OBJS = $(OBJCXX_SOURCES:.mm=.o)
OBJS = $(C_OBJS) $(CXX_OBJS) $(OBJCXX_OBJS)

# Target executable
TARGET = $(BIN_DIR)/FrontyBrowser

# Default rule
all: $(TARGET) clean_objs

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

# Compile Objective-C++ sources
%.o: %.mm
	$(OBJCXX) $(OBJCXXFLAGS) -c -o $@ $<

# Rule to clean object files after linking
clean_objs:
	rm -f $(OBJS)

# Clean rule
clean:
	rm -f $(OBJS)
	rm -f $(TARGET)

# Clean build rule
clean_build: clean all

# Run rule
run: $(TARGET)
	rm -f $(OBJS)
	./$(TARGET)

.PHONY: all clean clean_build run clean_objs

# Compiler to use
CC = g++
# Compiler flags
CFLAGS = -std=c++14
INCLUDE = -Iinclude

BUILD_DIR := build
LIB_DIR := lib
TARGET_DIR := bin

# Name of your main cpp file
MAIN = main.cpp
# Name of the executable
EXECUTABLE = $(TARGET_DIR)/GPUComp_H1
# Name of the library
OBJECTS = $(BUILD_DIR)/MatrixLib.o

all: $(EXECUTABLE)

debug: CFLAGS += -DDEBUG
debug: all

$(EXECUTABLE): src/${MAIN} $(OBJECTS)
	$(CC) $^ -o $@ $(INCLUDE) $(CFLAGS)

$(OBJECTS): $(LIB_DIR)/MatrixLib.cpp
	$(CC) -c -o $@ $(INCLUDE) $^ $(CFLAGS)

$(LIB_DIR)/MatrixLib.cpp: include/MatrixLib.h

clean:
	rm -f $(TARGET_DIR)/*
	rm -f $(BUILD_DIR)/*
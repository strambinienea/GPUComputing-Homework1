# Compiler to use
CC = g++
# Compiler flags
CFLAGS = -std=c++14 -g
INCLUDE = -Iinclude

BUILD_DIR := build
LIB_DIR := lib
TARGET_DIR := bin

# Name of your main cpp file
MAIN = Main.cpp
# Name of the executable
EXECUTABLE = $(TARGET_DIR)/GPUComp_H1
# Name of the library
OBJECTS = $(BUILD_DIR)/MatrixLib.o

all: $(EXECUTABLE)

debug: CFLAGS += -DDEBUG
debug: all

$(EXECUTABLE): src/${MAIN} $(OBJECTS)
	@mkdir -p $(@D)
	$(CC) $^ -o $@ $(INCLUDE) $(CFLAGS)

$(OBJECTS): $(LIB_DIR)/MatrixLib.cpp
	@mkdir -p $(@D)
	$(CC) -c -o $@ $(INCLUDE) $^ $(CFLAGS)

$(LIB_DIR)/MatrixLib.cpp: include/MatrixLib.h

clean:
	rm -rf $(TARGET_DIR)/*
	rm -rf $(BUILD_DIR)/*

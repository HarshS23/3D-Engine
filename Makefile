# # format 
# # Target: dependencies 
# #	action	
# #


# CC = gcc 
# CFLAGS = -Wall -Wextra -std=c99 -O2 
# SDL2DIR = -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib -lSDL2

# # source and output 
# SRC = src/main.c src/file_finder.c 
# OUT = bin/file_finder

# BUILD = ./$(OUT)

# all: $(OUT)

# build:
# 	$(BUILD)

# $(OUT): $(SRC)
# 	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(SDL2DIR)


# clean: 
# 	rm -f $(OUT)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I/opt/homebrew/include/SDL2
LDFLAGS = -L/opt/homebrew/lib -lSDL2

# Source files
SRC = src/main.c src/file_finder.c src/vector.c src/mesh.c src/display.c src/camera.c src/triangle.c

# Output binary
TARGET = ./bin/main

# Default target (runs when you type `make`)
all: build

# Build rule
build:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET)
	./$(TARGET)

run: build
	./$(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)


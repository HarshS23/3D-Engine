# # # format 
# # # Target: dependencies 
# # #	action	


# Compiler and flags
CC = gcc
CFLAGS = -w -Wall -Wextra -I/opt/homebrew/include/SDL2
LDFLAGS = -L/opt/homebrew/lib -lSDL2

# Source files
SRC = src/main.c src/file_finder.c src/vector.c src/mesh.c src/display.c src/camera.c src/triangle.c src/clipping.c src/light.c src/culling.c

# Output binary
TARGET = ./bin/main

# Default target (runs when you type `make`)
all: build

# Build rule (compile only)
build:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET)

# Run rule (compile if needed, then run)
run: build
	./$(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)


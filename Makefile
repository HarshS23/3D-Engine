# # # # format 
# # # # Target: dependencies 
# # # #	action	


# # Compiler and flags
# CC = gcc
# CFLAGS = -w -Wall -Wextra -I/opt/homebrew/include/SDL2
# LDFLAGS = -L/opt/homebrew/lib -lSDL2

# # Source files
# SRC = src/main.c src/file_finder.c src/vector.c src/mesh.c src/display.c src/camera.c src/triangle.c src/clipping.c src/light.c src/culling.c

# # Output binary
# TARGET = ./bin/main

# # Default target (runs when you type `make`)
# all: build

# # Build rule (compile only)
# build:
# 	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET)

# # Run rule (compile if needed, then run)
# run: build
# 	./$(TARGET)

# # Clean rule
# clean:
# 	rm -f $(TARGET)


# Detect Operating System
ifeq ($(OS),Windows_NT)
    # --- WINDOWS SETTINGS ---
    
    # ADJUST THESE PATHS to match where you extracted SDL2 (MinGW version)
    SDL_PATH = C:/SDL2
    
    CC = gcc
    # Include path for SDL2 headers
    CFLAGS = -w -Wall -Wextra -I$(SDL_PATH)/include -I$(SDL_PATH)/include/SDL2
    # Linker flags: Library path + required Windows libs (mingw32, SDL2main)
    LDFLAGS = -L$(SDL_PATH)/lib -lmingw32 -lSDL2main -lSDL2
    
    # Output binary (must end in .exe)
    TARGET = bin/main.exe
    
    # Clean command for Windows (Command Prompt)
    # If using PowerShell or Git Bash, you might prefer 'rm -f'
    CLEAN_CMD = del /Q /F
    
    # Fix for path separators in target if needed for 'del'
    TARGET_CLEAN = bin\main.exe
else
    # --- MACOS / LINUX SETTINGS ---
    
    CC = gcc
    CFLAGS = -w -Wall -Wextra -I/opt/homebrew/include/SDL2
    LDFLAGS = -L/opt/homebrew/lib -lSDL2
    
    # Output binary
    TARGET = ./bin/main
    
    CLEAN_CMD = rm -f
    TARGET_CLEAN = $(TARGET)
endif

# Source files
SRC = src/main.c src/file_finder.c src/vector.c src/mesh.c src/display.c src/camera.c src/triangle.c src/clipping.c src/light.c src/culling.c

# Default target
all: build

# Build rule
build:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET)

# Run rule
run: build
	./$(TARGET)

# Clean rule
clean:
	$(CLEAN_CMD) $(TARGET_CLEAN)
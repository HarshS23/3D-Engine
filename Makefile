# format 
# Target: dependencies 
#	action	
#


CC = gcc 
CFLAGS = -Wall -Wextra -std=c99 -O2 
SDL2DIR = -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib -lSDL2

# source and output 
SRC = src/main.c src/file_finder.c 
OUT = bin/file_finder

BUILD = ./$(OUT)

all: $(OUT)

build:
	$(BUILD)

$(OUT): $(SRC)
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(SDL2DIR)


clean: 
	rm -f $(OUT)
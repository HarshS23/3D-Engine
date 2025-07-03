# format 
# Target: dependencies 
#	action	
#


CC = gcc 
CLFAGS = -Wall -Werror -Wextra -std=c99 -O2 
SDL2DIR = -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib -lSDL2
SRC = src/main.c
OUT = bin/engine

all: 
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(SDL2DIR)

clean: 
	rm -f $(OUT)
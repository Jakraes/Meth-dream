CC = gcc
SRC = ./src/*.c
INC = ./inc
LIB = ./lib/
FLAGS = -lBearLibTerminal -s -O3 -std=c99
OUT = ./build/

ifeq ($(OS),Windows_NT)
	LIB := $(LIB)win32
	OUT := $(OUT)win32/app.exe 
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		LIB := $(LIB)linux
		OUT := $(OUT)linux/app 
	endif
endif

all:
	$(CC) $(SRC) -I$(INC) -L$(LIB) $(FLAGS) -o $(OUT)

run: all
ifeq ($(OS),Windows_NT)
	./build/win32/app.exe
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		./build/linux/app
	endif
endif
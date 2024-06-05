CC = gcc
SRC = ./src/*.c
INC = $(abspath ./inc/)
LIB = $(abspath ./lib/)
FLAGS = -std=c99
OUTDIR = $(abspath ./build/)

ifeq ($(OS),Windows_NT)
	LIB := $(LIB)/win32
	OUTDIR := $(OUTDIR)/win32/
	OUT := $(OUTDIR)app.exe
	FLAGS += -lBearLibTerminal
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		LIB := $(LIB)/linux/
		OUTDIR := $(OUTDIR)/linux/
		OUT := $(OUTDIR)app
		FLAGS += -lBearLibTerminal -Wl,-rpath=$(LIB)
	endif
endif

all: config
	$(CC) $(SRC) -I$(INC) -L$(LIB) $(FLAGS) -o $(OUT)

config:
	mkdir -p $(OUTDIR)
	cp -r ./res $(OUTDIR)/res

run: all
ifeq ($(OS),Windows_NT)
	./build/win32/app.exe
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		./build/linux/app
	endif
endif

clean:
	rm -rf ./build
HDRFLDR=headers
CC=g++
LIBS=
CFLAGS=-I$(HDRFLDR) --std=c++17 -O3 -Wall -Wextra -pedantic

CLASSES=main.cpp Image.cpp lodepng.c Bucket.cpp

all: main.cpp
	$(CC) $(CLASSES) -o rearrange $(LIBS) $(CFLAGS)




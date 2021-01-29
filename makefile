HDRFLDR=headers
CC=g++
LIBS=
CFLAGS=-I$(HDRFLDR) --std=c++17 -g

CLASSES=main.cpp Image.cpp lodepng.c Bucket.cpp Point.cpp

all: main.cpp
	$(CC) $(CLASSES) -o out $(LIBS) $(CFLAGS)




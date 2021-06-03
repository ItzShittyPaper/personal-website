#CC=gcc

#CFLAGS=-Wint-conversion

karatemp3-cpp: main.cpp
	g++ -o karate-bin main.cpp -L/usr/lib -lSDL2 -lSDL2_mixer -lncurses

karatemp3-core: main.c
	$(CC) -o karate $(CFLAGS) main.c -L/usr/lib -lSDL2 -lSDL2_mixer



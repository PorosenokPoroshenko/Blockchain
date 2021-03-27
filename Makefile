CC = g++
CFLAGS = -Wall -g

compile: 
	$(CC) $(CFLAGS)  main.cpp Blockchain.cpp Block.cpp ./headers/SHA256/bin/obj/SHA256.o -o blockchain.out

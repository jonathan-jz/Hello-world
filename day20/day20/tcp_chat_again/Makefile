SRCS:=$(wildcard *.c)
ELFS:=$(SRCS:%.c=%)
CC:=gcc
all:$(ELFS)
CFLAGS:=-g -Wall -pthread

%:%.c
	$(CC) $(CFLAGS) $< -o $@ 
clean:
	rm -rf $(ELFS)


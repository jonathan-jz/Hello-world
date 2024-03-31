SRCS:=$(wildcard *.c)
EXES:=$(SRCS:%.c=%)
all:$(EXES)
%:%.c
	gcc $^ -o $@ -g
clean:
	rm -f $(EXES)

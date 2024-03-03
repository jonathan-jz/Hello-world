SRCS:=$(wildcard *.c)
EXES:=$(SRCS:%.c=%)
all:$(EXES)
%:%.c
	gcc $^ -o $@

CC=gcc
CFLAGS=-O -c -g
OBJS=main.o func.o
math:$(OBJS)
	$(CC) $(OBJS) -o $@
%.o:%.c
	$(CC) $(CFLAGS) $^ -o $@
.PHONY:clean
clean:
	rm *.o math
	echo rm success.
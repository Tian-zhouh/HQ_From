CC=gcc
OBJS=main.o func.o 
CFLAGS=-g -c -O -Wall
main:$(OBJS)
	$(CC) $(OBJS) -o $@
%.o:%.c 
	$(CC) $(CFLAGS) $^ -o $@
.PHONY:clean
clean:
	rm *.o main
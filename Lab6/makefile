CFLAGS = -Wall -c
LFLAGS = -Wall
CC = gcc
OBJS = datamgr.o
EXE = datamgr

all: $(OBJS)
	$(CC) -g $(LFLAGS) $(OBJS) list.o -lcheck `pkg-config --cflags --libs check` -o $(EXE)
	./$(EXE)

	datamgr.o: datamgr.h datamgr.c
		$(CC) $(CFLAGS) datamgr.c

	list.o: list.h list.c
		$(CC) $(CFLAGS) list.c

clean:
	rm -f *~ *.o $(EXE)

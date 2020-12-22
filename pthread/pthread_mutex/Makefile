CC=gcc
SOURCES=pthread_mutex.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABL=pthread_mutex
process: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABL) -lpthread
process.o: $(SOURCES)
	$(CC) -c $(SOURCES)

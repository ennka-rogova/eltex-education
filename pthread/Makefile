CC=gcc
SOURCES=pthread.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABL=pthread
process: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABL) -lpthread
process.o: $(SOURCES)
	$(CC) -c $(SOURCES)

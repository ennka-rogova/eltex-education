CC=gcc
SOURCES=simple_process.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABL=simple_process
process: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABL)
process.o: $(SOURCES)
	$(CC) -c $(SOURCES)

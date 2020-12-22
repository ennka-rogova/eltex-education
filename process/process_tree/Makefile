CC=gcc
SOURCES=process_tree.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABL=process_tree
process: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABL)
process.o: $(SOURCES)
	$(CC) -c $(SOURCES)

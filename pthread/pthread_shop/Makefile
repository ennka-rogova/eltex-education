CC=gcc
SOURCES=pthread_shop.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABL=pthread_shop
process: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABL) -lpthread
process.o: $(SOURCES)
	$(CC) -c $(SOURCES)

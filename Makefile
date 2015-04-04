CC        = gcc
SRC_DIR		= ./src
SOURCES		= main.c func.c stack.c debug.c
OBJECTS		= main.o func.o stack.o debug.o
TARGET		= maze
DEL_FILE	= rm -f

maze: $(OBJECTS)
	$(CC) -o maze $(OBJECTS)

main.o: $(SRC_DIR)/head.h
	$(CC) -c $(SRC_DIR)/main.c

func.o: $(SRC_DIR)/head.h
	$(CC) -c $(SRC_DIR)/func.c
	
stack.o: $(SRC_DIR)/head.h
	$(CC) -c $(SRC_DIR)/stack.c

debug.o: $(SRC_DIR)/head.h
	$(CC) -c $(SRC_DIR)/debug.c
	
clean: 
	-$(DEL_FILE) $(OBJECTS) $(TARGET)

CC = gcc
CFLAGS = -Wall

BIN_DIR = /home/mgiannopa/quiz-3/bins

all: main child

main: main.c | $(BIN_DIR)
	$(CC) $(CFLAGS) main.c -o $(BIN_DIR)/main

child: child.c | $(BIN_DIR)
	$(CC) $(CFLAGS) child.c -o $(BIN_DIR)/child

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -f $(BIN_DIR)/main $(BIN_DIR)/child

install: all
	mkdir -p $(BIN_DIR)
	cp main child $(BIN_DIR)

.PHONY: all clean install

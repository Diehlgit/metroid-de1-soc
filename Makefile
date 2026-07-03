CC = gcc
CFLAGS = -Wall
TARGET = projeto.c
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -E $(SRC) -o $(TARGET) $(CFLAGS)

clean:
	rm -f $(TARGET)
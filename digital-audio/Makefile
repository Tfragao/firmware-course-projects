CC = gcc
CFLAGS = -Wall -Wextra -Iinc
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)
TARGET = build/audio

all: build $(TARGET)

build:
	mkdir -p build

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build
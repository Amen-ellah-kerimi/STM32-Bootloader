CC = gcc
CFLAGS = -Wall -g -Iinc
TARGET = bootloader_sim

SRCS = src/main.c src/bootloader.c src/crc32.c src/flash.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

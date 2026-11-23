# Compiler
CC = gcc

# Compiler flags:
# Wall -Wextra : enable useful warnings
# -g : include debugging information for GDB
CFLAGS = -Wall -Wextra -g

# Name of our executable
TARGET = endianness

# Name of our C source file
SRC = endianness.c

# Default target: compile the program
all: $(TARGET)

#Build the executable from the source file
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) output.bin

#These targets are commands, not actual files
.PHONY: all clean

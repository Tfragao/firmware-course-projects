# Compiler and flags
CC = gcc
CFLAGS = -I./inc -Wall -Wextra -g

# Directories
SRCDIR = src
BUILDDIR = build

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.c)

# Object files (placed in build)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))

# Target executable
TARGET = $(BUILDDIR)/firmware_program

# Default rule
all: $(BUILDDIR) $(TARGET)

# Create build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile source files to object files in build directory
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean

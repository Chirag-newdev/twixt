# ===========================
#  Basic GCC Makefile (Windows + PowerShell)
#  Supports: build, run, debug, clean
# ===========================
# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Wpedantic -g -O0
TARGET  = a.exe

# Source and object files (auto-detects all .c files)
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# Default target — same as 'make run'
all: run

# Build rule
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

# Compile each .c into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program in maximized Command Prompt
run: $(TARGET)
	cmd /c start "" /max cmd /k "$(CURDIR)\$(TARGET)"

# Launch GDB in TUI mode for debugging
debug: $(TARGET)
	cmd /c start "" /max cmd /k "gdb -tui $(TARGET)"

# Clean up build artifacts
clean:
	del /q $(OBJ) $(TARGET) 2>nul || exit 0

# Phony targets
.PHONY: all run debug clean

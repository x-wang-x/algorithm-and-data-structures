# =========================
# Compiler & target
# =========================
CC      := gcc
TARGET  := main

# =========================
# Directories
# =========================
SRC_DIR   := src
INC_DIR   := include
BUILD_DIR := build

# =========================
# Files
# =========================
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# =========================
# Flags
# =========================
CFLAGS  := -Wall -Wextra -std=c11 -I$(INC_DIR)
LDFLAGS :=

# =========================
# Default target
# =========================
all: $(TARGET).exe

# =========================
# Link step
# =========================
$(TARGET).exe: $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

# =========================
# Compile step
# =========================
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# =========================
# Utility targets
# =========================
clean:
	@if exist $(BUILD_DIR) del /Q $(BUILD_DIR)\*.o
	@if exist $(TARGET).exe del /Q $(TARGET).exe

rebuild: clean all

.PHONY: all clean rebuild

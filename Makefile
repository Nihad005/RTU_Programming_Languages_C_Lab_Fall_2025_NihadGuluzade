
# Simple Makefile for Lab 1
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2
LDFLAGS = 
BUILD_DIR = bin
SRC_DIR = src

PROGRAMS = $(BUILD_DIR)/lab2_1 $(BUILD_DIR)/lab2_2 $(BUILD_DIR)/lab2_3

all: $(PROGRAMS)

$(BUILD_DIR)/lab2_1: $(SRC_DIR)/lab2_1.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BUILD_DIR)/lab2_2: $(SRC_DIR)/lab2_2.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BUILD_DIR)/lab2_3: $(SRC_DIR)/lab2_3.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

lab2_1: $(BUILD_DIR)/lab2_1
lab2_2: $(BUILD_DIR)/lab2_2
lab2_3: $(BUILD_DIR)/lab2_3

run-lab2_1: lab2_1
	./$(BUILD_DIR)/lab2_1

run-lab2_2: lab2_2
	./$(BUILD_DIR)/lab2_2

run-lab2_3: lab2_3
	./$(BUILD_DIR)/lab2_3

clean:
	rm -rf $(BUILD_DIR)/*.o $(PROGRAMS)

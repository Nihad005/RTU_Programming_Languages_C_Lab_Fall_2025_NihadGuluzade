
# Simple Makefile for Lab 1
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2
LDFLAGS = 
BUILD_DIR = bin
SRC_DIR = src
lab_DIR = Lab4

PROGRAMS = $(BUILD_DIR)/Lab4_1 $(BUILD_DIR)/Lab4_2 $(BUILD_DIR)/Lab4_3

all: $(PROGRAMS)

$(BUILD_DIR)/Lab4_1: $(lab_DIR)/Lab4_1.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BUILD_DIR)/Lab4_2: $(lab_DIR)/lab4_2.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BUILD_DIR)/Lab4_3: $lab_DIR)/Lab4_3.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

Lab4_1: $(BUILD_DIR)/Lab4_1
Lab4_2: $(BUILD_DIR)/Lab4_2
Lab4_3: $(BUILD_DIR)/Lab4_3

run-Lab4_1: Lab4_1
	./$(BUILD_DIR)/lab4_1

run-Lab4_2: Lab4_2
	./$(BUILD_DIR)/lab4_2

run-Lab4_3: Lab4_3
	./$(BUILD_DIR)/Lab4_3

clean:
	rm -rf $(BUILD_DIR)/*.o $(PROGRAMS)

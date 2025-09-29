
# Simple Makefile for Lab 1
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2
LDFLAGS = 
BUILD_DIR = bin
SRC_DIR = src
lab_DIR = Lab3

PROGRAMS = $(BUILD_DIR)/lab3_1 $(BUILD_DIR)/lab3_2 $(BUILD_DIR)/lab3_3

all: $(PROGRAMS)

$(BUILD_DIR)/lab3_1: $(lab_DIR)/lab3_1.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BUILD_DIR)/lab3_2: $(lab_DIR)/lab3_2.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BUILD_DIR)/lab3_3: $lab_DIR)/lab3_3.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

lab3_1: $(BUILD_DIR)/lab3_1
lab3_2: $(BUILD_DIR)/lab3_2
lab3_3: $(BUILD_DIR)/lab3_3

run-lab3_1: lab3_1
	./$(BUILD_DIR)/lab3_1

run-lab3_2: lab3_2
	./$(BUILD_DIR)/lab3_2

run-lab3_3: lab3_3
	./$(BUILD_DIR)/lab3_3

clean:
	rm -rf $(BUILD_DIR)/*.o $(PROGRAMS)

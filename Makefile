

CC = gcc # NEVER CHANGE THIS
CFLAGS = -Wextra -Wall -pedantic -std=c17
CPPFLAGS = -I$(SRC_DIR)
LDFLAGS = 
OPENGL_LDFLAGS = -lglut -lGLU -lGL 

BUILD_DIR = build

SRC_DIR = src
MAIN_C = $(SRC_DIR)/main.c
MAIN_O = $(BUILD_DIR)/main.o

TARGET = $(BUILD_DIR)/main

STATIC_LIB = $(BUILD_DIR)/libphysics.a

C_SOURCES := $(shell find "$(SRC_DIR)" -type "f" -name "*.c")
LIB_SOURCES_C := $(filter-out $(EXECUTABLE),$(C_SOURCES))
LIB_SOURCES_C_BASENAME := $(shell basename -a $(LIB_SOURCES_C))
LIB_OBJECTS := $(patsub %.c,$(BUILD_DIR)/%.o,$(LIB_SOURCES_C_BASENAME))

.PHONY: prod debug clean

prod: $(CFLAGS) += -O3
prod: $(TARGET)

debug: $(CFLAGS) += -O0 -g
debug: $(TARGET)

$(TARGET): $(STATIC_LIB) $(MAIN_O) | $(BUILD_DIR)
	$(CC) $^ -o $@ $(LDFLAGS) $(OPENGL_LDFLAGS)

$(STATIC_LIB): $(LIB_OBJECTS) | $(BUILD_DIR)
	ar rcs $^ $@

$(LIB_OBJECTS): | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $(LIB_SOURCES_C) -o $@

$(MAIN_O): | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPP_FLAGS) $(OPENGL_LDFLAGS) -c $(MAIN_C) -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

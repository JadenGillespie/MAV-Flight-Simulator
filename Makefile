
SRC_DIR = src
GRAPHICS_SRC_DIR = $(SRC_DIR)/graphics
PHYSICS_SRC_DIR = $(SRC_DIR)/physics

CC = gcc # NEVER CHANGE THIS
CFLAGS = -Wextra -Wall -pedantic -std=c17
CPPFLAGS = -I$(SRC_DIR) -I$(GRAPHICS_SRC_DIR) -I$(PHYSICS_SRC_DIR)
LDFLAGS = $(STATIC_LIB)
OPENGL_LDFLAGS = -lglut -lGLU -lGL 

BUILD_DIR = build

MAIN_C = $(SRC_DIR)/main.c
MAIN_O = $(BUILD_DIR)/main.o

TARGET = $(BUILD_DIR)/main

STATIC_LIB = $(BUILD_DIR)/libphysics.a

C_SOURCES := $(shell find "$(SRC_DIR)" -type "f" -name "*.c")
LIB_SOURCES_C := $(filter-out $(MAIN_C),$(C_SOURCES))
LIB_SOURCES_C_BASENAME := $(shell basename -a $(LIB_SOURCES_C))
LIB_OBJECTS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(LIB_SOURCES_C_BASENAME))
$(info $(LIB_SOURCES_C))
$(info $(LIB_SOURCES_C_BASENAME))
$(info $(LIB_OBJECTS))
.PHONY: prod debug clean

prod: $(CFLAGS) += -O3
prod: $(TARGET)

debug: $(CFLAGS) += -O0 -g
debug: $(TARGET)

$(TARGET): $(STATIC_LIB) $(MAIN_O) | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(OPENGL_LDFLAGS)

$(STATIC_LIB): $(LIB_OBJECTS) | $(BUILD_DIR)
	ar rcs $@ $^

$(LIB_OBJECTS): $(LIB_SOURCES_C)| $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $(LIB_SOURCES_C) -o $@

$(MAIN_O): | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OPENGL_LDFLAGS) -c $(MAIN_C) -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

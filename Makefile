# ============================================================
#  Metroid — Makefile SDL2 (notebook)
# ============================================================

CC     = gcc
TARGET = metroid
CFLAGS = -Wall -Wextra -std=c11 -I include -I generated \
         -DRUNNING_SDL2 $(shell sdl2-config --cflags)
CFLAGS += -g -O0
LDFLAGS = $(shell sdl2-config --libs)

SRC      = $(wildcard src/*.c)
TILE_SRC = $(wildcard mapas/tiles/*/*.c)
ITEM_SRC = $(wildcard mapas/itens/*/*.c)
ENT_SRC  = $(wildcard mapas/entidades/*/*.c)

ALL_SRC  = $(SRC) $(TILE_SRC) $(ITEM_SRC) $(ENT_SRC)
OBJ      = $(patsubst %.c, build/%.o, $(ALL_SRC))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/ $(TARGET)

# ============================================================
#  Metroid — Makefile Linux (placa DE1-SoC)
# ============================================================

CC     = gcc
TARGET = metroid
CFLAGS = -Wall -Wextra -O1 -std=c1x -I include -I generated \
         -DRUNNING_LINUX

SRC      = $(wildcard src/*.c)
TILE_SRC = $(wildcard mapas/tiles/*/collision.c)
ITEM_SRC = $(wildcard mapas/itens/*/collision.c)
ENT_SRC  = $(wildcard mapas/entidades/*/*.c)

ALL_SRC  = $(SRC) $(TILE_SRC) $(ITEM_SRC) $(ENT_SRC)
OBJ      = $(patsubst %.c, build/%.o, $(ALL_SRC))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/ $(TARGET)

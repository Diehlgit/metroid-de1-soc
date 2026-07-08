# ============================================================
#  Metroid DE1-SoC — Makefile
# ============================================================

# --- Toolchain ----------------------------------------------
# Compilação cruzada no notebook:
#   CC = arm-linux-gnueabihf-gcc
# Compilação nativa na placa:
#   CC = gcc
CC     = arm-linux-gnueabihf-gcc
CFLAGS = -Wall -Wextra -O1 -std=c11 -I include -I generated

TARGET = metroid

# --- Fontes -------------------------------------------------
SRC      = $(wildcard src/*.c)
TILE_SRC = $(wildcard mapas/tiles/*/collision.c)
ITEM_SRC = $(wildcard mapas/itens/*/collision.c)
ENT_SRC  = $(wildcard mapas/entidades/*/*.c)

ALL_SRC  = $(SRC) $(TILE_SRC) $(ITEM_SRC) $(ENT_SRC)
OBJ      = $(patsubst %.c, build/%.o, $(ALL_SRC))

# --- Regras -------------------------------------------------
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/ $(TARGET)

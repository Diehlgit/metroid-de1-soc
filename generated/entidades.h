#pragma once
#include "../include/entity.h"
Entity *morcego_create(int x, int y, int h_dir, int v_dir);
Entity *pinwheel_create(int x, int y, int h_dir, int v_dir);
Entity *projetil_create(Entity *shooter, int damage, State *state);
Entity *samus_create(int x, int y, int h_dir, int v_dir);
Entity *scorpion_create(int x, int y, int h_dir, int v_dir);

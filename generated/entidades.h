#pragma once
#include "../include/entity.h"
#include "../mapas/entidades/projetil/projetil.h"
Entity *morcego_create(int x, int y, int h_dir, int v_dir);
Entity *pinwheel_create(int x, int y, int h_dir, int v_dir);
Entity *projetil_create(Entity *shooter, projetilStates tipo);
Entity *samus_create(int x, int y, int h_dir, int v_dir);
Entity *scorpion_create(int x, int y, int h_dir, int v_dir);
Entity *dragao_create(int x, int y);

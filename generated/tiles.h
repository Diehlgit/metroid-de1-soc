#pragma once
#include "../include/entity.h"
#include "../include/area_id.h"
Entity *metal_create(int x, int y);
Entity *porta_create(int x, int y);
Entity *tijolos_create(int x, int y);
Entity *transicao_create(int x, int y, AreaId destino, int spawn_x, int spawn_y);

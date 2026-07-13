#pragma once
#include "../include/area_id.h"
#include "../include/entity.h"

Entity *metal_create(int x, int y);
Entity *porta_create(int x, int y);
Entity *tijolos_create(int x, int y);
Entity *transicao_create(int x, int y, AreaId id, int player_x, int player_y);

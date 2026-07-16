/* AUTO-GERADO por generate_entities.py — não edite */
#pragma once
#include "../include/entity.h"
#include "../include/area_id.h"
Entity *espinhos_create(int x, int y, int spawn_x, int spawn_y);
Entity *estalactite_create(int x, int y);
Entity *metal_create(int x, int y);
Entity *porta_create(int x, int y, int array_pos);
Entity *tijolos_create(int x, int y);
Entity *transicao_create(int x, int y, AreaId destino, int spawn_x, int spawn_y);

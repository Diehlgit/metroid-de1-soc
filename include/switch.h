// include/world.h
#ifndef WORLD_H
#define WORLD_H
#include "entity.h"
#include "../include/area_id.h"

Grid* switch_area(AreaId id, Entity *player, EntityList *ents_list);

#endif

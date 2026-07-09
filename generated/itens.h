/* AUTO-GERADO por generate_itens.py — não edite */
#pragma once
#include <stdint.h>
#include "../include/basics.h"
#include "../include/entity.h"

extern CellList get_rectangle_cells(Hitbox*,Coordinates,int);
extern CellList get_circle_cells   (Hitbox*,Coordinates,int);
extern CellList get_triangle_cells (Hitbox*,Coordinates,int);


typedef struct {
    uint8_t r,g,b;
    Sprite *sprite;
    Hitbox  hitbox;
    void (*on_collision)(struct Entity*,struct Entity*);
    Intent (*think)(Grid*, struct Entity*);
} ItemInfo;

static ItemInfo ITEM_REGISTRY[] = {
};
static int ITEM_REGISTRY_SIZE=0;

static ItemInfo* item_from_color(uint8_t r,uint8_t g,uint8_t b){
    for(int i=0;i<ITEM_REGISTRY_SIZE;i++){
        ItemInfo *it=&ITEM_REGISTRY[i];
        if(it->r==r&&it->g==g&&it->b==b) return it;
    }
    return NULL;
}

/* Cria uma Entity de item na posição dada (alocação estática via pool) */
#define MAX_ITEM_INSTANCES 64
static Entity _item_pool[MAX_ITEM_INSTANCES];
static int    _item_pool_count = 0;

static Entity* item_create(ItemInfo *info, Coordinates pos){
    if(!info || _item_pool_count >= MAX_ITEM_INSTANCES) return NULL;
    Entity *e = &_item_pool[_item_pool_count++];
    e->position       = pos;
    e->type           = ENTITY_ITEM;
    e->hitbox         = info->hitbox;
    e->current_sprite = info->sprite;
    e->think          = info->think;
    e->on_collision   = info->on_collision;
    return e;
}

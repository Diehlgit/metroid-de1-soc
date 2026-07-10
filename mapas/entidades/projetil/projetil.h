#include "../../../include/entity.h"

static const uint16_t MOVING_projetil_PIXELS[16] = {
    0x8001, 0xF880, 0xF880, 0x8001,
    0xF880, 0xFEE0, 0xFEE0, 0xF880,
    0xF880, 0xFEE0, 0xFEE0, 0xF880,
    0x8001, 0xF880, 0xF880, 0x8001,
};
static Sprite MOVING_projetil = {
    .height=4, .width=4,
    .pixels=(uint16_t*)MOVING_projetil_PIXELS
};

static Sprite *projetil_moving_frames[] = {
    &MOVING_projetil,
};

static Animation anim_moving = {
    .frames          = projetil_moving_frames,
    .frame_count     = 1,
    .frame_duration  = 1,
    .loops           = 0,
};

extern const Entity PROJETIL_TEMPLATE;

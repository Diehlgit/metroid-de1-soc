#include "graphics.h"

/* ------------------------------------------------------------------------
 * plot_pixel
 *
 * Lowest-level primitive: writes a single pixel directly into the VGA
 * framebuffer via its memory-mapped address.
 *
 * The DE1-SoC VGA controller lays pixels out with each row padded to a
 * 1024-byte (512-pixel) stride, so the address of pixel (x, y) is:
 *
 *     VGA_BASE + (y << 10) + (x << 1)
 *
 * (y << 10) advances by 1024 bytes per row, (x << 1) advances by 2 bytes
 * per pixel (RGB565 = 16 bits/pixel).
 * ------------------------------------------------------------------------ */
static void plot_pixel(uint16_t x, uint16_t y, color_t color)
{
    volatile color_t *pixel_address =
        (volatile color_t *)(VGA_BASE + ((uint32_t)y << 10) + ((uint32_t)x << 1));
 
    *pixel_address = color;
}

/* ------------------------------------------------------------------------
 * draw_sprite_generic
 *
 * Shared helper: blits a row-major pixel buffer of size (w x h) with its
 * top-left corner at screen pixel (x, y), clipping any part that falls
 * off-screen.
 * ------------------------------------------------------------------------ */
static void draw_sprite_generic(uint16_t x, uint16_t y,
                                 uint16_t w, uint16_t h,
                                 const color_t *sprite)
{
    for (uint16_t row = 0; row < h; row++)
    {
        uint16_t screen_y = y + row;
        if (screen_y >= SCREEN_HEIGHT_PX)
        {
            break; /* off the bottom edge; rows after this are too */
        }

        for (uint16_t col = 0; col < w; col++)
        {
            uint16_t screen_x = x + col;
            if (screen_x >= SCREEN_WIDTH_PX)
            {
                break; /* off the right edge; rest of this row is too */
            }
			color_t pixel = sprite[row * w + col];

			if (pixel != COLOR_TRANSPARENT)
			{
            	plot_pixel(screen_x, screen_y, pixel);
			}
        }
    }
}

/* ------------------------------------------------------------------------
 * draw_map
 * ------------------------------------------------------------------------ */
void draw_map(const uint8_t map[GRID_ROWS][GRID_COLS],
              const color_t tileset[][BLOCK_SIZE_PX * BLOCK_SIZE_PX],
              uint32_t tile_count)
{
    for (uint16_t row = 0; row < GRID_ROWS; row++)
    {
        for (uint16_t col = 0; col < GRID_COLS; col++)
        {
            uint8_t tile_id = map[row][col];
            if (tile_id >= tile_count)
            {
                continue; /* skip invalid tile indices rather than fault */
            }

            uint16_t origin_x = (uint16_t)(col * BLOCK_SIZE_PX);
            uint16_t origin_y = (uint16_t)(row * BLOCK_SIZE_PX);

            draw_sprite_generic(origin_x, origin_y,
                                 BLOCK_SIZE_PX, BLOCK_SIZE_PX,
                                 tileset[tile_id]);
        }
    }
}

/* ------------------------------------------------------------------------
 * draw_samus
 * ------------------------------------------------------------------------ */
void draw_samus(uint16_t x, uint16_t y,
                 const color_t sprite[SAMUS_WIDTH_PX * SAMUS_HEIGHT_PX])
{
    draw_sprite_generic(x, y, SAMUS_WIDTH_PX, SAMUS_HEIGHT_PX, sprite);
}

/* ------------------------------------------------------------------------
 * draw_samus_ball
 * ------------------------------------------------------------------------ */
void draw_samus_ball(uint16_t x, uint16_t y,
                      const color_t sprite[SAMUS_BALL_WIDTH_PX * SAMUS_BALL_HEIGHT_PX])
{
    draw_sprite_generic(x, y, SAMUS_BALL_WIDTH_PX, SAMUS_BALL_HEIGHT_PX, sprite);
}

/* ------------------------------------------------------------------------
 * draw_enemy
 * ------------------------------------------------------------------------ */
void draw_enemy(uint16_t x, uint16_t y,
                 const color_t sprite[ENEMY_WIDTH_PX * ENEMY_HEIGHT_PX])
{
    draw_sprite_generic(x, y, ENEMY_WIDTH_PX, ENEMY_HEIGHT_PX, sprite);
}

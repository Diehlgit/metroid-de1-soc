#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

/* ------------------------------------------------------------------------
 * Display geometry (DE1-SoC VGA display)
 * ------------------------------------------------------------------------ */
#define VGA_BASE			0xC8000000
#define SCREEN_WIDTH_PX     320
#define SCREEN_HEIGHT_PX    240

/* Logical block (tile) size, in pixels */
#define BLOCK_SIZE_PX       8

/* Grid dimensions, in blocks */
#define GRID_COLS           (SCREEN_WIDTH_PX  / BLOCK_SIZE_PX)   /* 40 */
#define GRID_ROWS           (SCREEN_HEIGHT_PX / BLOCK_SIZE_PX)   /* 30 */

/* ------------------------------------------------------------------------
 * Sprite geometry
 * ------------------------------------------------------------------------ */
#define SAMUS_WIDTH_PX      24
#define SAMUS_HEIGHT_PX     32
#define SAMUS_WIDTH_BLK     (SAMUS_WIDTH_PX  / BLOCK_SIZE_PX)    /* 3 */
#define SAMUS_HEIGHT_BLK    (SAMUS_HEIGHT_PX / BLOCK_SIZE_PX)    /* 4 */

/* Samus "ball" (morph ball) stance - smaller alternate sprite */
#define SAMUS_BALL_WIDTH_PX   16
#define SAMUS_BALL_HEIGHT_PX  16
#define SAMUS_BALL_WIDTH_BLK  (SAMUS_BALL_WIDTH_PX  / BLOCK_SIZE_PX)  /* 2 */
#define SAMUS_BALL_HEIGHT_BLK (SAMUS_BALL_HEIGHT_PX / BLOCK_SIZE_PX)  /* 2 */

#define ENEMY_WIDTH_PX      32
#define ENEMY_HEIGHT_PX     32
#define ENEMY_WIDTH_BLK     (ENEMY_WIDTH_PX  / BLOCK_SIZE_PX)    /* 4 */
#define ENEMY_HEIGHT_BLK    (ENEMY_HEIGHT_PX / BLOCK_SIZE_PX)    /* 4 */

/* ------------------------------------------------------------------------
 * Pixel format
 *
 * The DE1-SoC UART pixel protocol commonly used in coursework expects
 * 16-bit RGB565 pixel values. Adjust this typedef if your driver uses a
 * different format (e.g. 8-bit indexed color).
 * ------------------------------------------------------------------------ */
typedef uint16_t color_t;
#define COLOR_TRANSPARENT   0xF81F

/* ------------------------------------------------------------------------
 * draw_map
 *
 * Draws the full background map, tile by tile, onto the display.
 *
 * @param map         Row-major array of tile indices, [GRID_ROWS][GRID_COLS].
 *                     Each entry selects a tile from `tileset`.
 * @param tileset     Array of tile bitmaps. Each tile is
 *                     BLOCK_SIZE_PX * BLOCK_SIZE_PX pixels, stored row-major.
 * @param tile_count  Number of tiles available in `tileset` (used for
 *                     bounds-checking tile indices found in `map`).
 *
 * Notes:
 *   - The map covers the whole 320x240 screen when GRID_COLS x GRID_ROWS
 *     (40x30) tiles are supplied.
 *   - Screen pixel origin for block (col, row) is:
 *       x = col * BLOCK_SIZE_PX
 *       y = row * BLOCK_SIZE_PX
 * ------------------------------------------------------------------------ */
void draw_map(const uint8_t map[GRID_ROWS][GRID_COLS],
              const color_t tileset[][BLOCK_SIZE_PX * BLOCK_SIZE_PX],
              uint32_t tile_count);

/* ------------------------------------------------------------------------
 * draw_samus
 *
 * Draws the Samus player sprite at pixel coordinate (x, y), where (x, y)
 * is the top-left corner of the sprite.
 *
 * @param x       Top-left x coordinate, in pixels.
 *                Valid range: 0 .. (SCREEN_WIDTH_PX - SAMUS_WIDTH_PX)
 * @param y       Top-left y coordinate, in pixels.
 *                Valid range: 0 .. (SCREEN_HEIGHT_PX - SAMUS_HEIGHT_PX)
 * @param sprite  Row-major pixel data for the sprite, of size
 *                SAMUS_WIDTH_PX * SAMUS_HEIGHT_PX color_t values.
 *
 * Notes:
 *   - x and y are given in pixels, not blocks, so the sprite is not
 *     restricted to snapping onto the 8x8 grid (useful for smooth motion).
 *   - Implementation should clip drawing at screen edges if x/y plus the
 *     sprite dimensions exceed SCREEN_WIDTH_PX/SCREEN_HEIGHT_PX.
 * ------------------------------------------------------------------------ */
void draw_samus(uint16_t x, uint16_t y,
                 const color_t sprite[SAMUS_WIDTH_PX * SAMUS_HEIGHT_PX]);

/* ------------------------------------------------------------------------
 * draw_samus_ball
 *
 * Draws Samus in her "ball" (morph ball) stance at pixel coordinate
 * (x, y), where (x, y) is the top-left corner of the sprite. This is a
 * separate, smaller sprite from the standing sprite used by draw_samus.
 *
 * @param x       Top-left x coordinate, in pixels.
 *                Valid range: 0 .. (SCREEN_WIDTH_PX - SAMUS_BALL_WIDTH_PX)
 * @param y       Top-left y coordinate, in pixels.
 *                Valid range: 0 .. (SCREEN_HEIGHT_PX - SAMUS_BALL_HEIGHT_PX)
 * @param sprite  Row-major pixel data for the sprite, of size
 *                SAMUS_BALL_WIDTH_PX * SAMUS_BALL_HEIGHT_PX color_t values.
 * ------------------------------------------------------------------------ */
void draw_samus_ball(uint16_t x, uint16_t y,
                      const color_t sprite[SAMUS_BALL_WIDTH_PX * SAMUS_BALL_HEIGHT_PX]);

/* ------------------------------------------------------------------------
 * draw_enemy
 *
 * Draws an enemy sprite at pixel coordinate (x, y), where (x, y) is the
 * top-left corner of the sprite.
 *
 * @param x       Top-left x coordinate, in pixels.
 *                Valid range: 0 .. (SCREEN_WIDTH_PX - ENEMY_WIDTH_PX)
 * @param y       Top-left y coordinate, in pixels.
 *                Valid range: 0 .. (SCREEN_HEIGHT_PX - ENEMY_HEIGHT_PX)
 * @param sprite  Row-major pixel data for the sprite, of size
 *                ENEMY_WIDTH_PX * ENEMY_HEIGHT_PX color_t values.
 * ------------------------------------------------------------------------ */
void draw_enemy(uint16_t x, uint16_t y,
                 const color_t sprite[ENEMY_WIDTH_PX * ENEMY_HEIGHT_PX]);

#endif /* GRAPHICS_H */

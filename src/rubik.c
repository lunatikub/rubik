#include <string.h>

#include "rubik.h"

struct rubik* rubik_create(void)
{
  struct rubik *new = NULL;

  new = malloc(sizeof(struct rubik));
  memset(new, 0, sizeof(struct rubik));

  return new;
}

void rubik_destroy(struct rubik **cube)
{
  free(*cube);
}

/**
 * Set case (x.y) with the 'color' of the 'face'.
 */
static inline void rubik_set_case(struct rubik *cube,
                                  enum rubik_face face,
                                  uint32_t x,
                                  uint32_t y,
                                  enum rubik_color color)
{
  cube->faces[face][x][y] = color;
}

/**
 * Fill an entire 'face' with 'color'.
 */
static inline
void rubik_fill_face(struct rubik *cube,
                     enum rubik_face face,
                     enum rubik_color color)
{
  uint32_t x = 0;
  uint32_t y = 0;

  for (x = 0; x < RUBIK_SZ; ++x) {
    for (y = 0; y < RUBIK_SZ; ++y) {
      rubik_set_case(cube, face, x, y, color);
    }
  }
}

void rubik_reset(struct rubik *cube)
{
  rubik_fill_face(cube, FRONT, BLUE);
  rubik_fill_face(cube, LEFT, ORANGE);
  rubik_fill_face(cube, UP, YELLOW);
  rubik_fill_face(cube, DOWN, WHITE);
  rubik_fill_face(cube, RIGHT, RED);
  rubik_fill_face(cube, BACK, GREEN);
}

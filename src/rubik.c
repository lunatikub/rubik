#include <stdio.h>
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

bool rubik_eq(struct rubik *c1, struct rubik *c2)
{
  uint32_t f = 0;
  uint32_t x = 0;
  uint32_t y = 0;

  for (f = FRONT; f < NR_FACE; ++f) {
    for (x = 0; x < RUBIK_SZ; ++x) {
      for (y = 0; y < RUBIK_SZ; ++y) {
        if (c1->faces[f][x][y] != c2->faces[f][x][y]) {
          return false;
        }
      }
    }
  }

  return true;
}

void rubik_dump(struct rubik *cube)
{
  uint32_t f = 0;
  uint32_t x = 0;
  uint32_t y = 0;

  for (f = FRONT; f < NR_FACE; ++f) {
    for (y = 0; y < RUBIK_SZ; ++y) {
      for (x = 0; x < RUBIK_SZ; ++x) {
        printf("%u ", cube->faces[f][x][y]);
      }
      printf("\n");
    }
    printf("\n");
  }
}

void rubik_cp(struct rubik *src, struct rubik *dst)
{
  uint32_t f = 0;
  uint32_t x = 0;
  uint32_t y = 0;

  for (f = FRONT; f < NR_FACE; ++f) {
    for (y = 0; y < RUBIK_SZ; ++y) {
      for (x = 0; x < RUBIK_SZ; ++x) {
        dst->faces[f][x][y] = src->faces[f][x][y];
      }
    }
  }
}

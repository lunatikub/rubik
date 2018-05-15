#include <stdbool.h>
#include <assert.h>

#include "rubik.h"
#include "rubik_move.h"

void rubik_move_h_clockwise(struct rubik *cube, uint32_t y)
{
  uint32_t i = 0;
  uint8_t tmp;

  for (i = 0; i < RUBIK_SZ; ++i) {
    tmp = cube->faces[LEFT][i][y];
    cube->faces[LEFT][i][y] = cube->faces[FRONT][i][y];
    cube->faces[FRONT][i][y] = cube->faces[RIGHT][i][y];
    cube->faces[RIGHT][i][y] = cube->faces[BACK][i][y];
    cube->faces[BACK][i][y] = tmp;
  }
}

void rubik_move_h_invert_clockwise(struct rubik *cube, uint32_t y)
{
  uint32_t i = 0;
  uint8_t tmp;

  for (i = 0; i < RUBIK_SZ; ++i) {
    tmp = cube->faces[BACK][i][y];
    cube->faces[BACK][i][y] = cube->faces[RIGHT][i][y];
    cube->faces[RIGHT][i][y] = cube->faces[FRONT][i][y];
    cube->faces[FRONT][i][y] = cube->faces[LEFT][i][y];
    cube->faces[LEFT][i][y] = tmp;
  }
}

void rubik_move(struct rubik *cube, const struct rubik_move *move)
{
#define CASE_MV(_mv, fct) \
  case _mv: fct(cube, move->prime, move->uturn); break;

  switch (move->basic) {
    CASE_MV(MV_U, rubik_move_u);
    CASE_MV(MV_D, rubik_move_d);
    default: assert(!"Move is not defined");
  }

#undef CASE_MV
}

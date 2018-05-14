#include <stdbool.h>
#include <assert.h>

#include "rubik.h"
#include "rubik_move.h"

/*****
 * U *
 *****/

/* U [up basic] */
static inline void rubik_mv_u_b(struct rubik *cube)
{
  uint32_t i = 0;
  uint8_t tmp;

  for (i = 0; i < RUBIK_SZ; ++i) {
    tmp = cube->faces[LEFT][i][0];
    cube->faces[LEFT][i][0] = cube->faces[FRONT][i][0];
    cube->faces[FRONT][i][0] = cube->faces[RIGHT][i][0];
    cube->faces[RIGHT][i][0] = cube->faces[BACK][i][0];
    cube->faces[BACK][i][0] = tmp;
  }
}

/* U' [up prime] */
static inline void rubik_mv_u_p(struct rubik *cube)
{
  uint32_t i = 0;
  uint8_t tmp;

  for (i = 0; i < RUBIK_SZ; ++i) {
    tmp = cube->faces[BACK][i][0];
    cube->faces[BACK][i][0] = cube->faces[RIGHT][i][0];
    cube->faces[RIGHT][i][0] = cube->faces[FRONT][i][0];
    cube->faces[FRONT][i][0] = cube->faces[LEFT][i][0];
    cube->faces[LEFT][i][0] = tmp;
  }
}

/* U2 [up basic 2] */
static inline void rubik_mv_u_b_2(struct rubik *cube)
{
  rubik_mv_u_b(cube);
  rubik_mv_u_b(cube);
}

/* U2' [up prime 2] */
static inline void rubik_mv_u_p_2(struct rubik *cube)
{
  rubik_mv_u_p(cube);
  rubik_mv_u_p(cube);
}

static inline void rubik_mv_u(struct rubik *cube, bool prime, bool uturn)
{
  if (uturn && prime) {
    rubik_mv_u_p_2(cube);
  } else if (uturn) {
    rubik_mv_u_b_2(cube);
  } else if (prime) {
    rubik_mv_u_p(cube);
  } else {
    rubik_mv_u_b(cube);
  }
}

void rubik_move(struct rubik *cube, struct rubik_move *move)
{
  switch (move->basic) {
    case MV_U: rubik_mv_u(cube, move->prime, move->uturn);
    default: assert(!"Move is not defined");
  }
}

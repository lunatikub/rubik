#include "rubik_move.h"

/* U [up] */
static inline void rubik_mv_u(struct rubik *cube)
{
  rubik_move_h_clockwise(cube, 0);
}

/* U' [up prime] */
static inline void rubik_mv_u_p(struct rubik *cube)
{
  rubik_move_h_invert_clockwise(cube, 0);
}

/* U2 [up 2] */
static inline void rubik_mv_u_2(struct rubik *cube)
{
  rubik_mv_u(cube);
  rubik_mv_u(cube);
}

/* U2' [up prime 2] */
static inline void rubik_mv_u_2_p(struct rubik *cube)
{
  rubik_mv_u_p(cube);
  rubik_mv_u_p(cube);
}

void rubik_move_u(struct rubik *cube, bool prime, bool uturn)
{
  if (uturn && prime) {
    rubik_mv_u_2_p(cube);
  } else if (uturn) {
    rubik_mv_u_2(cube);
  } else if (prime) {
    rubik_mv_u_p(cube);
  } else {
    rubik_mv_u(cube);
  }
}

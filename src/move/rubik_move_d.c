#include "rubik_move.h"

/* D [Down] */
static inline void rubik_mv_d(struct rubik *cube)
{
  rubik_move_h_invert_clockwise(cube, 2);
}

/* D' [Down prime] */
static inline void rubik_mv_d_p(struct rubik *cube)
{
  rubik_move_h_clockwise(cube, 2);
}

/* D2 [up 2] */
static inline void rubik_mv_d_2(struct rubik *cube)
{
  rubik_mv_d(cube);
  rubik_mv_d(cube);
}

/* D2' [up prime 2] */
static inline void rubik_mv_d_2_p(struct rubik *cube)
{
  rubik_mv_d_p(cube);
  rubik_mv_d_p(cube);
}

void rubik_move_d(struct rubik *cube, bool prime, bool uturn)
{
  if (uturn && prime) {
    rubik_mv_d_2_p(cube);
  } else if (uturn) {
    rubik_mv_d_2(cube);
  } else if (prime) {
    rubik_mv_d_p(cube);
  } else {
    rubik_mv_d(cube);
  }
}

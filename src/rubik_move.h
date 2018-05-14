#ifndef __RUBIK_MOVE_H__
# define __RUBIK_MOVE_H__

#include "rubik.h"

enum rubik_basic_move {
  MV_U, /* U [Up] */
};

struct rubik_move {
  enum rubik_basic_move basic; /* Basic move. */
  uint32_t prime:1; /* Clockwise direction. */
  uint32_t uturn:1; /* U-Turn. */
};

/**
 * Do a move on a cube.
 * Move must belong to the enumeration 'rubik_move'.
 */
void rubik_move(struct rubik *cube, struct rubik_move *move);

#endif /* !__RUBIK_MOVE_H__ */

#ifndef __RUBIK_MOVE_H__
# define __RUBIK_MOVE_H__

#include "rubik.h"

enum rubik_basic_move {
  MV_U, /* U [Up] */
  MV_D, /* D [Down] */
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
void rubik_move(struct rubik *cube, const struct rubik_move *move);

/**
 * Generic moves.
 */
void rubik_move_h_clockwise(struct rubik *cube, uint32_t y);
void rubik_move_h_invert_clockwise(struct rubik *cube, uint32_t y);

/**
 * All allowed basic moves.
 */
void rubik_move_u(struct rubik *cube, bool prime, bool uturn);
void rubik_move_d(struct rubik *cube, bool prime, bool uturn);

#endif /* !__RUBIK_MOVE_H__ */

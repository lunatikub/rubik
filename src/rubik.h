#ifndef __RUBIK_H__
# define __RUBIK_H__

#include <stdint.h>
#include <stdlib.h>

#define RUBIK_SZ (3)

enum rubik_color {
  RED,
  BLUE,
  YELLOW,
  WHITE,
  GREEN,
  ORANGE,
  NR_COLOR,
};

enum rubik_face {
  FRONT,
  LEFT,
  UP,
  DOWN,
  RIGHT,
  BACK,
  NR_FACE,
};

struct rubik {
  uint8_t faces[NR_FACE][RUBIK_SZ][RUBIK_SZ];
};

struct rubik* rubik_create(void);
void rubik_destroy(struct rubik **rubik);
void rubik_reset(struct rubik *rubik);

#endif /* !__RUBIK_H__ */

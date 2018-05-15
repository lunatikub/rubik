#ifndef __RUBIK_H__
# define __RUBIK_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

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

/**
 * Structure used to manage a rubik's cube.
 */
struct rubik {
  uint8_t faces[NR_FACE][RUBIK_SZ][RUBIK_SZ];
};

/**
 * Create a new cube.
 */
struct rubik* rubik_create(void);

/**
 * Destroy a cube.
 */
void rubik_destroy(struct rubik **cube);

/**
 * Reset a cube.
 * + FRONT: blue.
 * + LEFT: orange.
 * + UP: yellow.
 * + DOWN: white.
 * + RIGHT: red.
 * + BACK: green.
 */
void rubik_reset(struct rubik *cube);

/**
 * Copy a cube from source to destination.
 */
void rubik_cp(struct rubik *src, struct rubik *dst);

/**
 * Return true if the cubes are equals.
 * Otherwise return false.
 */
bool rubik_eq(struct rubik *c1, struct rubik *c2);

/**
 * Dump the cube on stdout.
 */
void rubik_dump(struct rubik *cube);

#endif /* !__RUBIK_H__ */

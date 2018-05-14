#include <assert.h>
#include <curses.h>

#include "rubik.h"

void rubik_x_init(void)
{
  initscr();
  start_color();

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
}

void rubik_x_clean(void)
{
  endwin();
}

static inline int rubik_x_case2color(uint8_t c)
{
  switch (c) {
    case RED: return 1;
    case BLUE: return 4;
    case YELLOW: return 3;
    case WHITE: return 7;
    case GREEN: return 2;
    case ORANGE: return 5;
    default: assert(!"Bad color !");
  }
  return -1;
}

static inline void rubik_x_dump_case(struct rubik *cube,
                                     enum rubik_face face,
                                     uint32_t x,
                                     uint32_t y,
                                     uint32_t x_orig,
                                     uint32_t y_orig)
{
  int color = rubik_x_case2color(cube->faces[face][x][y]);

  attron(COLOR_PAIR(color));
  mvprintw(y_orig + y, x_orig + x, "X");
  attroff(COLOR_PAIR(color));
}

static inline void rubik_x_dump_face(struct rubik *cube,
                                     enum rubik_face face,
                                     uint32_t x_orig,
                                     uint32_t y_orig)
{
  for (uint32_t x = 0; x < RUBIK_SZ; ++x) {
    for (uint32_t y = 0; y < RUBIK_SZ; ++y) {
      rubik_x_dump_case(cube, face, x, y, x_orig, y_orig);
    }
  }
}

void rubik_x_dump(struct rubik *cube, uint32_t x_orig, uint32_t y_orig)
{
  rubik_x_dump_face(cube, DOWN, x_orig + 4, y_orig + 6);
  rubik_x_dump_face(cube, LEFT, x_orig, y_orig + 3);
  rubik_x_dump_face(cube, FRONT, x_orig + 4, y_orig + 3);
  rubik_x_dump_face(cube, RIGHT, x_orig + 8, y_orig + 3);
  rubik_x_dump_face(cube, UP, x_orig + 4, y_orig);
  rubik_x_dump_face(cube, BACK, x_orig + 12, y_orig + 3);
  refresh();
}

void rubik_x_pause(void)
{
  getchar();
}

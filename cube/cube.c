#include "rubik.h"
#include "rubik_x.h"
#include "rubik_move.h"
#include "rubik_parser.h"

int main(void)
{
  struct rubik *cube = NULL;

  cube = rubik_create();
  rubik_x_init();

  rubik_reset(cube);
  rubik_x_dump(cube, 1, 1);
  struct rubik_move mv = { MV_D, 1, 0 };
  rubik_move(cube, &mv);
  rubik_x_dump(cube, 20, 1);
  rubik_x_pause();

  rubik_destroy(&cube);
  rubik_x_clean();

  return 0;
}

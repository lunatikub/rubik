#include "rubik.h"
#include "rubik_x.h"
#include "rubik_move.h"
#include "rubik_parser.h"

int main(int argc, char **argv)
{
  (void)argc;

  struct rubik_move seq[10] = { };

  uint32_t nr_move = rubik_parse(argv[1], seq);
  rubik_dump_seq(seq, nr_move);

  return 0;

  struct rubik *cube = NULL;

  cube = rubik_create();
  rubik_x_init();

  rubik_reset(cube);
  rubik_x_dump(cube, 1, 1);
  struct rubik_move mv = { MV_U, 0, 0 };
  rubik_move(cube, &mv);
  rubik_x_dump(cube, 20, 1);
  rubik_x_pause();

  rubik_destroy(&cube);
  rubik_x_clean();

  return 0;
}

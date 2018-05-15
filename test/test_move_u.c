#include "rubik_test.h"

#define RESET_CUBE \
  c1 = *c;         \
  c2 = *c;         \

int main(void)
{
  struct rubik *c = NULL;

  struct rubik c1;
  struct rubik c2;

  c = rubik_create();
  rubik_reset(c);

  /* U2 = UU */
  RESET_CUBE;
  rubik_move(&c1, &mv_u);
  rubik_move(&c1, &mv_u);
  rubik_move(&c2, &mv_u_2);
  EXPECT_EQ(rubik_eq(&c1, &c2), true);

  /* U2' = U'U' */
  RESET_CUBE;
  rubik_move(&c1, &mv_u_p);
  rubik_move(&c1, &mv_u_p);
  rubik_move(&c2, &mv_u_2_p);
  EXPECT_EQ(rubik_eq(&c1, &c2), true);

  /* "U2'U2 = {I} = U2U2' */
  RESET_CUBE;
  rubik_move(&c1, &mv_u_2_p);
  rubik_move(&c1, &mv_u_2);
  EXPECT_EQ(rubik_eq(&c1, &c2), true);
  rubik_move(&c2, &mv_u_2);
  rubik_move(&c2, &mv_u_2_p);
  EXPECT_EQ(rubik_eq(&c1, &c2), true);

  /* U2U = U' */
  RESET_CUBE;
  rubik_move(&c1, &mv_u_2);
  rubik_move(&c1, &mv_u);
  rubik_move(&c2, &mv_u_p);
  EXPECT_EQ(rubik_eq(&c1, &c2), true);

  rubik_destroy(&c);
  return 0;
}

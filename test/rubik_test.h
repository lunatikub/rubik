#ifndef __RUBIK_TEST_H__
# define __RUBIK_TEST_H__

#include <stdio.h>
#include <stdbool.h>

#include "rubik.h"
#include "rubik_move.h"
#include "rubik_parser.h"

static const struct rubik_move mv_u = { MV_U, 0, 0 };
static const struct rubik_move mv_u_2 = { MV_U, 0, 1 };
static const struct rubik_move mv_u_p = { MV_U, 1, 0 };
static const struct rubik_move mv_u_2_p = { MV_U, 1, 1 };

#define EXPECT_EQ(_x, _y) \
  if ((_x) != (_y)) {     \
    return 1;             \
  }

#endif /* !__RUBIK_TEST_H__ */

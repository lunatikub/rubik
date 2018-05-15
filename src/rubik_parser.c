#include <stdio.h>
#include <assert.h>

#include "rubik_parser.h"

/**
 * Link a character with a basic move.
 */
struct rubik_pair {
  char c;
  enum rubik_basic_move m;
};

/**
 * All allowed basic moves associated with
 * the corresponding character.
 */
static const struct rubik_pair allowed[] = {
  { 'U', MV_U },
  { 'D', MV_D },
};

/**
 * Return a basic move from the associated character.
 * Assert if not found.
 */
static inline enum rubik_basic_move rubik_get_basic_move(char m)
{
  for (uint32_t i = 0; i < sizeof(allowed) / sizeof(struct rubik_pair); ++i) {
    if (m == allowed[i].c) {
      return allowed[i].m;
    }
  }
  assert(!"rubik_get_move");
}

uint32_t rubik_parse(const char *moves, struct rubik_move *seq)
{
  uint32_t i = 0;
  uint32_t nr_move = 0;

  while (moves[i]) {
    seq[nr_move].basic = rubik_get_basic_move(moves[i]);
    ++i; /* eat the basic move */
    if (moves[i] == '2') {
      seq[nr_move].uturn = 1;
      ++i; /* eat the u-turn */
    }
    if (moves[i] == '\'') {
      seq[nr_move].prime = 1;
      ++i; /* eath the prime */
    }
    ++nr_move;
  }

  return nr_move;
}

static void rubik_dump_move(struct rubik_move *move)
{
  switch (move->basic) {
    case MV_U: printf("U"); break;
    case MV_D: printf("D"); break;
  }
  if (move->uturn) {
    printf("2");
  }
  if (move->prime) {
    printf("'");
  }
  printf("\n");
}

void rubik_dump_seq(struct rubik_move *seq, uint32_t nr_move)
{
  for (uint32_t i = 0; i < nr_move; ++i) {
    rubik_dump_move(&seq[i]);
  }
}

#ifndef __RUBIK_PARSER_H__
# define __RUBIK_PARSER_H__

#include "rubik_move.h"

/**
 * Parse a move sequence with David Singmaster's notation.
 * Return the number of moves.
 */
uint32_t rubik_parse(const char *moves, struct rubik_move *seq);

void rubik_dump_seq(struct rubik_move *seq, uint32_t nr_move);

#endif /* !__RUBIK_PARSER_H__ */

cmake_minimum_required (VERSION 2.6)
project (rubik)

set(CMAKE_C_FLAGS "\
-W -Wall -Wextra -Wundef -Wshadow -Wfloat-equal \
-Wpointer-arith -Wcast-align \
-Wstrict-prototypes -Wwrite-strings -Wunreachable-code")

include_directories(
  src
  src/move
)

file(
  GLOB_RECURSE
  source_files
  src/rubik.c
  src/rubik_parser.c
  src/rubik_x.c
  src/move/rubik_move.c
  src/move/rubik_move_u.c
  src/move/rubik_move_d.c
  cube/cube.c
)

add_executable(
  rubik
  ${source_files}
)

target_link_libraries(
  rubik
  ncurses
)

cmake_minimum_required (VERSION 2.6)
project (rubik)

set(CMAKE_C_FLAGS "\
-W -Wall -Wextra -Wundef -Wshadow -Wfloat-equal \
-Wpointer-arith -Wcast-align \
-Wstrict-prototypes -Wwrite-strings -Wunreachable-code")

include_directories(
  src
)

file(
  GLOB_RECURSE
  source_files
  src/*
)

add_executable(
  rubik
  ${source_files}
)

target_link_libraries(
  rubik
  ncurses
)

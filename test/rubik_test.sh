#!/bin/bash

# Colors (set to () to disable ANSI)
declare -A color=( \
           [reset]="\033[0m"		\
           [black]="\033[0;30m"		\
           [darkgray]="\033[1;30m"	\
           [red]="\033[0;31m"	 	\
           [lightred]="\033[1;31m"	\
           [green]="\033[0;32m"	 	\
           [lightgreen]="\033[1;32m"	\
           [orange]="\033[0;33m"	\
           [yellow]="\033[1;33m"	\
           [blue]="\033[0;34m"		\
           [lightblue]="\033[1;34m"	\
           [purple]="\033[0;35m"	\
           [lightpurple]="\033[1;35m"	\
           [cyan]="\033[0;36m"	 	\
           [lightcyan]="\033[1;36m"	\
           [lightgray]="\033[0;37m"	\
           [white]="\033[1;37m"	 	\
)

CFLAGS="-g -ggdb -W -Wall -Wextra -Wundef -Wshadow -Wfloat-equal \
-Wpointer-arith -Wcast-align \
-Wstrict-prototypes -Wwrite-strings -Wunreachable-code"

SRC=../src
LIB=-lncurses

get_ms()
{
    date +%s%N | cut -b1-13
}

rubik_test()
{
    local test_name=$1

    gcc ${CFLAGS} ${SRC}/*.c ${SRC}/move/*.c -I${SRC} -I${SRC}/move \
        ${test_name}.c -o ${test_name} ${LIB}
    [ $? -ne 0 ] && return 1
    ./${test_name}
    [ $? -ne 0 ] && return 1
    return 0
}

rubik_suite()
{
    local suite=$1
    local name_suite=$2

    printf "${color[purple]}<Rubik test ${name_suite}>${color[reset]}\n"
    for test_name in ${suite[*]}
    do
        printf "${color[yellow]}[${test_name}]${color[reset]} "
        start="$(get_ms)"
        rubik_test ${test_name}
        ret=$?
        end="$(get_ms)"
        if [ $ret -eq 0 ]
        then
            printf "${color[green]}[OK ($[$end-$start]ms)]${color[reset]} \n"
        else
            printf "${color[red]}[KO ($[$end-$start]ms)]${color[reset]}\n"
        fi
    done
    printf "${color[purple]}<Rubik test ${name_suite}>${color[reset]}\n"
}

test_move=(
    test_move_u
)

rubik_suite ${test_move[*]} "move"

exit 0

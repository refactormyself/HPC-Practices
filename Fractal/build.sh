#!/usr/bin/env bash

# create folder for build files
[ -d "./build" ] && rm -rf ./build/* || mkdir ./build ||:

gcc -Wall -Wextra -Werror -O2 -std=c99 -pedantic \
    -fopenmp -o ./build/fractal \
    main.c

echo "Compilation successful, now writing output to './output.txt'"
./build/fractal > ./output.txt

# remove build files
rm -rf ./build

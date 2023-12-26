#!/bin/sh

set -xe

cc -Wall -Wextra -pedantic -std=c99 -o test test.c
./test

#!/bin/bash

set -eu

INPUT=$1
OUTPUT=$2

cd "$INPUT"

# remove existing file
rm -f "$OUTPUT"

# create zip
7z a "$OUTPUT" \
    -xr!.vs \
    src \
    lib \
    include \
    test \
    README.md
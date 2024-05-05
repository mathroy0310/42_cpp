#!/bin/bash

# Author: maroy
# This simple script to use make in all my cpp exersices

# Usage: ./make.sh [all|re|clean|fclean]
for dir in $(find . -type d -name "ex*")
do
    echo "Processing in directory: $dir"
    make -C $dir $1 > /dev/null
done

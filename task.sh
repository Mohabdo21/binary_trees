#!/usr/bin/env bash
nums=(0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 100 101 102 103 104 110 111 112 113 114 120 121 122 123 124 130 131 132 133 134)
make -s task TASK_NUM=$((nums[$1] - 1)) && ./binary_trees && make -s clean 

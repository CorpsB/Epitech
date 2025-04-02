#!/bin/bash
find -name "#*" -delete -o -name "*#" -delete -o -name "*~" -delete -o -name "~*" -delete -o -name "a.out" -delete -o -name "vgcore*" -delete -o -name "*.gcda" -delete -o -name "*.gcno" -delete -o -name "unit_tests*" -delete -o -name "*.a" -delete -o -name "*.o" -delete -o -name "amazed" -delete
clear

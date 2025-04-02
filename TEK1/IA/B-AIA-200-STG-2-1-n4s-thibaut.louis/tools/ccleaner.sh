#!/bin/bash

find -name "#*" -delete -o -name "*#" -delete -o -name "*~" -delete -o -name "~*" -delete -o -name "vgcore*" -delete -o -name "*.gcda" -delete -o -name "*.gcno" -delete -o -name "unit_tests*" -delete
clear

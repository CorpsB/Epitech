#!/bin/bash
find -name "#*" -delete -o -name "*#" -delete -o -name "*~" -delete -o -name "~*" -delete -o -name "a.out" -delete -o -name "*.gcda" -delete -o -name "*.gcno" -delete -o -name "unit_tests" -delete -o -name "*.a" -delete
git add .
git commit -m "$1"
git push

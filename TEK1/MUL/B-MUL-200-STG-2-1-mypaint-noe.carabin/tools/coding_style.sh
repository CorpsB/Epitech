#!/bin/bash

./tools/ccleaner.sh
../coding-style-checker/coding-style.sh . .
clear
cat coding-style-reports.log
rm coding-style-reports.log
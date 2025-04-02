#!/bin/bash
../../Coding-style-checker/coding-style.sh . ../../Coding-style-checker/report
~/Delivery/coding-style-checker/coding-style.sh . .
clear
cat ../../Coding-style-checker/report/coding-style-reports.log
cat ./coding-style-reports.log
rm coding-style-reports.log

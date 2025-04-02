#!/bin/bash
if [ -z  '$1']
then
    wc -l students.csv
else
   grep -n -r $1 students.csv | wc -l
fi

       


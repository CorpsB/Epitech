#!/bin/bash
if [ -z  $1]
then
    wc -l
else
   grep -n -r -i $1 students.csv | wc -l
fi

       


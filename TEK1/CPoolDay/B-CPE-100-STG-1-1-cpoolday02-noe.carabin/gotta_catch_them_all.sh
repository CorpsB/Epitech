#!/bin/bash
cat passwd.txt | cut -d_ -f 1 | cut -d- -f 1 | cut -d: -f 1  | grep -c "^$1" | wc -l

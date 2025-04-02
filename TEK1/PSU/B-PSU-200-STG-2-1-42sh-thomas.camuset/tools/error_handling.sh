#!/bin/bash

make re
valgrind $1 ./42sh

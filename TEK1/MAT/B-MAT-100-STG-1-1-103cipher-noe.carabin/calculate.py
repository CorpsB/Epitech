#!/usr/bin/env python3
##
## EPITECH PROJECT, 2023
## CALCULATE
## File description:
## Do calculations
##

from math import *
from printing import *

def create_clone(m):
    s = []

    for i in range(len(m)):
        s.append([])
        for col in m[i]:
            s[i].append(col)
    return s

def create_submatrix(m, i, j):
    for row in m:
        del row[j]
    del m[i]
    return m

def get_key_size(key):
    s = len(key)
    n = 0

    while (n**2 < s):
        n += 1
    return n

def get_key_matrix(key, n):
    m = []
    c = 0
    x = 0

    for i in range(n):
        m.append([])
        for j in range(n):
            m[i].append(0)
    for i in range(len(key)):
        if c == n:
            c = 0
            x += 1
        m[x][c] = ord(key[i])
        c += 1
    return m

def get_msg_matrix(msg, n):
    m = []
    c = 0
    i = 0

    for carac in msg:
        if (c == n):
            c = 0
            i += 1
        if (c == 0):
            m.append([])
        m[i].append(ord(carac))
        c += 1
    for i in range(len(m)):
        while (len(m[i]) < n):
            m[i].append(0)
    return m

def multiple_matrix(m1, m2):
    m = []

    if len(m1[0]) != len(m2):
        error_size_print()
    for i in range(len(m1)):
        m.append([])
        for j in range(len(m2[0])):
            m[i].append(0)
            for k in range(len(m2)):
                m[i][j] += m1[i][k] * m2[k][j]
    return m

def multiple_matrix_integer(m, n):
    for i in range(len(m)):
        for j in range(len(m[0])):
            m[i][j] *= n
    return (m)

def transpos_matrix(m):
    s = []

    for i in range(len(m[0])):
        s.append([])
        for j in range(len(m)):
            s[i].append(m[j][i])
    return s

def get_cofactor(m, i, j):
    x = create_clone(m)
    s = create_submatrix(x, i, j)
    a = get_determin_NxN(s)

    if (int((i + j) / 2) != float((i + j) / 2)):
        a = a * (-1)
    return a

def get_determin_NxN(m):
    s = 0

    if len(m) == 1:
        return m[0][0]
    elif len(m) == 2:
        return m[0][0] * m[1][1] - m[0][1] * m[1][0]
    else:
        for i in range(len(m[0])):
            s += (m[0][i] * get_cofactor(m, 0, i))
    return s

def get_inverse_matrix(m):
    s = []

    z = get_determin_NxN(m)
    if (z == 0):
        error_determin_null()
    if (len(m) == 1):
        s.append([1 / z])
        return s
    for i in range(len(m)):
        s.append([])
        for j in range(len(m[0])):
            s[i].append((1 / z) * get_cofactor(m, i, j))
    return transpos_matrix(s)

def get_msg_matrix_crypt(msg, n):
    m = []
    c = ""
    i = 0
    j = 0
    k = 0

    for carac in msg:
        if (j == n):
            i += 1
            j = 0
        if (j == 0 and k == 0):
            m.append([])
            k = 1
        if (carac == ' '):
            m[i].append(int(c))
            c = ""
            k = 0
            j += 1
        else:
            c += carac
    m[len(m) - 1].append(int(c))
    while len(m[len(m) - 1]) < n:
        m[len(m) - 1].append(0)
    return m

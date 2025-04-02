#!/usr/bin/env python3
##
## EPITECH PROJECT, 2023
## PRINT
## File description:
## Print result.
##

def help_print():
    print("USAGE")
    print("    ./103cipher message key flag")
    print()
    print("DESCRIPTION")
    print("    message\ta message, made of ASCII characters")
    print("    key\t\tthe encryption key, made of ASCII characters")
    print("    flag\t0 for the message to be encrypted, 1 to be decrypted")
    exit(0)

def error_unknown_print():
    print("Bad number or bad type of arguments.")
    exit(84)

def error_size_print():
    print("Bad number of arguments.")
    exit(84)

def error_type_print():
    print("Bad type of arguments.")
    exit(84)

def error_determin_null():
    print("The determinant is null.")
    exit(84)

def key_matrix_print(m):
    print("Key matrix:")
    for i in range(len(m)):
        for j in range(len(m[0]) - 1):
            print(round(m[i][j], 3), end="\t")
        print(round(m[i][len(m[0]) - 1], 3))

def crypted_key_matrix_print(m):
    print("Key matrix:")
    for i in range(len(m)):
        for j in range(len(m[0]) - 1):
            if round(m[i][j], 3) != -0.0:
                print(round(m[i][j], 3), end="\t")
            else:
                print(0.0, end="\t")
        if round(m[i][len(m[0]) - 1], 3) != -0.0:
            print(round(m[i][len(m[0]) - 1], 3))
        else:
            print(0.0)

def msg_matrix_print(m):
    a = len(m) - 1
    b = len(m[0]) - 1

    print("Encrypted message:")
    for i in range(a + 1):
        for j in range(b + 1):
            if (i == a and j == b):
                print(m[i][j])
            else:
                print(m[i][j], end = " ")

def msg_alpha_print(m):
    c = ""
    v = 0

    print("Decrypted message:")
    for i in range(len(m)):
        for j in range(len(m[0])):
            v = int(round(m[i][j], 0))
            if (v != 0):
                c += chr(v)
    print(c)

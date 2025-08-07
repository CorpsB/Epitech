;;
;; EPITECH PROJECT, 2025
;; B-ASM-400-STG-4-1-asmminilibc-noe.carabin
;; File description:
;; memcpy
;;

BITS 64
SECTION .note.GNU-stack

GLOBAL memcpy

SECTION .text

;MEMO :
;RAX - Le registre de RETURN
;RDI - Le premier argument
;RSI - Le deuxième argument
;RDX - Le troisième argument
;RCX - Le quatrième argument (Et pleins d'autres, mais coding style ?d)
;
;Un caractère = 8 bits = 1 octets
;MOV déplace : MOV reçoit envoie

;RET = J'ai finis mon travail = return RAX
; AL : Registre de reference pour les octet de manip memoire
; RCX : Registre à utiliser pour faire des boucles, et des comparaisons
; verifier si null
;buffer trop long 
;buffer de 4

memcpy:
    XOR RAX, RAX
    XOR RCX, RCX
    XOR R8, R8
    MOV R8, RDI
    TEST RSI, RSI
    JE .error
    TEST RDI, RDI
    JE .error
    TEST RDX, RDX
    JE .return
    MOV RAX, RDI

.loop:
    MOV AL, [RSI]
    MOV [RDI], AL
    ADD RCX, 1
    ADD RDI, 1
    ADD RSI, 1
    CMP RCX, RDX
    JE .return
    JMP .loop

.return:
    MOV RAX, R8
    RET

.error:
    RET
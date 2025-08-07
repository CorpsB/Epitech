;;
;; EPITECH PROJECT, 2025
;; B-ASM-400-STG-4-1-asmminilibc-noe.carabin
;; File description:
;; memset
;;

BITS 64
SECTION .note.GNU-stack

GLOBAL memset

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
;taille nulle

memset:
    XOR RAX, RAX
    XOR RCX, RCX
    MOV RCX, RDI
    TEST RDI, RDI
    JE .return
    CMP RDX, 0
    JE .return
    MOV BL, SIL

.loop:
    MOV [RDI], BL
    ADD RAX, 1
    ADD RDI, 1
    CMP RAX, RDX
    JE .return
    JMP .loop

.return:
    XOR RAX, RAX
    MOV RAX, RCX
    RET

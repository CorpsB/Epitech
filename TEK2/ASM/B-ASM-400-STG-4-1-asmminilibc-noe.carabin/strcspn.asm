;;
;; EPITECH PROJECT, 2025
;; B-ASM-400-STG-4-1-asmminilibc-noe.carabin
;; File description:
;; strcspn
;;
BITS 64
SECTION .note.GNU-stack

GLOBAL strcspn

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

strcspn:
    XOR RAX, RAX
    TEST RDI, RDI
    JE .error
    TEST RSI, RSI
    JE .error
    MOV RDX, RSI

.loop1:
    MOV BL, [RDI]
    CMP BL, 0
    JE .notfound
    MOV RSI, RDX

.loop2
    MOV CL, [RSI]
    CMP CL, 0
    JE .CONTINUE
    CMP CL, BL
    JE .found
    ADD RSI, 1
    JMP .loop2

.CONTINUE 
    ADD RDI, 1
    ADD RAX, 1
    JMP .loop1

.found:
    RET

.notfound:
    RET

.error:
    RET
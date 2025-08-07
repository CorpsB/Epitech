BITS 64
SECTION .note.GNU-stack

GLOBAL strchr
GLOBAL index
GLOBAL rindex

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
; voir nchr

rindex:
index:
strchr:
    CMP RDI, 0
    JE .done
    XOR RAX, RAX
    MOV BL, SIL

.loop:
    MOV DL, [RDI]
    CMP DL, BL
    JE .find
    CMP DL, 0
    JE .done
    ADD RDI, 1
    JMP .loop

.done:
    XOR RAX, RAX
    RET

.find:
    MOV RAX, RDI
    RET

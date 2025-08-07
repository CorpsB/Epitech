BITS 64
SECTION .note.GNU-stack

GLOBAL strrchr

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
; chercher le '\0'

strrchr:
    XOR RAX, RAX
    CMP RDI, 0
    JE .error
    MOV BL, SIL

.loop:
    MOV DL, [RDI]
    CMP DL, 0
    JE .end
    CMP DL, BL
    JE .find
    ADD RDI, 1
    JMP .loop

.find:
    MOV RAX, RDI
    ADD RDI, 1
    JMP .loop

.findend:
    MOV RAX, RDI
    RET

.end:
    CMP BL, 0
    JE .findend
    RET

.error:
    RET
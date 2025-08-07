BITS 64
SECTION .note.GNU-stack

GLOBAL strlen

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
;

strlen:
    CMP RDI, 0
    JE .done
    XOR RAX, RAX

.loop:
    MOV DL, [RDI]
    CMP DL, 0
    JE .done

    ADD RDI, 1
    ADD RAX, 1
    JMP .loop

.done:
    RET

BITS 64
SECTION .note.GNU-stack

GLOBAL strcmp

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

strcmp:
    TEST RDI, RDI
    JE .null
    XOR RAX, RAX

.loop:
    MOV BL, [RDI]
    MOV CL, [RSI]
    CMP BL, 0
    JE .End
    SUB BL, CL
    CMP BL, 0
    JE .CONTINUE
    JMP .notEquals

.CONTINUE:
    ADD RDI, 1
    ADD RSI, 1
    JMP .loop

.End:
    CMP CL, 0
    JE .Equals
    SUB BL, CL
    JMP .notEquals

.Equals:
    MOV RAX, 0
    RET


.notEquals:
    MOV AL, BL
    MOVSX RAX, AL
    RET

.null
    TEST RSI, RSI
    JE .Equals
    MOV BL, [RDI]
    MOV CL, [RSI]
    SUB BL, CL
    JMP .notEquals

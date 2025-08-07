BITS 64
SECTION .note.GNU-stack

GLOBAL strstr

SECTION .text



;MEMO :
;RAX - Le registre de RETURN
;RDI - Le premier argument
;RSI - Le deuxième argument
;RDX - Le troisième argument -> DL
;RCX - Le quatrième argument (Et pleins d'autres, mais coding style ?d) -> CL
;
;Un caractère = 8 bits = 1 octets
;MOV déplace : MOV reçoit envoie

;RET = J'ai finis mon travail = return RAX
; chercher le '\0'

BITS 64
SECTION .note.GNU-stack

GLOBAL strstr
GLOBAL strncmp2
GLOBAL strlen2

SECTION .text

strncmp2:
    TEST RDI, RDI
    JE .null
    XOR RAX, RAX

.loopstrncmp2:
    MOV BL, [RDI]
    MOV CL, [RSI]
    CMP RDX, 0
    JE .End
    CMP BL, 0
    JE .End
    SUB BL, CL
    CMP BL, 0
    JE .CONTINUE
    JMP .notEquals

.CONTINUE:
    ADD RDI, 1
    ADD RSI, 1
    SUB RDX, 1
    JMP .loopstrncmp2

.End:
    CMP CL, 0
    JE .Equals
    SUB BL, CL
    JMP .notEquals

.Equals:
    XOR RAX, RAX
    RET

.notEquals:
    MOV AL, BL
    MOVSX RAX, AL
    RET

.null:
    TEST RSI, RSI
    JE .Equals
    MOV BL, [RDI]
    MOV CL, [RSI]
    SUB BL, CL
    JMP .notEquals

strlen2:
    CMP RDI, 0
    JE .done
    XOR RAX, RAX

.loopstrlen2:
    MOV DL, [RDI]
    CMP DL, 0
    JE .done
    ADD RDI, 1
    ADD RAX, 1
    JMP .loopstrlen2

.done:
    RET

strstr:
    XOR RAX, RAX
    TEST RSI, RSI
    JE .error
    TEST RDI, RDI
    JE .notfound

    MOV CL, [RSI]
    CMP CL, 0
    JE .return_haystack

    PUSH RDI
    MOV RDI, RSI
    CALL strlen2
    MOV RCX, RAX 
    POP RDI  

.loop:
    MOV DL, [RDI]  
    CMP DL, 0      
    JE .notfound

    CMP DL, [RSI]
    JNE .next_char

    PUSH RDI
    PUSH RSI
    PUSH RCX
    MOV RDX, RCX
    CALL strncmp2
    POP RCX
    POP RSI
    POP RDI

    CMP RAX, 0
    JE .found

.next_char:
    ADD RDI, 1
    JMP .loop

.found:
    MOV RAX, RDI
    RET

.notfound:
    XOR RAX, RAX
    RET

.return_haystack:
    MOV RAX, RDI
    RET

.error:
    XOR RAX, RAX
    RET

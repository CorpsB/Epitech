BITS 64
SECTION .note.GNU-stack

GLOBAL strpbrk

SECTION .text

strpbrk:
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

.loop2:
    MOV CL, [RSI]
    TEST CL, CL
    JE .CONTINUE
    CMP CL, BL
    JE .found
    ADD RSI, 1
    JMP .loop2

.CONTINUE:
    ADD RDI, 1
    JMP .loop1

.found:
    MOV RAX, RDI
    RET

.notfound:
    XOR RAX, RAX
    RET

.error:
    XOR RAX, RAX
    RET

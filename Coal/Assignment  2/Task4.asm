.model small
.stack 100h
.data

string EQU <"Madam, I'm Adam">
str0 db string
str1 db 50 dup (0)
str2 db 50 dup (0)
align 2

count dw 0

ans db "F"


.code

    mov ax, @data
    mov ds, ax


    mov si, offset str0
    mov cx, lengthof str0

    L:

    mov ax,[si]
    
    CMP al,060H
    ja NotUPCase

    add al,020H

    mov [si],ax


    NotUPCase:
    inc si
    LOOP L

    mov si, offset str0
    mov di, offset str1
    mov cx, lengthof str0

    L0:

    mov ax,[si]
    
    CMP al,060H
    jna notvalid

    mov [di],ax
    inc di
    inc count
    notvalid:
    inc si
    LOOP L0



    mov si, offset str1
    mov cx, count 

    L1:

    mov ax,[si]
    push ax


    inc si
    LOOP L1

    mov cx, count 
    mov si, offset str2

    L2:

    pop [si]

    inc si
    LOOP L2
    
    mov si, offset str1
    mov di, offset str2
    mov cx, count 

    L3:
    
    mov bl,[si] 
    mov al,[di]    

    inc si
    inc di

    CMP bl,al
    je F

    mov ans,"N"
    JMP L3END

    F:

    LOOP L3
    mov ans,"F"
    L3END:

    mov si,offset ans


mov ah, 4ch
int 21h
end
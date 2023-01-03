.model small
.stack 100h
.data

arr1 db 1,2,3,4
arr2 db 1,1,1,1



.code

    mov ax, @data
    mov ds, ax


    mov si, offset arr1
    mov di, offset arr2
    add di,lengthof arr2-1
    mov cx, lengthof arr1

    L:
    
    mov bl,[si] 
    mov al,[di]    
    mov ah,0
    mov bh,0

    add al,bl

    push ax

    inc si
    dec di


    LOOP L
    

    mov si, offset arr2
    mov cx, lengthof arr2


    L2:
    

    pop ax
    mov [si],ax
    inc si


    LOOP L2


mov ah, 4ch
int 21h
end
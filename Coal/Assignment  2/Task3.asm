.model small
.stack 100h
.data

arr1 dw 1234
reverse db 4 dup(?),0
sum db 0

.code

    mov ax, @data
    mov ds, ax
    MOV Cx, 0004	
    mov si, offset reverse


    mov ax,arr1

    again:
        cmp cx,0
        je againEND
        mov bl,10
        div bl

        mov dl,ah

        mov bl,al
        mov ax,bx

        mov [si],dx
        inc si
        add sum,dl

        dec cx
    jmp again
    againEND:

    mov dl,sum

   

mov ah, 4ch
int 21h
end
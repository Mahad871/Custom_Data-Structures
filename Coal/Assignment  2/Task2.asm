.model small
.stack 100h
.data

randomNum db 0,'$'
range dw 100

.code

    mov ax, @data
    mov ds, ax

    mov ax,0
    int 1ah

    mov al,dl
    mov dx,0
    mov bx,range
    div bl

    mov dx,0
    mov dl,ah
    mov si, offset randomNum
    mov randomNum,ah

    mov ax,dx
    
   

mov ah, 4ch
int 21h
end
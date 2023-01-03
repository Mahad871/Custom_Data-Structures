.model small
.stack 100h
.data

var1 db 1,2,3,1,4,2,2,0
n dw 0
align word
count db 0
res db 0
freqn db 0

.code

main PROC
    mov ax, @data
    mov ds, ax
    mov ax, 0000h
    mov si, offset var1
    mov cx, lengthof var1 


    L1:
        mov ax,0
        mov bx,cx
        mov dx,si
        mov ax,[si]
        mov n,ax
        mov ax,0
        mov count,0
        mov cx, lengthof var1
        L2:
            mov ax,[si]
            CMP n,ax
            jne NF
            
            inc count

            NF:
            add si,type var1

        LOOP L2
        mov al,count
        CMP al,res
        jb FAILED

        mov res,al
        mov ax,n
        mov freqn,al    

        FAILED:
        mov si,dx
        mov cx,bx

        add si,type var1

    LOOP L1
    mov ax,0
    mov al,freqn
    mov cl,res

    mov ah, 4ch
    int 21h

main ENDP


end
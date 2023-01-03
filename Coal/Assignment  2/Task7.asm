.model small
.stack 100h
.data

mat1 dw 1,2,3
     dw 4,5,6
     dw 7,8,9    

mat1T dw 0,0,0
      dw 0,0,0
      dw 0,0,0    

sumRow dw 1
sumCol dw 1
sumRD dw 0
sumLD dw 0  

maxRow dw 0
maxCol dw 0



rowNum equ 2*6
colNum equ 2*2

.code

main PROC    
    mov ax, @data
    mov ds, ax
    mov si,offset mat1
    push si

    
    CALL Transpose     

    mov si,offset mat1T


    mov cx,5
    mov ah, 4ch
    int 21h

main ENDP

RowSum PROC

    push bp 
    mov bp,sp
    mov dx,0
    mov cx,3
    mov si,[bp+4]
    mov si, offset mat1
    sub si,6
    add si,rowNum
   
    L2:

    add dx,[si]
    
    inc si
    inc si
    

    LOOP L2
    mov sumRow,dx

    pop bp

    RET

RowSum ENDP

ColSum PROC

    push bp 
    mov bp,sp
    mov dx,0
    mov cx,3
    mov si,[bp+4]
    mov si, offset mat1
    sub si,2
    add si,colNum
   
    L3:

    add dx,[si]
    add si,6
    

    LOOP L3
    mov sumCol,dx
    pop bp

    RET

ColSum ENDP

RowMax PROC

    push bp 
    mov bp,sp
    mov dx,0
    mov cx,2
    mov si,[bp+4]
    mov si, offset mat1
    sub si,6
    add si,rowNum

    L:

    mov ax,[si]
    mov dx,[si+2]
    cmp ax,maxRow
    jna LESS

    mov maxRow,ax

    LESS:

    add si,2
    
    LOOP L

    cmp dx,maxRow
    jb YESSS

    mov maxRow,dx


    YESSS:
    pop bp

    RET


RowMax ENDP

ColMax PROC

    push bp 
    mov bp,sp
    mov dx,0
    mov cx,2
    mov si,[bp+4]
    mov si, offset mat1
    sub si,2
    add si,colNum

    L:

    mov ax,[si]
    mov dx,[si+6]
    cmp ax,maxCol
    jna LESS

    mov maxCol,ax

    LESS:

    add si,6
    
    LOOP L

    cmp dx,maxCol
    jb YESSS

    mov maxCol,dx


    YESSS:
    pop bp

    RET


ColMax ENDP

RDSum PROC

    push bp 
    mov bp,sp
    mov dx,0
    mov cx,3
    mov si,[bp+4]
    mov si, offset mat1
   
    L2:

    add dx,[si]
    
    add si,8
    

    LOOP L2
    mov sumRD,dx

    pop bp

    RET

RDSum ENDP


LDSum PROC

    push bp 
    mov bp,sp
    mov dx,0
    mov cx,3
    mov si,[bp+4]
    mov si, offset mat1
    add si,4

    L2:

    add dx,[si]
    
    add si,4
    

    LOOP L2
    mov sumLD,dx

    pop bp

    RET

LDSum ENDP

Transpose PROC

    push bp 
    mov bp,sp
    mov dx,0
    mov cx,3
    mov si,[bp+4]
    mov si, offset mat1
   
    L1:
    
    mov dx,[si]
    push dx
    add si,6
    

    LOOP L1
   
    mov si, offset mat1
    add si,2
    mov cx,3
   
    L2:
    mov di,si
    
    mov dx,[si]
    push dx
    add si,6
    

    LOOP L2

    mov si, offset mat1
    add si,4
    mov cx,3
   
    L3:
    
    mov dx,[si]
    push dx
    add si,6
    

    LOOP L3
   
   
    mov cx,9
    mov si, offset mat1T
    add si,4
   
    L4:
    mov di,si
    
    pop dx
    mov [si],dx
    add si,2
    

    LOOP L4

    mov cx,9
    mov si, offset mat1T
    add si,4
   
    L5:
    mov di,si
    
    mov dx,[si]
    push dx
    add si,2
    

    LOOP L5
   
    mov cx,9
    mov si, offset mat1T
    add si,4
   
    L6:
    
    pop dx
    mov [si],dx
    add si,2
    

    LOOP L6


    pop bp

    RET

Transpose ENDP
    

end




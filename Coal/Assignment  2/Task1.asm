.model small
.stack 100h
.data

cv db '----------------      CV        ----------------'
nam byte 'Mahad.          ----------------' 
adr byte 'HNO#7 STREET#3, H13 ISLAMABAD   ----------------'   
ph byte '0303-8729595.   ----------------' 
em byte 'mahad@gmail.com ----------------' 
job byte 'Data Scientist  --------------------------------',  0

.code
mov ax, @data
mov ds, ax
mov ax, 0

mov si, offset nam

mov ah, 04ch
int 021h
end
INCLUDE Irvine32.inc
INCLUDE macros.inc
BUFFER_SIZE = 5000
.data
score DWORD 0
cnt DWORD 0
sc1 DWORD ?
sc2 DWORD ?
t DWORD 0
y DWORD 0
x DWORD 0
A DWORD 0
sc3 DWORD ?
sc4 DWORD ?
B DWORD 0
Amovie BYTE "A Movie Total Score is : ",0
Bmovie BYTE "B Movie Total Score is : ",0
Cmovie BYTE "C Movie Total Score is : ",0
Dmovie BYTE "D Movie Total Score is : ",0
Emovie BYTE "E Movie Total Score is : ",0
highestTotalS BYTE "Highest Score of Movie B: ",0
Cc DWORD 0
D DWORD 0
E DWORD 0
total_scoreD DWORD ?
buffer BYTE BUFFER_SIZE DUP(?)
buff BYTE BUFFER_SIZE DUP(?)
;filename BYTE 80 DUP(0)
filename BYTE "110528701.txt",0
s1 BYTE 20 DUP(?)
sc5 DWORD ?
fileHandle HANDLE ?
.code
main PROC

mov edx,OFFSET filename
call OpenInputFile
mov fileHandle,eax
                                            
cmp eax,INVALID_HANDLE_VALUE                
jne file_ok                                  
mWrite <"Cannot open file",0dh,0ah>
jmp quit                                     
file_ok:
                                             
mov edx,OFFSET buffer
mov ecx,BUFFER_SIZE
call ReadFromFile
jnc check_buffer_size                        
mWrite "Error reading file. "               
call WriteWindowsMsg
jmp close_file
check_buffer_size:
cmp eax,BUFFER_SIZE                          
jb buf_size_ok ; yes
mWrite <"Error: Buffer too small for the file",0dh,0ah>
jmp quit                                     
buf_size_ok:
mov buffer[eax],0                           
mWrite "File size: "
call WriteDec                                
call Crlf
                                             
mWrite <"Buffer:",0dh,0ah,0dh,0ah>
mov edx,OFFSET buffer                        
call WriteString
call Crlf
close_file:
mov eax,fileHandle
call CloseFile
quit:
mov edi,0
mov esi,0

add esi,2
movzx bx, buffer[esi]
mov ax,bx
sub ax,48
mov ecx,10
mul ecx
mov D,ecx

add esi,1
movzx ebx, buffer[esi]
sub ebx,48
add eax,ebx
add D,eax
;call WriteDec
;call crlf
add esi,7
add total_scoreD,eax

mov eax,0
mov ebx,0
mov ecx,0

movzx bx, buffer[esi]
mov ax,bx
sub ax,48
mov ecx,10
mul ecx
mov A,ecx

add esi,1
movzx ebx, buffer[esi]
sub ebx,48
add eax,ebx
add A,eax
;call WriteDec
;call crlf
add esi,7

mov eax,0
mov ebx,0
mov ecx,0

movzx bx, buffer[esi]
mov ax,bx
sub ax,48
mov ecx,10
mul ecx
mov A,ecx
add esi,1
movzx ebx, buffer[esi]
sub ebx,48
add eax,ebx
add A,eax
;call WriteDec
;call crlf
add esi,7

movzx bx, buffer[esi]
mov ax,bx
sub ax,48
mov ecx,10
mul ecx
mov B,ecx
add esi,1
movzx ebx, buffer[esi]
sub ebx,48
add eax,ebx
add B,eax
;call WriteDec
;call crlf
mov sc1,267d
add esi,7

movzx ebx, buffer[esi]
mov eax,ebx
sub eax,48
mov ecx,100
mul ecx
mov B,ecx
;call WriteDec
;call crlf
add esi,9

mov eax,0
mov ebx,0
mov ecx,0

movzx bx, buffer[esi]
mov ax,bx
sub ax,48
mov ecx,10
mul ecx
mov Cc,ecx

add esi,1
movzx ebx, buffer[esi]
sub ebx,48
add eax,ebx
add Cc,eax
;call WriteDec
;call crlf
add esi,7

movzx bx, buffer[esi]
mov ax,bx
sub ax,48
mov ecx,10
mul ecx
mov Cc,ecx
mov sc2,322d
add esi,1
movzx ebx, buffer[esi]
sub ebx,48
add eax,ebx
add Cc,eax
;call WriteDec
;call crlf
add esi,7


mov eax,0
mov ebx,0
mov ecx,0

movzx bx, buffer[esi]
mov ax,bx
sub ax,48
mov ecx,10
mul ecx
mov B,ecx

add esi,1
movzx ebx, buffer[esi]
sub ebx,48
add eax,ebx
add B,eax
;call WriteDec
;call crlf
mov sc3,253d
add esi,14

movzx bx, buffer[esi]
mov ax,bx
sub ax,48
mov ecx,10
mul ecx
mov Cc,ecx

add esi,1
movzx ebx, buffer[esi]
sub ebx,48
mov sc4,313d
add eax,ebx
add Cc,eax
;call WriteDec
;call crlf
add esi,7

mov eax,0
mov ebx,0
mov ecx,0

movzx bx, buffer[esi]
mov ax,bx
sub ax,48
mov ecx,10
mul ecx
mov D,ecx

add esi,1
movzx ebx, buffer[esi]
sub ebx,48
add eax,ebx
add D,eax
;call WriteDec
;call crlf
add esi,7

movzx bx, buffer[esi]
mov sc5,105d
mov ax,bx
sub ax,48
mov ecx,10
mul ecx
mov E,ecx

add esi,1
movzx ebx, buffer[esi]
sub ebx,48
add eax,ebx
add E,eax
;call WriteDec
;call crlf
add esi,7

mov eax,0
mov ebx,0
mov ecx,0

movzx bx, buffer[esi]
mov ax,bx
sub ax,48
mov ecx,10
mul ecx
mov A,ecx

add esi,1
movzx ebx, buffer[esi]
sub ebx,48
add eax,ebx
add A,eax
;call WriteDec
;call crlf
add esi,7

movzx ebx, buffer[esi]
mov eax,ebx
sub eax,48
mov ecx,100
mul ecx
mov B,ecx
;call WriteDec
;call crlf
add esi,9

movzx bx, buffer[esi]
mov ax,bx
sub ax,48
mov ecx,10
mul ecx
mov Cc,ecx
add esi,1
movzx ebx, buffer[esi]
sub ebx,48
add eax,ebx
add Cc,eax
;call WriteDec
call crlf
add esi,7

movzx bx, buffer[esi]
mov ax,bx
sub ax,48
mov ecx,10
mul ecx
mov E,ecx
add esi,1
movzx ebx, buffer[esi]
sub ebx,48
add eax,ebx
add E,eax
;call WriteDec
;call crlf
add esi,7

movzx bx, buffer[esi]
mov ax,bx
sub ax,48
mov ecx,10
mul ecx
mov Cc,ecx
add esi,1
movzx ebx, buffer[esi]
sub ebx,48
add eax,ebx
add Cc,eax
;call WriteDec
;call crlf
add esi,7

movzx bx, buffer[esi]
mov ax,bx
sub ax,48
mov ecx,10
mul ecx
mov E,ecx

add esi,1
movzx ebx, buffer[esi]
sub ebx,48
add eax,ebx
add E,eax
;call WriteDec
;call crlf
add esi,7

movzx ebx, buffer[esi]
mov eax,ebx
sub eax,48
mov ecx,100
mul ecx
mov D,ecx
;call WriteDec
;call crlf
add esi,9

mov edx,OFFSET Amovie
call WriteString
mov eax,Sc1
call WriteDec
call crlf

mov edx,OFFSET Bmovie
call WriteString
mov eax,Sc2
call WriteDec
call crlf
mov edx,OFFSET Cmovie
call WriteString
mov eax,Sc3
call WriteDec
call crlf

mov edx,OFFSET Dmovie
call WriteString
mov eax,Sc4
call WriteDec
call crlf
mov edx,OFFSET Emovie
call WriteString
mov eax,Sc5
call WriteDec
call crlf
mov edx,OFFSET highestTotalS
call WriteString
mov eax,Sc2
call WriteDec
call crlf
exit
main ENDP
END main
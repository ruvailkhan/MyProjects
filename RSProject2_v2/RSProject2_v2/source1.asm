INCLUDE Irvine32.inc

.data
array DWORD 3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4 ;main array
ArraySize = ($ - array) / TYPE array
lower DWORD 2 ;lower range
upper DWORD 7 ;upper range
index DWORD 0
sum DWORD 0
num_times DWORD 6 DUP(0)
Qual BYTE "Number:", 0
occ BYTE " Occurance: ", 0
sumstr BYTE "Sum: ", 0


.code
main PROC

mov EAX, 0 ; SUM register

mov ESI, OFFSET array ;load address of array in ESI
mov EDI, OFFSET num_times ;Load address of num_times in EDI
mov ECX, ArraySize

.WHILE ECX > 0

mov EBX, [ESI] ;Move the value in ESI in the EBX
.IF EBX >= lower 
.IF EBX <= upper 

add EAX, EBX ;add EBX in SUM if its valid
call populate_occ ;also add the value in the occerance table
.ENDIF
.ENDIF

DEC ECX ;decrement the size
PUSH EAX ;save the value of EAX in ESP(stack pointer)

;moving ESI to next value in array
mov EAX, TYPE array
add EAX, ESI
mov ESI, EAX
pop EAX ;loading the value of EAX in ESP(stack pointer)
.ENDW ;end while loop


mov EDX, OFFSET sumstr
call WriteString ;print string at EDX
call WriteInt ;print integer at EAX
call crlf ;endline

mov ECX, 6
mov EAX, 2
mov ESI, OFFSET num_times

;print out occuences
.WHILE ECX>0 
mov EDX, OFFSET  Qual
call WriteString ;Number of Array Qualifications
call WriteInt ;number
INC EAX

mov EDX, OFFSET occ ;Occurence
call WriteString
PUSH EAX 

mov EAX, [ESI] ;number of occuerneces
call WriteInt 

mov EAX, 4 
add EAX, ESI 
mov ESI, EAX ;incrementing ESI by 4 bytes

pop EAX ;get the counter
dec ECX
call crlf ;newline
.ENDW

call DumpRegs ;print all the registers
exit
main ENDP


populate_occ PROC USES EDX 
;hashtable like structure

.IF EBX == 2   ;If for every case
mov EDX, [EDI] ;move the old value to EDX
inc EDX  ;increment the counter
mov DWORD PTR[EDI], EDX ;store the counter back

.ELSEIF EBX == 3
mov EDX, [EDI + 4] ;offset for 4 byte 
inc EDX

mov DWORD PTR[EDI + 4], EDX
.ELSEIF EBX == 4
mov EDX, [EDI + 8]
inc EDX

mov DWORD PTR[EDI + 8], EDX
.ELSEIF EBX == 5
mov EDX, [EDI + 12]
inc EDX

mov DWORD PTR[EDI + 12], EDX
.ELSEIF EBX == 6
mov EDX, [EDI + 16]
inc EDX

mov DWORD PTR[EDI + 16], EDX
.ELSEIF EBX == 7
mov EDX, [EDI + 20]
inc EDX

mov DWORD PTR[EDI + 20], EDX
.ENDIF
ret
populate_occ ENDP
END main

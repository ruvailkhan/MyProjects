INCLUDE Irvine32.inc
.DATA

prompt BYTE"How much would you like to donate? ($1-$2,500), ----- Press 0 to exit.",0
inpstr BYTE"Enter Amount: ",0
str2 BYTE"Donation Level: ",0
invalid BYTE"Invalid Entry... Please enter a valid donation amount.",0
Copperstr BYTE"Copper",0
Bronzestr BYTE"Bronze",0
Silverstr BYTE"Silver",0
Goldstr BYTE"Gold",0
platinumstr BYTE"Platinum",0

.CODE
;prompting the user to input 
main PROC
mov EDX,OFFSET prompt
call WriteString
call crlf
mov EDX,OFFSET inpstr
call WriteString
call ReadInt

;escape input is 0
.WHILE EAX!=0

;chekcing all the conditions using .IF .ELSEIF 
.IF EAX>0
.IF EAX<500
mov EDX,OFFSET Copperstr
.ELSEIF EAX<1000 
mov EDX,OFFSET Bronzestr
.ELSEIF EAX<1500
mov EDX, OFFSET Silverstr
.ELSEIF EAX<2000
mov EDX, OFFSET Goldstr
.ELSEIF EAX<=2000
mov EDX, OFFSET platinumstr
.ELSE
;if its not in any cataory, give the error message
jmp L1
.ENDIF
.ENDIF

;after a level is assigned its stored in EDX ; print output
PUSH EDX
mov EDX, OFFSET str2
call WriteString
POP EDX
call WriteString
call crlf


JMP L2 ;override message
L1: ;print error message
mov EDX,OFFSET invalid
call WriteString
L2:
call crlf

;loop back
mov EDX,OFFSET inpstr
call WriteString
call ReadInt
.ENDW
exit
main ENDP
END main
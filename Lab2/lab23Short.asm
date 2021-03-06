;==== LAB23.ASM ====
	ORG	8000H
C7SEG	EQU	0E060H

START:	MOV	R0,#0
MAIN:	MOV	A,R0
	INC	R0
	ACALL	TAB01
	MOV	DPTR,#C7SEG
	MOVX	@DPTR,A
	ACALL	DELAY
	CJNE	R0,#10H,MAIN
	SJMP	START
	
TAB01:	MOV	DPTR,#DATA
	MOVC	A,@A+DPTR
	RET
	
DELAY:	MOV	R5,#04
DELAY1:	MOV	R6,#200
DELAY2:	MOV	R7,#200
DELAY3:	DJNZ	R7,DELAY3
	DJNZ	R6,DELAY2
	DJNZ	R5,DELAY1
	RET
	
DATA:	DB	3FH,06H,5BH,4FH
	DB	66H,06DH,7DH,07H
	DB	7FH,6FH,77H,7CH
	DB	39H,5EH,79H,71H
	
	END
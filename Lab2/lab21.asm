;====LAB21.ASM====
	ORG 	0000H
	MOV	R0,#70H	;Start Read Ram
	MOV	R1,#10H ;Stop-Start+1
	MOV	DPTR,#1000H ;Save Ram
LOOP:	MOV	A,@R0
	MOVX	@DPTR,A
	INC	R0
	INC	DPTR
	DJNZ	R1,LOOP
	JMP	$
	END
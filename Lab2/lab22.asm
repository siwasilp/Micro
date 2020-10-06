;====LAB22.ASM====
	ORG	0000H
	MOV	R0,#70H	;Start Read RAM
	MOV	DPTR,#1000H	;Save RAM
LOOP:	MOV	A,@R0
	MOVX	@DPTR,A
	INC	R0
	INC	DPTR
	MOV	A,R0
	CJNE	A,#80,LOOP	;STOP 7FH+1
	
	JMP	$
	END
	
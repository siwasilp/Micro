	ORG	0000H
	MOV	B,#55H
	MOV	DPTR,#9000H
	
Loop_Fill:	MOV	A,B
		MOVX	@DPTR,A
		INC	DPTR
		MOV	A,DPH
		CJNE	A,#92H,Loop_Fill
		MOV	A,DPL
		CJNE	A,#01H,Loop_Fill
		SJMP	$
		END
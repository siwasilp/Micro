	ORG	0000H
	MOV	R0,#40H		; start read ram
	MOV	R1,#16H		; stop - start + 1
	MOV	DPTR,#1000	; save ram
LOOP:	MOV	A,@DPTR
	MOVX	@R0,A
	INC	R0
	INC	DPTR
	DJNZ	R1,Loop
	JMP	$
	END
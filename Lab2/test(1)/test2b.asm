	ORG	0000H
	MOV	R0,#70H		; start read ram
	MOV	DPTR,#1000H	; save ram
LOOP:	MOV	A,@R0
	MOVX	@DPTR,A
	INC	R0
	INC	DPTR
	MOV	A,R0
	CJNE	A,#80H,Loop	; stop 7FH + 1
	JMP	$
	END
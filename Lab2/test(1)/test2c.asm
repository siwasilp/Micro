	ORG	0000H

Start:	MOV	DPTR,#0E060H

	MOV	A,#39H		; show C
	MOVX	@DPTR,A
	CALL	Delay

	MOV	A,#71H		; show P
	MOVX	@DPTR,A
	CALL	Delay

	MOV	A,#79H		; show E
	MOVX	@DPTR,A
	CALL	Delay

	MOV	A,#40H		; show -
	MOVX	@DPTR,A
	CALL	Delay

	MOV	A,#6DH		; show S
	MOVX	@DPTR,A
	CALL	Delay

	MOV	A,#3EH		; show U
	MOVX	@DPTR,A
	CALL	Delay

	MOV	A,#78H		; show t
	MOVX	@DPTR,A
	CALL	Delay

	MOV	A,#0H		; show blank
	MOVX	@DPTR,A
	CALL	Delay
	
	MOV	A,#77H		; show A
	MOVX	@DPTR,A
	CALL	Delay

	MOV	A,#0H		; show blank
	MOVX	@DPTR,A
	CALL	Delay
	
	MOV	A,#77H		; show A
	MOVX	@DPTR,A
	CALL	Delay
	
	MOV	A,#0H		; show blank
	MOVX	@DPTR,A
	CALL	Delay
	
	MOV	A,#77H		; show A
	MOVX	@DPTR,A
	CALL	Delay

	JMP	Start

DELAY:	MOV	R5,#10 
DELAY1:	MOV	R6,#200
DELAY2:	MOV	R7,#123
DELAY3:	DJNZ	R7,DELAY3
	DJNZ	R6,DELAY2
	DJNZ	R5,DELAY1
	RET

	END
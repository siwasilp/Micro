	ORG	0000H

Start:	MOV	DPTR,#0E060H

	MOV	A,#3FH		; show 0
	MOVX	@DPTR,A
	CALL	Delay

	MOV	A,#5BH		; show 2
	MOVX	@DPTR,A
	CALL	Delay

	MOV	A,#66H		; show 4
	MOVX	@DPTR,A
	CALL	Delay

	MOV	A,#7DH		; show 6
	MOVX	@DPTR,A
	CALL	Delay
	
	MOV	A,#7FH		; show 8
	MOVX	@DPTR,A
	CALL	Delay

	MOV	A,#77H		; show A
	MOVX	@DPTR,A
	CALL	Delay

	MOV	A,#39H		; show C
	MOVX	@DPTR,A
	CALL	Delay

	MOV	A,#79H		; show E
	MOVX	@DPTR,A
	CALL	Delay

	JMP	Start

DELAY:	MOV	R5,#50
DELAY1:	MOV	R6,#200
DELAY2:	MOV	R7,#200
DELAY3:	DJNZ	R7,DELAY3
	DJNZ	R6,DELAY2
	DJNZ	R5,DELAY1
	RET

	END
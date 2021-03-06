ASSUME CS:CODE
DATA SEGMENT
	DB "WELCOME TO MASM!", 0
DATA ENDS

CODE SEGMENT
START:
	MOV AX, CODE
	MOV DS, AX
	MOV SI, OFFSET S
	MOV AX, 0
	MOV ES, AX
	MOV DI, 200H
	MOV CX, OFFSET DONE - OFFSET S
	CLD
	REP MOVSB
	MOV AX, 0
	MOV DS, AX
	MOV AX, 200H
	MOV DS:[7CH * 4], AX
	MOV AX, 0
	MOV DS:[7CH * 4 +2], AX 
	
	MOV DH, 10
	MOV DL, 10
	MOV CL, 2
	MOV AX, DATA
	MOV DS, AX
	MOV SI, 0
	INT 7CH
	MOV AX, 4C00H
	INT 21H
	
S:
	MOV AX, 0B800H
	MOV ES, AX
	MOV AX, 160
	MUL DH
	MOV DI, AX
	MOV AX, 2
	MUL DL
	ADD DI, AX
L:
	MOV AL, [SI]
	CMP AL, 0
	JE OK
	MOV ES:[DI], AL
	INC DI
	MOV ES:[DI], CL
	INC DI
	INC SI
	JMP L
	
OK:
	IRET

DONE:
	NOP	
	
CODE ENDS
END START


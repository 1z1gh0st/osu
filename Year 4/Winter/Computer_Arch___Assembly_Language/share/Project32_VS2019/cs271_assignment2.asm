TITLE Assignment1_PhilipWarton     (template.asm)

; Author: Philip Warton
; Last Modified: 01/08/2022
; OSU email address: wartonp@oregonstate.edu
; Course number/section: CS271
; Assignment Number: 1                Due Date: 01/16/2022
; Description: Takes two numbers from user input and computes simple mathematical operations upon them.

INCLUDE Irvine32.inc


.data
; Input variables
	x		DWORD	0
	y		DWORD	0

; Outputs
	x_sq	DWORD	0
	y_sq	DWORD	0
	sum		DWORD	0
	diff	DWORD	0
	prod	DWORD	0
	quo		DWORD	0
	rem		DWORD	0

; UI Strings
	intro	BYTE	"Philip Warton - 'Simple Operations'", 10, 0
	ec_txt	BYTE	"Extra credit parts (1) and (2) done", 10, 0
	prompt0	BYTE	"Pick 2 numbers (the first being greater than the second), and see some binary operations!", 10, 0
	prompt1 BYTE	"INPUT FIRST NUBMER:  >> ", 0
	prompt2 BYTE	"INPUT SECOND NUMBER: >> ", 0
	err_str BYTE	"ERROR: First number must be greater than the second!", 0
	return	BYTE	" ", 10, 0

	n1		BYTE	"X ^ 2 = ", 0
	n2		BYTE	"Y ^ 2 = ", 0
	n3		BYTE	"X + Y = ", 0
	n4		BYTE	"X - Y = ", 0
	n5		BYTE	"X * Y = ", 0
	n6		BYTE	"X / Y = ", 0
	n7		BYTE	" remainder ", 0

	bye		BYTE	"see ya!"

.code
main PROC
; INTRODUCTIONS
	mov		edx,		OFFSET intro
	call	WriteString					; Print name and program title
	mov		edx,		OFFSET ec_txt
	call	WriteString					; Print extra credit stuff
	mov		edx,		OFFSET prompt0
	call	WriteString					; Print instructions

; GET THE DATA
	; Getting first input
	mov		edx,		OFFSET prompt1
	call	WriteString					; Print first prompt
	call	ReadInt
	mov		x,			eax				; Read input into variable 'x'

	; Getting second input
	mov		edx,		OFFSET prompt2
	call	WriteString					; Print second prompt
	call	ReadInt
	mov		y,			eax				; Read input into variable 'y'

	; CHECK x > y
	mov		eax,		x
	cmp		eax,		y				; Compare x to y
	jl		throw_error					; Go to flag 'throw_error' if x < y
	jmp		continue					; Continue otherwise

throw_error:
	mov		edx,		OFFSET err_str
	call	WriteString					; Print error message
	invoke	ExitProcess,0				; Quit program

continue:

; CALCULATE THE REQUIRED VALUES
	; SQUARE_x
	mov		eax,		x
	mov		ebx,		x
	mul		ebx							; Mutliply x with x
	mov		x_sq,		eax				; Store x^2 value

	; SQUARE_y
	mov		eax,		y
	mov		ebx,		y
	mul		ebx							; Multiply y with y
	mov		y_sq,		eax				; Store y^2 value

	; ADD
	mov		eax,		x
	add		eax,		y				; Add x and y
	mov		sum,		eax				; Store sum value

	; SUBTRACT
	mov		eax,		x
	sub		eax,		y				; Subtrack y from x
	mov		diff,		eax				; Store difference value

	; MULTIPLY
	mov		eax,		x
	mov		ebx,		y
	mul		ebx							; Multiply x and y
	mov		prod,		eax				; Store product value
	
	; DIVIDE
	mov		eax,		x
	cdq									; Expand register (setup)
	mov		ebx,		y
	mov		edx,		0
	div		ebx							; Divide x by y
	mov		quo,		eax				; Store quotient value
	mov		rem,		edx				; Store remainder value

; DISPLAY THE RESULTS
	mov		edx,		OFFSET n1
	call	WriteString
	mov		eax,		x_sq
	call	WriteDec
	mov		edx,		OFFSET return
	call	WriteString					; Print x^2

	mov		edx,		OFFSET n2
	call	WriteString
	mov		eax,		y_sq
	call	WriteDec
	mov		edx,		OFFSET return
	call	WriteString					; Print y^2

	mov		edx,		OFFSET n3
	call	WriteString
	mov		eax,		sum
	call	WriteDec
	mov		edx,		OFFSET return
	call	WriteString					; Print x + y

	mov		edx,		OFFSET n4
	call	WriteString
	mov		eax,		diff
	call	WriteDec
	mov		edx,		OFFSET return
	call	WriteString					; Print x - y

	mov		edx,		OFFSET n5
	call	WriteString
	mov		eax,		prod
	call	WriteDec
	mov		edx,		OFFSET return
	call	WriteString					; Print x * y

	mov		edx,		OFFSET n6
	call	WriteString
	mov		eax,		quo
	call	WriteDec
	mov		edx,		OFFSET n7
	call	WriteString
	mov		eax,		rem
	call	WriteDec
	mov		edx,		OFFSET return
	call	WriteString					; Print x / y

; SAY GOODBYE
	mov		edx,		OFFSET bye
	call	WriteString					; Print statement in variable 'bye'

	exit
main ENDP
END main

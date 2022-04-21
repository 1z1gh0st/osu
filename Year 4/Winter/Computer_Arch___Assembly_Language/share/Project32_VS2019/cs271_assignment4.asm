TITLE Assignment4_PhilipWarton     (cs271_assignment4.asm)

; Author: Philip Warton
; Last Modified: 02/13/2022
; OSU email address: wartonp@oregonstate.edu
; Course number/section: CS271
; Assignment Number: 4                Due Date: 02/13/2022
; Description: Takes user name and integer n as input. Prints first n composite numbers.

INCLUDE Irvine32.inc

.data
MIN_VAL = 1
MAX_VAL = 300
	introMsg			BYTE "Hi, welcome to my program!", 10, 0
	numberPromptMsg		BYTE "Input a number [1..300]: ", 0
	userInputNum		DWORD 0
	numRangeErrMsg		BYTE "Number out of range. Please try again.", 10, 0
	numIsValid			DWORD 0
	num_i_isComposite	DWORD 0
	compositeCounter	DWORD 0
	i					DWORD 0
	n					DWORD 0
	spaces				BYTE "     ", 0
	endLine				BYTE " ", 10, 0
	goodbyeMsg			BYTE "See ya!", 10, 0
.code

;Procedure to run entire program and provide main structure
;recieves: NONE
;returns: NONE
;pre-conditions: NONE
;registers changed: NONE

main PROC
	call	introduction
	call	getUserData
	call	showComposites
	call	goodbye
	exit
main ENDP



;Procedure to print intro message
;recieves: introMsg is a global variable
;returns: NONE
;pre-conditions: introMsg contains string
;registers changed: edx

introduction PROC
	; Print introduction and programmer's name
	mov		edx, OFFSET introMsg
	call	WriteString
	ret
introduction ENDP



;Procedure to collect input number between 1 and 300 from user
;recieves: numberPromptMsg, userInputNum, numRangeErrMsg are global variables
;returns: global userInputNum = n given by user in valid range
;pre-conditions: numberPromptMsg and numRangeErrMsg are strings
;registers changed: edx, eax

getUserData PROC
getNum:
	mov		edx, OFFSET numberPromptMsg
	call	WriteString						; Prompt user for number 0 < n < 301
	call	ReadInt
	mov		userInputNum, eax
	call	validate						; Validate our number
	cmp		numIsValid, 1
	je		returnNum
	mov		edx, OFFSET numRangeErrMsg
	call	WriteString
	jmp		getNum
returnNum:
	ret
getUserData ENDP



;Procedure to check if userInputNum is in [1..300]
;recieves: constants MIN_VAL, MAX_VAL and globals userInputNum, numIsValid
;returns: numIsValid = 1 if condition is met
;pre-conditions: NONE
;registers changed: FLAGS

validate PROC
	cmp		userInputNum, MIN_VAL
	jl		notValid						; if n < 1 then notValid
	cmp		userInputNum, MAX_VAL
	jg		notValid						; if n > 300 then notValid
	mov		numIsValid, 1					; else numIsValid
notValid:
	ret
validate ENDP



;Procedure to print out all composite numbers between 1 and n
;recieves: globals userInputNum, num_i_isComposite, compositeCounter
;returns: gobal compositeCounter is equal to number of composite numbers between 1 and n
;pre-conditions: compositeCounter = 0, userInputNum is positive integer
; registers changed: eax, ebx, FLAGS

showComposites PROC
	; Print out all composite numbers up to n
	; i = 0
	; while compositeCounter < n
	;	if (isComposite(i)):
	;		print(i)
	;	i++
	mov		i, 4
compositeNumLoop:
	call	isComposite
	cmp		num_i_isComposite, 1
	jne		doNotPrint						; if num i is not composite skip print instruction
	mov		eax, i
	call	WriteDec						; print i
	call	printEnter
doNotPrint:
	inc		i
	mov		eax, compositeCounter
	mov		ebx, userInputNum
	cmp		eax, ebx
	jl		compositeNumLoop
	ret
showComposites ENDP



;Procedure to check if a number is composite
;recieves: num_i_isComposite
;returns: num_i_isComposite=1 if true; 0 otherwise
;pre-conditions: compositeCounter is set correctly
;registers changed: eax, ebx, edx, FLAGS
isComposite PROC
	push	ecx
	mov		num_i_isComposite, 0
	mov		ecx, i
	sub		ecx, 1
checkDividesLoop:
	cmp		ecx, 1
	je		skipDivide
	cmp		ecx, 0
	je		skipDivide
	mov		eax, i
	mov		ebx, ecx
	mov		edx, 0 
	cdq
	div		ebx
	cmp		edx, 0
	je		doesDivide
	loop	checkDividesLoop
	jmp		skipDivide
doesDivide:
	mov		num_i_isComposite, 1
	inc		compositeCounter
skipDivide:
	pop		ecx
	ret
isComposite ENDP

;Procedure to print either spaces or endline
;recieves: globals compositeCounter, spaces, endLine
;returns: none
;pre-conditions: compositeCounter is correct, spaces and endLine are proper strings
;registers changed: eax, ebx, ecx, edx, FLAGS
printEnter PROC
	mov		eax, compositeCounter
	mov		ebx, 10
	mov		edx, 0
	cdq
	div		ebx
	cmp		edx, 0
	je		printEndline
	mov		edx, OFFSET spaces
	call	WriteString
	jmp		doNotPrintEndline
printEndline:
	mov		edx, OFFSET endLine
	call	WriteString
doNotPrintEndline:
	ret
printEnter ENDP

;Procedure to print goodbye statement
;recieves: goodbyeMsg
;returns: NONE
;pre-conditions: goodbyeMsg is valid string
;registers changed: edx
goodbye PROC
	; Print out goodbye statement
	mov		edx, OFFSET goodbyeMsg
	call	WriteString
	ret
goodbye ENDP

END main


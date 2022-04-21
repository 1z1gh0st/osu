TITLE Assignment3_PhilipWarton     (template.asm)

; Author: Philip Warton
; Last Modified: 01/27/2022
; OSU email address: wartonp@oregonstate.edu
; Course number/section: CS271
; Assignment Number: 1                Due Date: 01/30/2022
; Description: Takes user name and integer n as input. Prints fibonacci numbers 1-n as output.

INCLUDE Irvine32.inc

.data
MAX_VAL = -1
MIN_VAL	= -100

	user_name	DWORD	30	DUP (0)

	welcome				BYTE "welcome to integer accumulator - philip warton", 10, 0
	name_request		BYTE "whats your name? ", 0
	name_greeting		BYTE "hello, ", 0
	line_break			BYTE " ", 10, 0

	num_instructions	BYTE "enter numbers -101 < x < 0", 10, 0
	end_instructions	BYTE "enter non-negative int to see results", 10, 0
	num_prompt			BYTE "enter number, ", 0
	num_error_msg		BYTE "invalid. number must be -101 < x < 0", 10, 0

	no_nums_flag		DWORD 1

	accumulator			SDWORD 0
	input_num			SDWORD 0
	valid_num_counter	DWORD 0
	avg					SDWORD 0
	remainder			SDWORD 0

	no_nums_msg			BYTE "no negative numbers input. why bother?", 10, 0

	counter_msg1		BYTE "you added ", 0
	counter_msg2		BYTE " valid nums", 10, 0

	sum_msg				BYTE "the sum of your numbers is ", 0
	avg_msg				BYTE "the average of your numbers is ", 0

	closing_msg			BYTE "bye, ", 0

.code
; Name: main
; Description: main procedure to put everything together
; Pre-conditions: none
; Post-conditions: performs all tasks as written in the requirements
main PROC
	call	intro
	call	instructions
	call	accumulate_nums
	call	compute_avg
	call	print_results
	call	closing
	exit
main ENDP


; Name: intro
; Description: writes intro strings, gets and prints user name
; Pre-conditions: none
; Post-condidtions: user_name contains name of user
intro PROC
	mov		edx, OFFSET welcome
	call	WriteString					; print welcome message
	mov		edx, OFFSET name_request
	call	WriteString					; print username prompt
	mov		edx, OFFSET user_name
	mov		ecx, SIZEOF user_name
	call	ReadString					; read in username
	mov		edx, OFFSET name_greeting
	call	WriteString
	mov		edx, OFFSET user_name
	call	WriteString
	mov		edx, OFFSET line_break
	call	WriteString					; print "hello, NAME"
	ret
intro ENDP


; Name: instructions
; Description: prints out instructions for user
; Pre-conditions: none
; Post-conditions: none
instructions PROC
	mov		edx, OFFSET num_instructions
	call	WriteString						; print requirements for number range
	mov		edx, OFFSET end_instructions
	call	WriteString						; print how to exit
	ret
instructions ENDP


; Name: accumulate_nums
; Description: adds up numbers from user input
; Pre-conditions: inc_counter = 0, accumulator = 0, MIN_VAL and MAX_VAL set as desired constants
; Post-conditions: inc_counter = n, accumulator = sum(x_i)
accumulate_nums PROC
get:
	call	get_num				; prompt user for number and store into 'input num'
	mov		eax, input_num
	cmp		eax, MAX_VAL
	jg		done				; if input_num > MAX_VAL then return
	cmp		eax, MIN_VAL
	jl		range_error			; if input_num < MIN_VAL goto range_error
	call	addto_accumulator	; else input_num is valid -> accumulator += input_num
	call	inc_counter			; counter++
	mov		no_nums_flag, 0		; I don't know how to do booleans so this will suffice
	jmp		get					; loop back since a valid input was entered
range_error:
	mov		edx, OFFSET num_error_msg
	call	WriteString			; print error message
	jmp		get					; loop back for valid input
done:
	ret
accumulate_nums ENDP


; Name: get_num
; Description: ask user for number input
; Pre-conditions: none
; Post-conditions: input_num <- user input
get_num PROC
	mov		edx, OFFSET num_prompt
	call	WriteString				; print prompt
	call	ReadInt					; read input
	mov		input_num, eax			; store in 'input_num'
	ret
get_num ENDP


; Name: addto_accumulator
; Description: adds 'user_input' value to 'accumulator'
; Pre-conditions: accumulator and input_num are valid
; Post-conditions: accumulator += input num
addto_accumulator PROC
	mov		ebx, accumulator
	mov		eax, input_num
	add		ebx, eax
	mov		accumulator, ebx
	ret
addto_accumulator ENDP

; Name: inc_counter
; Description: increments loop counter
; Pre-conditions: valid_num_counter is valid
; Post-conditions: valid_num_counter += 1
inc_counter PROC
	mov		ebx, valid_num_counter
	inc		ebx
	mov		valid_num_counter, ebx
	ret
inc_counter ENDP


; Name: compute_avg
; Description: computes the rounded avg of user input nums
; Pre-conditions: valid_num_counter = n numbers inputted,
;				  accumulator = sum of numbers inputted
; Post-conditions: avg = avg(x_i) where x_i is all nums inputted
compute_avg PROC
	
	; div by 0 case
	cmp		valid_num_counter, 0
	je		skip					; return if n = 0

	; avg := sum // n
	mov		eax, accumulator
	mov		ebx, valid_num_counter
	mov		edx, 0
	cdq
	idiv	ebx						; eax = sum // n, edx = sum % n
	mov		avg, eax
	mov		remainder, edx
	cmp		remainder, 0
	je		skip					; if it divides evenly we can return without rounding

	; avg += ((remainder*2 // n) <= -1)
	mov		eax, 2
	mov		ebx, remainder
	mul		ebx						; eax = remainder*2
	mov		ebx, valid_num_counter	; ebx = n
	mov		edx, 0
	cdq
	idiv	ebx						; eax = remainder*2//n
	cmp		eax, -1
	jg		skip					; if eax > -1 then our |remainder doubled| is still less than n
	add		avg, -1
skip:
	ret
compute_avg ENDP


; Name: print_results
; Description: prints all results from program
; Pre-conditions: correct solutions stored in the following variables
;					-valid_num_counter
;					-accumulator
;					-avg
; Post-conditions: none
print_results PROC

	; Print message if no inputs recieved
	cmp		no_nums_flag, 1
	jne		recieved_input
	mov		edx, OFFSET no_nums_msg
	call	WriteString
	jmp		skip_all

recieved_input:
	; Print value of 'valid_num_counter'
	mov		edx, OFFSET counter_msg1
	call	WriteString
	mov		eax, valid_num_counter
	call	WriteDec
	mov		edx, OFFSET counter_msg2
	call	WriteString

	; Print value of 'accumulator'
	mov		edx, OFFSET sum_msg
	call	WriteString
	mov		eax, accumulator
	call	WriteInt
	mov		edx, OFFSET line_break
	call	WriteString

	; Print value of 'avg'
	mov		edx, OFFSET avg_msg
	call	WriteString
	mov		eax, avg
	call	WriteInt
	mov		edx, OFFSET line_break
	call	WriteString
skip_all:
	ret
print_results ENDP


; Name: closing
; Description: print goodbye message
; Pre-conditions: user_name stores user's name
; Post-conditions: none
closing PROC
	mov		edx, OFFSET closing_msg
	call	WriteString
	mov		edx, OFFSET user_name
	call	WriteString				; Print "bye, USER NAME"
	ret
closing ENDP

END main


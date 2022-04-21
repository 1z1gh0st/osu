TITLE Assignment5_PhilipWarton     (cs271_assignment5.asm)

; Author: Philip Warton
; Last Modified: 02/24/2022
; OSU email address: wartonp@oregonstate.edu
; Course number/section: CS271
; Assignment Number: 5                Due Date: 02/27/2022
; Description: Generate a list of random numbers, sort, compute median.

INCLUDE Irvine32.inc

.data
MIN = 15
MAX = 200

LO = 100
HI = 999

	introMsg			BYTE "Hi, welcome to my program!", 10, 0
	numberPromptMsg		BYTE "Input a number [15..200]: ", 0
	numRangeErrMsg		BYTE "Number out of range. Please try again.", 10, 0
	spaces				BYTE "     ", 0
	goodbyeMsg			BYTE "See ya!", 10, 0

	unsorted			BYTE "unsorted list: ", 10, 0
	sorted				BYTE "  sorted list: ", 10, 0
	median				BYTE "       median: ", 10, 0

	request				DWORD 0
	array				DWORD MAX DUP(?)

.code

;Procedure to run entire program and provide main structure
;recieves: NONE
;returns: NONE
;pre-conditions: NONE
;registers changed: NONE

main PROC
	call	Randomize
	call	introduction

	; getData(&request)
	push	OFFSET request
	call	getData

	; fillArray(&array, request)
	push	OFFSET array
	push	request
	call	fillArray

	; displayList(&array, request)
	mov		edx, OFFSET unsorted
	call	WriteString
	push	OFFSET array
	push	request
	call	displayList
	call	Crlf

	; sortList(&array, request)
	push	OFFSET array
	push	request
	call	sortList

	; displayList(&array, request)
	mov		edx, OFFSET sorted
	call	WriteString
	push	OFFSET array
	push	request
	call	displayList
	call	Crlf
	
	; displayMedian(&array, request)
	mov		edx, OFFSET median
	call	WriteString
	push	OFFSET array
	push	request
	call	displayMedian

	exit
main ENDP





;Procedure to print intro message
;recieves: introMsg is a global variable
;returns: NONE
;pre-conditions: introMsg contains string
;post-conditions: message is displayed
;registers changed: NONE
introduction PROC
	push	edx

	; Print introduction and programmer's name
	mov		edx, OFFSET introMsg
	call	WriteString

	pop		edx
	ret
introduction ENDP





;Procedure to get a valid input from the user
;recieves: &request
;returns: &request with proper value
;pre-conditions: request is a doubleword int, and its address is on the stack
;post-conditions: request's address is no longer on the stack and request contains some integer between 15-200
;registers changed: NONE

getData PROC

	; Recieving parameter from system stack [stores &request in ebx]
	push	ebp
	mov		ebp, esp
	mov		ebx, [ebp+8]
	pushad

	; Skip range error section
	jmp		read_input

	; Print error message
range_error:
	mov		edx, OFFSET numRangeErrMsg
	call	WriteString

	; Get user input value
read_input:
	mov		edx, OFFSET numberPromptMsg
	call	WriteString
	call	ReadInt

	; Check the range
	cmp		eax, MIN
	jl		range_error
	cmp		eax, MAX
	jg		range_error

	; If we do not encounter a range error, we store our value into &request
	mov		[ebx], eax
	
	popad
	pop		ebp
	ret		4
getData ENDP





;Procedure to fill array with random nums
;recieves: &request, &array
;returns: array full of nums
;pre-conditions: parameters are both on the stack, 14<request<201
;post-conditions: array contains 'request' random integers
;registers changed: NONE

fillArray PROC

	; Setup
	push	ebp
	mov		ebp, esp
	pushad

	; Accepting parameters from the stack
	mov		edi, [ebp+12]
	mov		ecx, [ebp+8]

	; Loop to add nums
add_number:

	; Generate random num
	mov		eax, HI
	sub		eax, LO
	inc		eax
	call	RandomRange
	add		eax, LO

	; Add it to array
	mov		[edi], eax
	add		edi, 4
	loop	add_number

	; Exit setup
	popad
	pop		ebp
	ret 8
fillArray ENDP





;Procedure to sort our array using selection sort algorithm
;recieves: &request, &array
;returns: sorted list in array
;pre-conditions: request contains the number of elements in array of random 3-digit nums
;post-conditions: array is sorted
;registers changed: NONE

sortList PROC
	
	; Setup
	push	ebp
	mov		ebp, esp
	pushad

	; Accepting passed variables
	mov		edi, [ebp+12]
	mov		esi, [ebp+8]

	; Outer loop
	mov		eax, 0 ; k
outer_loop_top:
	inc		eax
	cmp		eax, esi
	jge		outer_loop_bottom
	dec		eax
	mov		ecx, eax ; i = k

	; Inner loop
	mov		ebx, eax ; j = k + 1
	inc		ebx
inner_loop_top:
	cmp		ebx, esi
	jge		inner_loop_bottom

	; If array[j] > array[i] => i = j
	mov		edx, [edi+ebx*4]
	cmp		edx, [edi+ecx*4]
	jle		skip
	mov		ecx, ebx ; i = j
skip:
	inc		ebx

	jmp		inner_loop_top
inner_loop_bottom:

	; Swap(array[k], array[i])
	lea		ebx, [edi+eax*4]
	push	ebx
	lea		ebx, [edi+ecx*4]
	push	ebx
	call	exchangeElements
	inc		eax

	jmp		outer_loop_top
outer_loop_bottom:

	; Exit setup
	popad
	pop		ebp
	ret 8
sortList ENDP





;Procedure to swap two elements
;recieves: pointers of two array elements
;returns: nothing
;pre-conditions: both pointers are on the stack prior to call
;post-conditions: values are swapped in the array
;registers changed: NONE

exchangeElements PROC

	; Setup
	push	ebp
	mov		ebp, esp
	pushad

	; Swap array indices
	mov		eax, [ebp+8]
	mov		ebx, [ebp+12]
	mov		ecx, [eax]
	mov		edx, [ebx]
	mov		[eax], edx
	mov		[ebx], ecx

	; Exit setup
	popad
	pop		ebp
	ret 8
exchangeElements ENDP






;Procedure to display the median of an array
;recieves: &request, &array
;returns: NONE
;pre-conditions: array and request addresses are on the stack
;post-conditions: median has been printed to console
;registers changed: NONE

displayMedian PROC

	; Setup
	push	ebp
	mov		ebp, esp

	; Pass in variables
	mov		esi, [ebp+12]
	mov		ecx, [ebp+8]

	; Compute request / 2
	mov		eax, ecx
	mov		ebx, 2
	mov		edx, 0
	div		ebx
	cmp		edx, 0
	je		request_is_even
request_is_odd:
	; Print list[request//2]
	mov		eax, [esi+eax*4]
	call	WriteDec
	jmp		skip
request_is_even:
	mov		ebx, [esi+eax*4]
	mov		eax, [esi+eax*4+4]
	add		eax, ebx
	mov		ebx, 2
	mov		edx, 0
	div		ebx
	add		eax, edx
	call	WriteDec
skip:
	call	Crlf
	pop		ebp
	ret 8
displayMedian ENDP






; Procedure to print out the list
; recieves: &request, &array
; returns: NONE
; pre-conditions: parameters are passed correctly onto the stack
; post-conditions: array has been printed
; registers changed: NONE

displayList PROC
	
	; Setup
	push	ebp
	mov		ebp, esp
	pushad

	; Parameters
	mov		esi, [ebp+12]
	mov		ecx, [ebp+8]

print_num:
	mov		eax, [esi]
	call	WriteDec
	mov		edx, OFFSET spaces
	call	WriteString
	add		esi, 4

	; 10 per line
	mov		eax, [ebp+8]
	sub		eax, ecx
	inc		eax
	mov		ebx, 10
	mov		edx, 0
	div		ebx
	cmp		edx, 0
	jne		no_enter
	call	Crlf
no_enter:
	loop	print_num

	; Setup for exit
	popad
	pop		ebp
	ret 8
displayList ENDP






;Procedure to print goodbye statement
;recieves: goodbyeMsg
;returns: NONE
;pre-conditions: goodbyeMsg is valid string
;registers changed: edx
goodbye PROC

	push	edx

	; Print out goodbye statement
	mov		edx, OFFSET goodbyeMsg
	call	WriteString

	pop		edx
	ret
goodbye ENDP

END main


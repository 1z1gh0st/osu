TITLE Assignment2_PhilipWarton     (template.asm)

; Author: Philip Warton
; Last Modified: 01/23/2022
; OSU email address: wartonp@oregonstate.edu
; Course number/section: CS271
; Assignment Number: 1                Due Date: 01/23/2022
; Description: Takes user name and integer n as input. Prints fibonacci numbers 1-n as output.

INCLUDE Irvine32.inc

.data
;~CONST_VARS~;
	MAX_VAL		DWORD	46
	MIN_VAL		DWORD	1
	ROW_LEN		DWORD	4

;~INPUT_VARS~;
	uname		DWORD	30	DUP (0)
	n			DWORD	0

;~ALGORITHM_VARS~;
	curr		DWORD	1
	prev		DWORD	0

;~UI_STR~;
	intro		BYTE	"Philip Warton - 'Fibonacci Soup'", 10, 0
	ec_txt		BYTE	"Extra credit (display numbers in aligned columns)", 10, 0
	get_name	BYTE	"Enter your name:                               >> ", 0
	hello		BYTE	"Hello, ", 0
	get_num		BYTE	"Number of desired Fibonacci numbers [1 .. 46]: >> ", 0
	range_err	BYTE	"Desired number is out of range...", 10, 0
	space		BYTE	"      ", 0
	entr		BYTE	" ", 10, 0
	bye			BYTE	"BYE", 10, 0

.code
main PROC
	mov	eax,1
	mov	ebx,4
	label6:
	mul	ebx
	call	WriteDec
	call	CrLf
	inc	ebx
	cmp		eax,40
	jbe		label6
	mov		eax,ebx
	call	WriteDec
	call	CrLf
	exit
main ENDP
END main

TITLE Final_Project_Philip_Warton     (CS271_Final_Project_Philip.asm)

; Author: Philip Warton
; Last Modified: 03/15/2022
; OSU email address: wartonp@oregonstate.edu
; Course number/section: CS271
; Assignment Number: N/A                 Due Date: 03/15/2022
; Description: Perform cryptographic tasks given different parameters passed.

INCLUDE Irvine32.inc

.data

.code

main PROC
	exit
main ENDP

; **EC: Add a comment that contains EXACTLY ONE TA name at the beginning of the program. 
;		If that TA happens to be your grader, then you get the points :) 
; Megan Black

; **EC: Ensure that the "decoy" mode correctly returns the sum of ANY signed 16 bit numbers
;		For example, if I sum these two 16-bit numbers: (-32768) + (-32768) I should receive 
;		the value (-65,536) (stored in the 32 bit variable).

; Procedure to recieve parameters and choose helper procedure
; Recieves: three arguments, the third of which may contain a number when dereferenced
; Returns: NONE. Anything that needs to be changed is passed by reference and altered within the function
; Pre-conditions: The last parameter pushed to stack must contain a pointer to a number '-1', or '-2' if 
;			the encrypt or decrypt functionalities are desired
; Post-condtions: Message should either be encrypted or decrypted in place, or the third parameter should
;			contain the sum of the first 2
; Registers changed: EAX

compute PROC

	; Setup
	push	ebp
	mov		ebp, esp

	; Decider parameter
	mov		eax, [ebp+8]
	mov		eax, [eax]
	cmp		eax, -1
	je		encrypt_label
	cmp		eax, -2
	je		decrypt_label

	; decoy(op1,op2,op3)
	push	WORD ptr [ebp+14]
	push	WORD ptr [ebp+12]
	push	[ebp+8]
	call	decoy
	pop		ebp
	ret		8

encrypt_label:
	; encrypt(op1, op2)
	push	[ebp+16]
	push	[ebp+12]
	call	encrypt
	pop		ebp
	ret		12
	
decrypt_label:
	; decrypt(op1, op2)
	push	[ebp+16]
	push	[ebp+12]
	call	decrypt
	pop		ebp
	ret		12

compute ENDP




; Procedure to add two integers and put their sum into the destination
; Recieves: three arguments, the third of which is an address for the resulting sum, the first 2 being integers
; Returns: NONE. Destination is passed by reference so the result is moved directly into the destination
; Pre-conditions: Parameters must be passed in the following order: operand1, operand2, &dest
; Post-condtions: Destination should contain proper sum of the two operands
; Registers changed: EAX, EBX

decoy PROC

	; Sup-procedure setup
	push	ebp
	mov		ebp, esp

	; Recieve integers with sign extension
	movsx	eax, WORD ptr [ebp+14]
	movsx	ebx, WORD ptr [ebp+12]

	; Take their sum
	add		eax, ebx

	; Store it into dest by dereferencing
	mov		ebx, [ebp+8]
	mov		[ebx], eax

	; Exit
	pop		ebp
	ret		8
decoy ENDP




; Procedure to encrypt messages
; Recieves: two arguments, one being a 26 permutation of the alphabet (KEY), and some other BYTE array (MESSAGE)
; Returns: NONE. We alter MESSAGE in place since we recieve a pointer to it
; Pre-conditions: Parameters must be passed in the following order: KEY, MESSAGE
; Post-condtions: MESSAGE should be encrypted correctly using the key
; Registers changed: ESI, EDI, EDX, AL, EBX

encrypt PROC
	; Sub-procedure setup
	push	ebp
	mov		ebp, esp

	; Recieve parameters
	mov		esi, [ebp+12]	; KEY
	mov		edi, [ebp+8]	; MESSAGE

	mov		edx, 0			; INDEX i

; while(MESSAGE[i] != 0)
loop_top_label:
	
	; While loop condition
	mov		al, BYTE PTR [edi+edx]
	cmp		al, 0
	je		loop_bottom_label

	; Only do lowercase ascii chars
	cmp		al, 97
	jl		skip_replace
	cmp		al, 122
	jg		skip_replace

	; While loop content
	sub		al, 97
	movzx	ebx, al
	mov		al, [esi+ebx]

	; MESSAGE[i] = KEY[MESSAGE[i] - 97]
	mov		[edi+edx], al

skip_replace:
	inc		edx
	jmp		loop_top_label
loop_bottom_label:

	; Exit
	pop		ebp
	ret		8
encrypt ENDP




; Procedure to decrypt messages
; Recieves: two arguments, one being a 26 permutation of the alphabet (KEY), and some other BYTE array (MESSAGE)
; Returns: NONE. We alter MESSAGE in place since we recieve a pointer to it
; Pre-conditions: Parameters must be passed in the following order: KEY, MESSAGE
; Post-condtions: MESSAGE should be decrypted correctly using the key
; Registers changed: ESI, EDI, AL, BL, CL, EBX, ECX, EDX

decrypt PROC
	; Sub-procedure setup
	push	ebp
	mov		ebp, esp

	; Recieve parameters
	mov		esi, [ebp+12]	; KEY
	mov		edi, [ebp+8]	; MESSAGE

	mov		edx, 0			; INDEX: i

	; while(MESSAGE[i] != null)
outer_loop_top:
	mov		al, BYTE PTR [edi+edx]
	cmp		al, 0
	je		outer_loop_bottom

	; if(MESSAGE[i] in [97..122])
	cmp		al, 97
	jl		skip_replace
	cmp		al, 122
	jg		skip_replace

	mov		ecx, 0
	; while(KEY[j] != MESSAGE[i])
inner_loop_top:
	mov		bl, BYTE PTR [esi+ecx]
	cmp		al, bl
	je		inner_loop_bottom

	; j++;
	inc		ecx
	jmp		inner_loop_top
inner_loop_bottom:
	add		cl, 97
	mov		[edi+edx], cl

skip_replace:

	inc		edx
	jmp		outer_loop_top
outer_loop_bottom:

	; Exit
	pop		ebp
	ret		8
decrypt ENDP


END main

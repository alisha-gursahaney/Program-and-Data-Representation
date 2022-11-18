; threexplusone.s
;
; Prelab 9
; Alisha Meena Gursahaney
; amg9zd
;
; Purpose : Print out the number of iterations it took 
;			for the integer to converge to 1.
;
; Parameter 1 is the first integer x - rdi
; Parameter 2 is the number of times to call the subroutine - rsi
; Return value is the number of iterations
; Syntax copied over from vecsum.s

	global threexplusone

	section .text

threexplusone:
	xor	rax, rax	 ; zero out the return register
	xor rcx, rcx	; zero out i counter
	

check:	; check if even or odd to jump to correct loop
	;push rdi
	;push rax
	cmp rdi, 1
	je done
	; and rdi, rcx ; check if odd
	mov r10, 1
	;pop rax
	mov r10, 1
	and r10, rdi
	cmp r10, 1
	je odd
	jmp even

even:	; x/2
	; pop rdi
	sar rdi, 1 ; shift x by bit to divide by 2
	; push rcx
	call threexplusone
	add rcx, 1	; increment counter
	; pop rcx
	jmp check

odd:	; 3x+1
	; pop rdi
	imul rdi, 3
	add rdi, 1
	; push rcx
	call threexplusone
	; pop rcx
	add rcx, 1	; increment counter
	jmp check

done:
	mov rax, rcx	; move i counter into return register
	ret



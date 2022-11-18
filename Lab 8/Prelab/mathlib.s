; mathlib.s
;
; Prelab 8
; Alisha Meena Gursahaney
; amg9zd
;
; Purpose : This file contains the implementation of the function
;           product and power, which compute the product and power values 
;			of 2 inputted integers
;
; Parameter 1 is the first integer x
; Parameter 2 is the second integer y
; Return value is the product and power of the 2 integers
;
; Syntax copied over from vecsum.s

	global product
	global power


	section .text

product:
; similar to lecture with while loop i == n
	xor	rax, rax	 ; zero out the return register
	xor	rcx, rcx	 ; zero out the counter i
	; x will be put into rdi
	; y will be put into rsi
	

product_loop:
	cmp	rcx, rsi	 ; does i == y?
	je	done		 ; if so, we are done with the loop
	add	rax, rdi  ; add x to the sum again
	inc	rcx	 ; increment our counter i
	jmp	product_loop		 ; we are done with this loop iteration

product_done: 
	ret

power:
	xor	rax, rax	 ; zero out the return register
	xor	rcx, rcx	 ; zero out the counter i
	mov rcx, 1
	mov rax, rdi	; move the first integer into the power for base^1

power_loop: 
	cmp	rcx, rsi	 ; does i == y?
	je	done		 ; if so, we are done with the loop
	imul rax, rdi  ; multiply the sum by x again
	inc	rcx	 ; increment our counter i ; increment i first so it starts at 1 for pow
	jmp	power_loop		 ; we are done with this loop iteration

done:	

	; Standard epilogue: the return value is already in rax, we
	; do not have any callee-saved registers to restore, and we do not
	; have any local variables to deallocate, so all we do is return
	ret
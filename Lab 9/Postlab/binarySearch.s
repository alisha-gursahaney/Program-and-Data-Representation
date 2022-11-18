; binarysearch.s
;
; Postlab 9
; Alisha Meena Gursahaney
; amg9zd
;
; Purpose : Print out the number of iterations it took 
;			for the integer to converge to 1.
;
; Parameter 1 is a pointer to an int array - rdi
; Parameter 2 is an integer representing the beginning of the array - rsi
; Parameter 3 is an integer representing the end of the array - rdx
; Parameter 4 is an integer representing the target element to find in the array-rcx
; Return value is int index into the array where the target was found
; 	return -1 if not found
; Syntax copied over from vecsum.s

	global binarySearch

	section .text

binarySearch:
	mov rax, -1		; keep -1 in rax in case that target is not found
	xor r10, r10	; array value
	xor r11, r11	; midpoint index
	

search: 
	cmp rsi, rdx ; if the left index is equal to the right index
	jg done	; base case
	mov r11, rsi ; copy left index into r11
	add r11, rdx ; add left and right indices
	shr r11, 1 ; divide by 2 by shifting, r11 is now the midpoint
	mov r10d, [rdi+4*r11]
	cmp r10, rcx ; check if target equals current value
	je found
	; CHECK THIS BELOW
	; 		cmp r10, rcx ; check if target is greater than value
	jl low		; if a[mid]<target
	; 		cmp r10, rcx ; check if target is less than current value
	jg else

low:
	add r11, 1 	; add 1 to midpoint
	mov rsi, r11 ; change left index to midpoint
	jmp binarySearch
	
else:
	sub r11, 1 	; sub 1 from midpoint
	mov rdx, r11 ; change right index to midpoint
	jmp binarySearch

found:
	mov rax, r11
	jmp done

done:	
	ret




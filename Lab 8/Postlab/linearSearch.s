; Alisha Meena Gursahaney
; amg9zd
; postlab 8
; parameter 1: pointer to int array rdi
; parameter 2: int size of array rsi
; parameter 3: int target rdx
; array[i] is equal to [rdi+4*[i]]

	global linearSearch

	section .text

linearSearch:
	xor rax, rax ; set return register to zero
	mov rax, -1 ; set return value to -1, so it will return -1 if not found
	xor r8, r8 ; i iterator set to zero
	mov r8, 0

search:
	cmp edx, [rdi+4*r8] ; if the target is equal to the pointer
	je found 		; jump to found loop if equal
	cmp rsi, r8		; base case if the iterator is the same as the size, then done
	je notfound 	; at end of array and not found, will return -1
	add r8, 1 		; increment i counter by 1
	jmp search 		; loop

notfound:
	ret

found:
	mov rax, r8 	; if found, move the iterator into rax
	ret


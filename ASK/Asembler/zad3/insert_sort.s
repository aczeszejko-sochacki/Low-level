	.global insert_sort
	.type insert_sort, @function
	.section .text

insert_sort:
	mov %rdi, %r8		# %r8 = i(first not sorted el)
.loop:	cmp %r8, %rsi
	je .exit
	mov %r8, %r9		# %r9 = j(iterator on sorted)
	lea 8(%r8), %r8		# i++
	mov (%r8), %rax		# %rax = T[i]
.srtd:	cmp (%r9), %rax		
	jge .loop		# if T[j] <= T[i] insert done
	mov (%r9), %r10		# tmp
	mov 8(%r9), %r11	# tmp
	mov %r10, 8(%r9)	# swap
	mov %r11, (%r9)		# swap
	cmp %r9, %rdi		# if  T[i] is minimum in sorted
	je .loop
	lea -8(%r9), %r9	# j--
	jmp .srtd
.exit:	ret
	.size = . - insert_sort

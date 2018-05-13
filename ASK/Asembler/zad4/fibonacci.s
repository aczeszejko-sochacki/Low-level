	.global fibonacci
	.type fibonacci, @function
	.section .text

fibonacci:
	mov	%rdi, %rbx
	test	%rbx, %rbx
	je	.exit		# if (n == 0) exit
	cmp	$1, %rbx	
	je	.exit		# if (n == 1) exit
.fib:	push	%rdi
	dec	%rdi		# n--
	push	%rbp
	call	fibonacci
	pop	%rbp
	pop	%rdi
	mov	%rax, %rbp
	push	%rdi
	sub	$2, %rdi	# n -= 2
	push	%rbp
	call	fibonacci
	pop	%rbp
	pop	%rdi
	add	%rbp,%rax	# fib(n) = fib(n-1) + fib(n-2)
	ret
.exit:	mov %rbx, %rax
	ret
        .size   fibonacci, . - fibonacci
	


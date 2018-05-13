	.global lcm_gcd
	.type lcm_gcd, @function
	.section .text

lcm_gcd:
	mov %rdi, %r8		# %r8 = x
	mov %rsi, %r9		# %r9 = y

.gcd:	cmp %r8, %r9		# check if y > x
	je .exit		# if(x == y) .exit
	jl .ygrtr		# if(x < y) .ygrtr
	sub %r8, %r9		# x -= y
	jmp .gcd

.ygrtr:	sub %r9, %r8		# y -= x
	jmp .gcd

.exit:	mov %rdi, %rax
	mul %rsi
	div %r8
	mov %r8, %rdx
	ret
	.size = . - lcm_gcd

	.global mulf
	.type mulf, @function
	.section .text

mulf:	mov %edi, %r8d	
	mov %esi, %ebx
	xor %r8d, %ebx		# compute sign of mul
	and $0x80000000, %ebx	# sign of mul in %ebx

	mov %esi, %r9d
	and $0x7F800000, %r8d	# only E1 in %r8d
	and $0x7F800000, %r9d	# only E2 in %r9d
	lea (%r8d, %r9d), %ecx	# E1 + E2 in %ecx
	sub $0x3F800000, %ecx	# E1 + E2 should have one bias
	and $0x7F800000, %ecx	# cut new E
	
	xor %rax, %rax
	mov %edi, %r8d
	mov %esi, %eax
	and $0x007FFFFF, %r8d	# only M1 in %r8d
	and $0x007FFFFF, %eax	# only M2 in %eax
	xor $0x00800000, %r8d	# set default 1. in %r8d
	xor $0x00800000, %eax	# set default 1. in %eax
	mul %r8d		# exact M1 * exact M2 in %edx:%eax
	mov %edx, %r8d
	and $0x00008000, %r8d
	cmp $0x00008000, %r8d	# check if M1 * M2 > 2
	jne .exit
	shr $1, %r8d		# shift new M in case of overflow
	add $0x00800000, %ecx	# inc exp in case of overflow

.exit:	shr $23, %eax		# shift new M
	shl $9, %edx
	add %edx, %eax		# %eax is the final M
	and $0x007FFFFF, %eax	# remove default bit
	xor %ebx, %eax		# set sign
	xor %ecx, %eax		# set exp
	ret
	.size = . - mulf

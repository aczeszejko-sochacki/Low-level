	.global clz
	.type clz,@function
	.section .text

clz:
	mov $16, %cl		# shift param in %cl
	mov $32, %rax		# count leading 0 in %rax
	test %rdi, %rdi
	jz .min			# if %rdi is 0 .min

.bins:	test %cl, %cl
	jz .exit		# lg 16 iterations
	mov %rdi, %r8		
	shr %cl, %r8
	test %r8, %r8		# check if left half is zero
	jz .zeros
	mov %r8, %rdi
	sub %cl, %al		# there was 1 in left half
.zeros:	shr %cl
	jmp .bins		# continue loop

.exit:	dec %rax
.min:	ret
.max:	mov $0, %rax
	ret
	.size = . - clz

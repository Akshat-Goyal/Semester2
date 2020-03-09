.text
.global parityCheck
parityCheck:
	movl	$0,%eax
	movl	$0,%ebx
.Lcheck:
	cmpl	$64,%ebx
	je		.Lexit
	movq	%rdi,%rcx
	andq	$1,%rcx
	cmpq	$1,%rcx
	je		.Lone
	sarq	$1,%rdi
	inc		%ebx
	jmp		.Lcheck
.Lone:
	inc		%eax
	sarq	$1,%rdi
	inc		%ebx
	jmp		.Lcheck
.Lexit:
	andl	$1,%eax
	cmpl	$1,%eax
	jne		.Leven
	ret
.Leven:
	movl	$0,%eax
	ret

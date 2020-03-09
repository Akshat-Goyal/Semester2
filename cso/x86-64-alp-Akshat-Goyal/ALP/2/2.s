.text
.global max
max:
	movl	(%rdi),%eax		
	movl	$0,%r8d
	movl	$1,%r9d
.Lcol:
	cmpl	%edx,%r9d
	je		.Lrow
	movl	%edx,%ebx
	imul	%r8d,%ebx
	addl	%r9d,%ebx
	lea		(%rdi,%rbx,4),%rbx
	movl	(%rbx),%ebx
	cmpl	%eax,%ebx
	jg		.Lmax
	inc		%r9d
	jmp		.Lcol
.Lmax:
	movl	%ebx,%eax
	inc		%r9d
	jmp		.Lcol
.Lrow:
	inc		%r8d
	cmpl	%esi,%r8d
	je		.Lexit
	movl	$0,%r9d
	jmp		.Lcol
.Lexit:
	ret

.text
.global binarySearch
binarySearch:
	movl	$-1,%r9d
	movl	$2,%r11d
	movl	%edx,%r8d
	movl	$0,%ebx
	dec		%esi
	movl	%esi,%ecx
.Lloop:
	cmpl	%ebx,%ecx
	jl		.Lexit
	movl	%ecx,%eax
	addl	%ebx,%eax
	cqto	
	idivl	%r11d
	leaq	(%rdi,%rax,4),%r10
	movl	(%r10),%r10d
	cmpl	%r10d,%r8d
	je		.Le
	jg		.Ll
	jmp		.Lg
.Le:
	movl	%eax,%r9d
	jmp		.Lexit
.Ll:	
	movl	%eax,%ebx
	inc		%ebx
	jmp		.Lloop
.Lg:
	movl	%eax,%ecx
	dec		%ecx
	jmp		.Lloop
.Lexit:	
	movl	%r9d,%eax
	ret

.text
.global reverse
length:
.Llength:
	leaq	(%rdi,%rax,1),%rcx
	cmpb	$0,(%rcx)
	je		.Lreturn
	inc		%eax
	jmp		.Llength		
.Lreturn:
	ret
swap:
	movb	(%rdi),%r8b
	movb	(%rsi),%r9b
	movb	%r9b,(%rdi)
	movb	%r8b,(%rsi)
	ret	
reverse:
	movl	$0,%eax
	call	length
	movl	$0,%ebx
	dec		%eax
	movq	%rdi,%rcx
.Lrev:
	cmpl	%ebx,%eax
	jle		.Lexit
	leaq	(%rcx,%rbx,1),%rdi
	leaq	(%rcx,%rax,1),%rsi
	call	swap
	inc		%ebx
	dec		%eax
	jmp		.Lrev
.Lexit:
	ret

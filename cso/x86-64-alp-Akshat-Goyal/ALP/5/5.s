.text
.global sumN
sumN:
	cmpl	$0,%edi
	je		.LbaseCase
	movl	%edi,%eax
	push	%rax
	dec		%edi
	call	sumN
	pop		%rbx
	addl	%ebx,%eax
	ret
.LbaseCase:
	movl	$0,%eax
	ret

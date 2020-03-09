.text
.global merge
merge:
	movl	$0,%eax
	movl	$0,%ebx
	movl	$-1,%r11d
.Lmerge:
	cmpl	%eax,%esi
	je		.Ll1
	cmpl	%ebx,%ecx
	je		.Ll2
	leaq	(%rdi,%rax,4),%r9
	leaq	(%rdx,%rbx,4),%r10
	movl	(%r9),%r9d
	movl	(%r10),%r10d
	cmpl	%r9d,%r10d
	jge		.Lle
	jmp		.Lg
.Lle:
	inc		%r11d
	inc		%eax
	lea 	(%r8,%r11,4),%r12
	movl	%r9d,(%r12)
	jmp		.Lmerge
.Lg:
	inc		%r11d
	inc 	%ebx
	lea 	(%r8,%r11,4),%r12
	movl	%r10d,(%r12)
	jmp		.Lmerge
.Ll1:
	cmpl	%ebx,%ecx
	je 		.Lexit
	inc		%r11d
	lea 	(%r8,%r11,4),%r12
	leaq	(%rdx,%rbx,4),%r10
	movl	(%r10),%r10d
	movl	%r10d,(%r12)
	inc		%ebx
	jmp		.Ll1
.Ll2:
	cmpl	%eax,%esi
	je 		.Lexit
	inc		%r11d
	lea 	(%r8,%r11,4),%r12
	leaq	(%rdi,%rax,4),%r9
	movl	(%r9),%r9d
	movl	%r9d,(%r12)
	inc		%eax
	jmp		.Ll2
.Lexit:
	ret

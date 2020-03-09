.text
.global sort
sort:
	movl	$0,%eax			#i=0
	movl	%esi,%ecx		#j < n - i -1
	dec		%esi			#n--
.Lloop1:
	cmpl	%eax,%esi
	je		.Lexit
	inc		%eax			#i++
	movl	$0,%ebx			#j=0
	dec		%ecx
	jmp		.Lloop2
.Lloop2:
	cmpl 	%ebx,%ecx
	je		.Lloop1
	lea		(%rdi,%rbx,4),%r8
	movq	%r8,%r9
	addq	$4,%r9
	movl	(%r8),%r10d
	movl	(%r9),%r11d
	cmpl	%r10d,%r11d
	jl		.Lswap
	inc		%ebx
	jmp		.Lloop2
.Lswap:
	movl	%r10d,(%r9)
	movl	%r11d,(%r8)
	inc		%ebx
	jmp		.Lloop2
.Lexit:
	ret

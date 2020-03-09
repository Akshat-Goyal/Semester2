.text
.global sum
sum:
	movl 	$0,%eax			#even sum
	movl 	$0,%r8d			#row i -> n
	movl 	$0,%r9d			#col j -> m
.Lcol:
	cmpl	%edx,%r9d		#if j==m
	je   	.Lrow
	movl 	%edx,%ecx			#ecx=m
	imul 	%r8d,%ecx			#ecx*=i
	addl 	%r9d,%ecx			#ecx+=j
	lea  	(%rdi,%rcx,4),%rcx	
	movl 	(%rcx),%ecx			#ecx=*(ar+i*m+j)
	movl 	%ecx,%r10d			#r10d=ecx
	andl  	$1,%r10d			#r10d&=1
	cmpl	$0,%r10d			#if r10d == 0 (if ecx is even)
	je		.Lsum				#add ecx to sum
	inc		%r9d				#j++
	jmp		.Lcol
.Lsum:
	addl	%ecx,%eax			#sum+=ecx
	inc		%r9d				#j++
	jmp		.Lcol
.Lrow:
	inc 	%r8d				#i++
	cmpl 	%esi,%r8d			#if i == n
	je   	.Lexit				#return sum
	movl	$0,%r9d				#j=0
	jmp		.Lcol
.Lexit:
	ret

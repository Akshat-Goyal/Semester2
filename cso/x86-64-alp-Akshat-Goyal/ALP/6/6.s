.text
.global isPrime
isPrime:
	movl	$2,%ebx					#i=2
.Lprime:
	cmpl	%ebx,%edi
	je		.Lexit1					#if i == n
	jl		.Lexit2					#if i < n
	movl	%edi,%eax				#eax=n
	cqto							#edx=0
	idivl	%ebx					#eax/ebx  eax=q,edx=r
	cmpl	$0,%edx					#if r == 0
	je		.Lexit2
	inc		%ebx					#i++
	jmp		.Lprime
.Lexit1:
	movl	$1,%eax					#eax=1 (prime)
	ret
.Lexit2:
	movl	$0,%eax					#eax=0 (not prime)
	ret

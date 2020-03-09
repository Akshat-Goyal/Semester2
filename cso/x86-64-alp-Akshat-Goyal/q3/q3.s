.text
.global fibonacci
fibonacci:
	movl 	$1, %eax			#a1=1
	movl 	$0, %ebx			#a0=0
	movl 	$1, %ecx			#for(i=1;;)
.Lback:
	cmpl 	%edi,%ecx			#%edi==N
	je		.Lloopexit			
	movl	%eax,%edx			#edx=a1
	addl	%ebx,%eax			#a1+=a0
	movl	%edx,%ebx			#a0=a1(previous value)
	inc		%ecx				#i++
	jmp		.Lback
.Lloopexit:
	ret
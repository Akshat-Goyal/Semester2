.data

N:
	.long 11			

aN:									#Nth fibonacci no
	.long 0

# Code section starts 

.text
.global main
main:
	movl 	$0, %eax					#a0
	movl 	$1, %ebx					#a1
	movl 	$1, %ecx					#for (i=1;;)
	mov 	N@GOTPCREL(%rip), %rdx
	movl	(%rdx),%edx				#N<->%edx
.Lback:
	cmpl 	%ecx,%edx				#i==N
	je 		.Lloopexit
	movl 	%ebx,%esi				#a1<->%esi
	addl	%eax,%ebx				#a1+=a0
	movl    %esi,%eax				#a0=a1(previous value)
	inc 	%ecx					#i++
	jmp		.Lback
.Lloopexit:
	mov     aN@GOTPCREL(%rip),%ecx
	movl	%ebx, (%ecx)			
	ret
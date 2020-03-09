.data

N:
	.long 11			

aN:									#Nth fibonacci no
	.long 0

# Code section starts 

.text
.global main
main:
	mov 	N@GOTPCREL(%rip), %rdi
	movl 	(%rdi),%edi				#N<->%edx
	call	fibonacci
	mov     aN@GOTPCREL(%rip),%ebx
	movl	%eax, (%ebx)			#aN=eax			
	ret
.data

N:
	.long 11

aN:									#Nth fibonacci no
	.long 0

# Code section starts 

.text
fibonacci:
	cmpl 	$0,%edi
	je		.LbaseCase1
	cmpl	$1,%edi
	je		.LbaseCase2
	dec		%edi					
	push    %rdi
	call	fibonacci				#fibonacci(N-1)
	pop     %rdi
	push    %rax
	dec     %edi
	call    fibonacci				#fibonacci(N-2)
	pop     %rbx
	addl	%ebx,%eax
	ret
.LbaseCase1:
	movl    $0,%eax
	ret
.LbaseCase2:
	movl    $1,%eax
	ret
.global main
main:
	mov 	N@GOTPCREL(%rip), %rdi
	movl   (%rdi),%edi					#N<->%edi
	call    fibonacci
	mov     aN@GOTPCREL(%rip),%ebx
	movl	%eax, (%ebx)				#aN=eax
	ret
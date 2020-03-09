.data

N:
	.long 5									#N

array:
	.long 5,2,1,3,4

sum:
	.long 0

max:
	.long 0

.text
.global main
main:
	mov 	N@GOTPCREL(%rip), %rax      	
	movl   (%rax),%eax						#N<->eax
	mov 	array@GOTPCREL(%rip), %rbx		#array<->rbx
	movl    $1,%ecx							#for(i=1;;)
	movl    (%rbx),%edx						#max<->edx
	movl    %edx,%esi						#sum<->esi
.Lfor:
	cmpl    %ecx,%eax
	je      .Lloopexit
	lea     (%rbx,%rcx,4),%r8				#r8=&array[i]
	cmpl    %edx,(%r8)
	jg      .Lmax
	jmp     .Lsum
.Lmax:
	movl    (%r8),%edx
	jmp     .Lsum
.Lsum:
	addl    (%r8),%esi
	inc     %ecx							#i++
	jmp     .Lfor
.Lloopexit:
	mov 	max@GOTPCREL(%rip), %rax
	movl    %edx,(%rax)
	mov 	sum@GOTPCREL(%rip), %rbx
	movl    %esi,(%rbx)
	ret

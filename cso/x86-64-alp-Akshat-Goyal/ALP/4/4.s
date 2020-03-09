.text
.global partition
swap:
	lea		(%rdi,%rax,4),%r8
	movl	(%r8),%r9d
	movl	%edx,(%r8)
	lea		(%rdi,%rcx,4),%r8
	movl	%r9d,(%r8)
	ret
partition:
	movl	%esi,%eax			#i=n
	movl	%esi,%ecx
	dec		%ecx
.Lloop:
	cmpl	$0,%ecx
	je		.Lexit
	lea		(%rdi,%rcx,4),%rdx
	movl	(%rdx),%edx
	cmpl	%edx,(%rdi)
	jl		.Ldo
	dec		%ecx
	jmp		.Lloop
.Ldo:
	dec		%eax
	call	swap
	dec		%ecx
	jmp		.Lloop
.Lexit:
	dec		%eax
	movl	(%rdi),%edx
	call	swap
	ret

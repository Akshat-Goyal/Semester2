.text
.global countMovesHanoi
countMovesHanoi:
	cmpl	$1,%edi
	je		.Lbase
	dec		%edi
	movl	$0,%eax
	call	countMovesHanoi
	imul	$2,%eax
	addl	$1,%eax
	ret
.Lbase:
	movl	$1,%eax
	ret

	.section	__TEXT,__text,regular,pure_instructions
	.globl	_LLStackIsEmpty
	.align	4, 0x90
_LLStackIsEmpty:                        ## @LLStackIsEmpty
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%eax
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	cmpl	$0, (%eax)
	sete	%cl
	andb	$1, %cl
	movzbl	%cl, %eax
	addl	$4, %esp
	popl	%ebp
	ret

	.globl	_LLStackPush
	.align	4, 0x90
_LLStackPush:                           ## @LLStackPush
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	subl	$36, %esp
	calll	L1$pb
L1$pb:
	popl	%eax
	movb	12(%ebp), %cl
	movl	8(%ebp), %edx
	movl	$8, %esi
	movl	%edx, -8(%ebp)
	movb	%cl, -9(%ebp)
	movl	$8, (%esp)
	movl	%eax, -20(%ebp)         ## 4-byte Spill
	movl	%esi, -24(%ebp)         ## 4-byte Spill
	calll	_malloc
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	jne	LBB1_2
## BB#1:
	movl	-20(%ebp), %eax         ## 4-byte Reload
	leal	L_.str-L1$pb(%eax), %ecx
	movl	%ecx, (%esp)
	calll	_printf
	movl	$1, %ecx
	movl	$1, (%esp)
	movl	%eax, -28(%ebp)         ## 4-byte Spill
	movl	%ecx, -32(%ebp)         ## 4-byte Spill
	calll	_exit
LBB1_2:
	movl	-8(%ebp), %eax
	cmpl	$0, (%eax)
	jle	LBB1_4
## BB#3:
	movl	-8(%ebp), %eax
	movl	4(%eax), %eax
	movl	-16(%ebp), %ecx
	movl	%eax, 4(%ecx)
LBB1_4:
	movl	-16(%ebp), %eax
	movl	-8(%ebp), %ecx
	movl	%eax, 4(%ecx)
	movb	-9(%ebp), %dl
	movl	-16(%ebp), %eax
	movb	%dl, (%eax)
	movl	-8(%ebp), %eax
	movl	(%eax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%eax)
	addl	$36, %esp
	popl	%esi
	popl	%ebp
	ret

	.globl	_LLStackPop
	.align	4, 0x90
_LLStackPop:                            ## @LLStackPop
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %eax
	movb	(%eax), %cl
	movb	%cl, -5(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	-4(%ebp), %edx
	movl	%eax, 4(%edx)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	calll	_free
	movl	-4(%ebp), %eax
	movl	(%eax), %edx
	subl	$1, %edx
	movl	%edx, (%eax)
	movsbl	-5(%ebp), %eax
	addl	$24, %esp
	popl	%ebp
	ret

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"No available memory to add to the stack\n"


.subsections_via_symbols

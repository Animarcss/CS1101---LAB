	.file	"math.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Enter two integers: "
.LC1:
	.string	"%d %d"
.LC2:
	.string	"Sum = %d\n"
.LC3:
	.string	"Difference = %d\n"
.LC4:
	.string	"Product = %d\n"
.LC5:
	.string	"Quotient = %d\n"
.LC6:
	.string	"Remainder = %d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	endbr64
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	4(%rsp), %rdx
	movq	%rsp, %rsi
	xorl	%eax, %eax
	leaq	.LC1(%rip), %rdi
	call	__isoc99_scanf@PLT
	movl	4(%rsp), %edx
	movl	$1, %edi
	xorl	%eax, %eax
	addl	(%rsp), %edx
	leaq	.LC2(%rip), %rsi
	call	__printf_chk@PLT
	movl	(%rsp), %edx
	movl	$1, %edi
	xorl	%eax, %eax
	subl	4(%rsp), %edx
	leaq	.LC3(%rip), %rsi
	call	__printf_chk@PLT
	movl	(%rsp), %edx
	imull	4(%rsp), %edx
	xorl	%eax, %eax
	leaq	.LC4(%rip), %rsi
	movl	$1, %edi
	call	__printf_chk@PLT
	movl	(%rsp), %eax
	movl	$1, %edi
	leaq	.LC5(%rip), %rsi
	cltd
	idivl	4(%rsp)
	movl	%eax, %edx
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movl	(%rsp), %eax
	movl	$1, %edi
	leaq	.LC6(%rip), %rsi
	cltd
	idivl	4(%rsp)
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movq	8(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L5
	xorl	%eax, %eax
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L5:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:

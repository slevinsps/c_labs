	.file	"zad1.c"
	.text
	.globl	_Division
	.def	_Division;	.scl	2;	.type	32;	.endef
_Division:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
L4:
	movl	8(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	L7
	movl	12(%ebp), %eax
	subl	%eax, 8(%ebp)
	addl	$1, -4(%ebp)
	jmp	L4
L7:
	nop
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Enter a,b\0"
LC1:
	.ascii "%d %d\0"
LC2:
	.ascii "Uncorrected variables...\0"
LC3:
	.ascii "Division by zero...\0"
LC4:
	.ascii "%d / %d = %d; %d %% %d = %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$48, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	call	___main
L12:
	movl	__imp___iob, %eax
	addl	$32, %eax
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	_setbuf
	movl	$LC0, (%esp)
	call	_puts
	leal	36(%esp), %eax
	movl	%eax, 8(%esp)
	leal	40(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	testl	%eax, %eax
	jne	L9
	movl	__imp___iob, %eax
	movl	%eax, (%esp)
	call	_fflush
	movl	$LC2, (%esp)
	call	_puts
	jmp	L10
L9:
	movl	36(%esp), %eax
	testl	%eax, %eax
	jne	L11
	movl	$LC3, (%esp)
	call	_puts
	jmp	L10
L11:
	movl	__imp___iob, %eax
	movl	%eax, (%esp)
	call	_fflush
	movl	36(%esp), %edx
	movl	40(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_Division
	movl	%eax, 44(%esp)
	movl	40(%esp), %edx
	movl	36(%esp), %eax
	imull	44(%esp), %eax
	movl	%edx, %esi
	subl	%eax, %esi
	movl	36(%esp), %ebx
	movl	40(%esp), %ecx
	movl	36(%esp), %edx
	movl	40(%esp), %eax
	movl	%esi, 24(%esp)
	movl	%ebx, 20(%esp)
	movl	%ecx, 16(%esp)
	movl	44(%esp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
L10:
	jmp	L12
	.cfi_endproc
LFE14:
	.ident	"GCC: (Rev2, Built by MSYS2 project) 6.3.0"
	.def	_setbuf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_fflush;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef

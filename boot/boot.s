.set MAGIC, 0x1BADB002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.align 4
    .long MAGIC
    .long FLAGS
    .long CHECKSUM

.section .text
.global _start
_start:
    cli
    mov $stack_top, %esp
    call kernel_main
halt:
    hlt
    jmp halt

.section .bss
.space 16384
stack_top:

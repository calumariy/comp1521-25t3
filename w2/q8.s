#include <stdio.h>

main:

outer_init:
    li $t0, 1
outer_cond:
    bgt $t0, 10, outer_end
outer_body:
outer_body__inner_init:
    li $t1, 0
outer_body__inner_cond:
    bge $t1, $t0, outer_body__inner_end
outer_body__inner_body:
    li 	$a0, '*'
    li  $v0, 11
    syscall
outer_body__inner_incr:
    addi $t1, $t1, 1
    j    outer_body__inner_cond
outer_body__inner_end:
    li 	$a0, '\n'
    li  $v0, 11
    syscall
outer_incr:
    addi $t0, $t0, 1
    j outer_cond

outer_end:

	jr $ra
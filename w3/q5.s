.data
numbers:
    .word 0:10

.text
main:
    li  $t0, 0

loop_cond:
    bge	$t0, 10, loop_end

loop_body:

    li	$v0, 5
    syscall
    move	$t1, $v0

    la	$t2, numbers
    mul	$t3, $t0, 4
    add	$t2, $t2, $t3

    sw	$t1, ($t2)

loop_inc:
    addi $t0, $t0, 1
    j   loop_cond

loop_end:

    jr	$ra
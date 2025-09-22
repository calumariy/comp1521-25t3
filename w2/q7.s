main:

print_3rd_number_init:
    li	$t0, 24

print_3rd_number_cond:
	bge	$t0, 42, loop_end

print_3rd_number_body:


    li	$v0, 1
	move	$a0, $t0
    syscall

    li	$v0, 11
    li	$a0, '\n'
    syscall


loop_inc:
	addi	$t0, $t0, 3
    j	 loop_cond

loop_end:

    jr	$ra
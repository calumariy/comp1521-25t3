.data
string_label:
	.asciiz "Enter a number: "


.text
main:
	la	$a0, string_label
	
	li	$v0, 4
	syscall				# print string

	li	$v0, 5
	syscall				# get input in v0

	move	$t0, $v0

	mul	$t1, $t0, $t0	# y (t1) = x * x (t0 * t0)

	li	$v0, 1
	move	$a0, $t1
	syscall			# print y

	li	$a0, '\n'
	li	$v0, 11
	syscall			# Print new line


	jr	$ra

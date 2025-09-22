.data
string_label:
	.asciiz "Enter a number: "


.text
main:
	la	$a0, string_label
	
	li	$v0, 4
	syscall			# printf("Enter a number: ")

	li	$v0, 5
	syscall		
	move	$t0, $v0	# scanf("%d", $t0)

	mul	$t1, $t0, $t0	# $t1 = $t0 * $t0

	li	$v0, 1
	syscall			# printf("%d", $t1)

	li	$a0, '\n'
	li	$v0, 11
	syscall			# putchar("\n")


	jr	$ra
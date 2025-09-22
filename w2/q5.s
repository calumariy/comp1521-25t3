.data
string_label:
	.asciiz "Enter a number: "

error_string:
	.asciiz "Error: too big for 32 bits\n"

.text
main:
	la	$a0, string_label
	
	li	$v0, 4
	syscall			# printf("Enter a number: ")

	li	$v0, 5
	syscall		
	move	$t0, $v0	# scanf("%d", $t0)

error_code:
	#printf("number too big")
	la	$a0, error_string
	li	$v0, 4
	syscall

	j	main_epilogue

square_code:
	mul	$t1, $t0, $t0	# $t1 = $t0 * $t0

	li	$v0, 1
	move	$a0, $t1
	syscall			# printf("%d", $t1)

	li	$a0, '\n'
	li	$v0, 11
	syscall			# putchar("\n")


main_epilogue:
	jr	$ra
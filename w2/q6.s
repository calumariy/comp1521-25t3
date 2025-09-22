.data
input_string:
	.asciiz "Enter a number: "

medium_string:
	.asciiz "medium\n"

small_big_string:
	.asciiz "small/big\n"
.text
main:
	#  x= $t1
    li	$v0, 4
    la	$a0, input_string
    syscall

    li	$v0, 5
    syscall
    move $t0, $v0

    ble	 $t0, 100, print_small_big
    bge  $t0, 1000, print_small_big

print_medium:
    la   $a0, medium_string
    li	 $v0, 4
    syscall
    j    end_label;
print_small_big:
    li	 $a0, small_big_string
    li	 $v0, 4
    syscall
end_label:
	jr $ra


.data
# input array of four integers
inputArray: .word 2, 3, 4, 5

.text
.globl main
main:
    la   $t0, inputArray     # $t0 = address of first element of inputArray
    li   $t1, 0x10010020     # $t1 = address of first element of our output array

    li   $t2, 4              # loop counter for 4 elements

loop:
    lw   $t3, 0($t0)         # load current element from inputArray into $t3
    mul  $t4, $t3, $t3       # compute the square: $t4 = $t3 * $t3
    sw   $t4, 0($t1)         # store the squared value into outputArray

    addi $t0, $t0, 4         # advance input pointer by 4 bytes (size of an integer)
    addi $t1, $t1, 4         # advance output pointer similarly
    addi $t2, $t2, -1        # decrement loop counter

    bnez $t2, loop           # continue looping if $t2 is not zero

    li   $v0, 10             # load exit system call code
    syscall                  # make the system call to terminate
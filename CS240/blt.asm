# - sets $t0 = 1 if val1 < val2 (using SLT)
# - sets $t1 = 1 if val1 < val2 (manual method)

.data
val1:   .word 2
val2:   .word 3

.text
.globl main

main:
    # load values into registers
    lw    $s0, val1 		# $s1 = val1
    lw    $s1, val2 		# $s2 = val2

    # method 1: Use SLT to set $t0 = 1 if $s1 < $s2
    
    slt   $at, $s0, $s1  		# $at = 1 if $s1 < $s2 (signed)
    bne   $at, $zero, less1 	# if $at < 0, branch to less
    
    continue:
    # method 2: Subtract and shift right
    
    sub   $at, $s1, $s0
    bgtz  $at, less2
    
    j     done

less1: li $t0, 1 		# set $t0 to 1 (refer to line 1)
       j  continue

less2: li $t1, 1

done:
    li    $v0, 10
    syscall
nop 0 0 0 startaddress to load from next (something like .data)
loa 0 0 15
loa 0 0 0 load 1
add 0 15 15 increase r15 by 1 
loa 0 0 1 
add 0 15 15 increase r15 by 1
loa 0 0 2
nop 0 0 0
loa 0 0 4
nop 0 0 0
loa 0 0 5
nop 0 0 0
add 0 1 6
nop 0 0 0
add 1 5 0
nop 0 0 0
add 6 5 1
nop 0 0 0
add 3 4 3
nop 0 0 0
loa 0 0 15
nop 0 0 0
jle 3 2 0
hlt 0 0 0 

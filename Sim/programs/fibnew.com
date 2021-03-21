nop 0 0 0 startaddress to load from next (something like .data)
loa 0 0 15
loa 0 0 0 load value #1
add 0 15 15 increase r15 by 1
nop 0 0 0
loa 0 0 1 load value #1 
add 0 15 15 increase r15 by 1
nop 0 0 0
loa 0 0 2 load #repeats
add 0 15 15
nop 0 0 0
loa 0 0 4 load #0
add 0 15 15 
nop 0 0 0
loa 0 0 5 load #1
add 0 15 15
nop 0 0 0
loa 0 0 15 load jump adress
nop 0 0 0
add 0 1 6 add r0 and r1 save to r6
nop 0 0 0
add 0 4 1 move r0 to r1
nop 0 0 0
add 6 4 1 move result of r0+r1 from r6 to r0
nop 0 0 0
add 3 5 3 increment counter by 1 
nop 0 0 0
jle 3 2 0 jump if r3 smaller than r2(repeats)
hlt 0 0 0 
nop 0 0 0 value for r0 
nop 0 0 0 value for r1
nop 0 0 0 value for r2
nop 0 0 0 value for r4
nop 0 0 0 value for r5

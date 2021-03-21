nop 0 0 0   start of data in memory
loa 0 0 15  load memory adress of data
nop 0 0 0
loa 0 0 0   const 1
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 1   a
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 2   s
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 3   m
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 4   newline
nop 0 0 0
add 0 15 15
nop 0 0 0
tgl 0 0 0
nop 0 0 0
str 1 0 0   print a
nop 0 0 0
str 2 0 0   print s
nop 0 0 0
str 3 0 0   print m
nop 0 0 0
str 4 0 0   print newline
nop 0 0 0
loa 0 0 1   input first char
nop 0 0 0
loa 0 0 2   input second char
nop 0 0 0
loa 0 0 3   input third char
nop 0 0 0
tgl 0 0 0   switch back to prgm mem
add 2 3 1   add second and third char together, store in r1
nop 0 0 0
loa 0 0 4   136
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 5   140
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 6   144
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 7   145
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 8   146
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 9   147
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 10  150
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 11  155
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 12  157
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 13  159
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 14  load jump adress
nop 0 0 0
add 0 15 15
nop 0 0 0
jeq 1 4 0   jump if r1 = 136/add
hlt 0 0 0
loa 0 0 1   a
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 2   d
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 3   d
nop 0 0 0
add 0 15 15
nop 0 0 0
loa 0 0 4   newline
nop 0 0 0
add 0 15 15
nop 0 0 0
tgl 0 0 0   print to term
nop 0 0 0
str 1 0 0   print a
nop 0 0 0
str 2 0 0   print d
nop 0 0 0
str 3 0 0   print d
nop 0 0 0
str 4 0 0   print newline
nop 0 0 0
tgl 0 0 0
loa 0 0 14  load adress for halt jump
nop 0 0 0
jeq 0 0 0   jump to halt-adress

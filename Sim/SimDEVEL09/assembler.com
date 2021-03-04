loa 0 0 0a
nop 0 0 0
loa 0 0 1s
nop 0 0 0
loa 0 0 2e
nop 0 0 0
loa 0 0 3m
nop 0 0 0
loa 0 0 4b
nop 0 0 0
loa 0 0 5l
nop 0 0 0
loa 0 0 6r
nop 0 0 0
loa 0 0 7newline
nop 0 0 0
tgl 0 0 0
nop 0 0 0
str 0 0 0a
nop 0 0 0
str 1 0 0s
nop 0 0 0
str 1 0 0s
nop 0 0 0
str 2 0 0e
nop 0 0 0
str 3 0 0m
nop 0 0 0
str 4 0 0b
nop 0 0 0
str 5 0 0l
nop 0 0 0
str 2 0 0e
nop 0 0 0
str 6 0 0r
nop 0 0 0
str 7 0 0newline
nop 0 0 0
loa 0 0 0load input
nop 0 0 0
loa 0 0 1
nop 0 0 0
loa 0 0 2
nop 0 0 0
tgl 0 0 0switch to load from pram
add 1 2 0add last to chars together for compare
loa 0 0 1load first set for compare
nop 0 0 0
loa 0 0 2
nop 0 0 0
loa 0 0 3
nop 0 0 0
loa 0 0 4
nop 0 0 0
loa 0 0 5
nop 0 0 0
loa 0 0 6
nop 0 0 0
loa 0 0 7
nop 0 0 0
loa 0 0 8
nop 0 0 0
loa 0 0 9
nop 0 0 0
loa 0 0 10
nop 0 0 0
loa 0 0 11
nop 0 0 0
loa 0 0 12
nop 0 0 0
loa 0 0 13
nop 0 0 0
loa 0 0 14
nop 0 0 0
loa 0 0 15jump adress
nop 0 0 0
jeq 0 1 0jmp if r0=136
loa 0 0 15jump adress
nop 0 0 0
jeq 0 2 0jmp if r0=140
loa 0 0 15jump adress
nop 0 0 0
jeq 0 3 0jmp if r0=144
loa 0 0 15jump adress
nop 0 0 0
jeq 0 4 0jmp if r0=145
loa 0 0 15jump adress
nop 0 0 0
jeq 0 5 0jmp if r0=146
loa 0 0 15jump adress
nop 0 0 0
jeq 0 6 0jmp if r0=147
loa 0 0 15jump adress
nop 0 0 0
jeq 0 7 0jmp if r0=150
loa 0 0 15jump adress
nop 0 0 0
jeq 0 8 0jmp if r0=155
loa 0 0 15jump adress
nop 0 0 0
jeq 0 9 0jmp if r0=157
loa 0 0 15jump adress
nop 0 0 0
jeq 0 10 0jmp if r0=159
loa 0 0 15jump adress
nop 0 0 0
jeq 0 11 0jmp if r0=160
loa 0 0 15jump adress
nop 0 0 0
jeq 0 12 0jmp if r0=161
loa 0 0 15jump adress
nop 0 0 0
jeq 0 13 0jmp if r0=163
loa 0 0 15jump adress
nop 0 0 0
jeq 0 14 0jmp if r0=166
loa 0 0 15jmp to halt if all else fails
nop 0 0 0
jeq 0 0 0
loa 0 0 0load return val for r0=136
nop 0 0 0
loa 0 0 15jump to store
nop 0 0 0
jeq 0 0 0
loa 0 0 0load return val for r0=136
nop 0 0 0
loa 0 0 15jump to store
nop 0 0 0
jeq 0 0 0
loa 0 0 0load return val for r0=136
nop 0 0 0
loa 0 0 15jump to store
nop 0 0 0
jeq 0 0 0
loa 0 0 0load return val for r0=136
nop 0 0 0
loa 0 0 15jump to store
nop 0 0 0
jeq 0 0 0
loa 0 0 0load return val for r0=136
nop 0 0 0
loa 0 0 15jump to store
nop 0 0 0
jeq 0 0 0
loa 0 0 0load return val for r0=136
nop 0 0 0
loa 0 0 15jump to store
nop 0 0 0
jeq 0 0 0
loa 0 0 0load return val for r0=136
nop 0 0 0
loa 0 0 15jump to store
nop 0 0 0
jeq 0 0 0
loa 0 0 0load return val for r0=136
nop 0 0 0
loa 0 0 15jump to store
nop 0 0 0
jeq 0 0 0
loa 0 0 0load return val for r0=136
nop 0 0 0
loa 0 0 15jump to store
nop 0 0 0
jeq 0 0 0
loa 0 0 0load return val for r0=136
nop 0 0 0
loa 0 0 15jump to store
nop 0 0 0
jeq 0 0 0
loa 0 0 0load return val for r0=136
nop 0 0 0
loa 0 0 15jump to store
nop 0 0 0
jeq 0 0 0
loa 0 0 0load return val for r0=136
nop 0 0 0
loa 0 0 15jump to store
nop 0 0 0
jeq 0 0 0
loa 0 0 0load return val for r0=136
nop 0 0 0
loa 0 0 15jump to store
nop 0 0 0
jeq 0 0 0
loa 0 0 0load return val for r0=136
nop 0 0 0
loa 0 0 15jump to store
nop 0 0 0
jeq 0 0 0
str 0 0 0store return val in memory
nop 0 0 0
loa 0 0 0return to program start
nop 0 0 0
jqe 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0
nop 0 0 0

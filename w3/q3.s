#int u;
#int v = 42;
#char w;
#char x = 'a';
#double y;
#int z[20];
#char a[10] = {'X'};


.data
u: .space 4
v: .word 42
w: .space 1
x: .byte 'a'
.align 2
y: .space 8
z: .space 80
a: .byte  'X':10

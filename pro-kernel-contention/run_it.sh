# run: process_name module_name duration type

make clean > null 2> null
pidNow=$(pgrep -x -o $1)
varX=$2

echo "obj-m += $varX.o

def:
	make -C /lib/modules/\$(shell uname -r)/build M=\$(shell pwd) modules
clean:
	make -C /lib/modules/\$(shell uname -r)/build M=\$(shell pwd) clean
" > Makefile
 
cp pro_mod.c $2.c
make 2> null > null
insmod $2.ko pid_tmp=$pidNow timeX=$3 typex=$4 

dmesg | grep "promod $pidNow" > tst_out
g++ profileX.cpp
./a.out $3 < tst_out

# run: process_name module_name duration type periodic-gap

make clean > null 2> null
varX=$2

echo "obj-m += $varX.o

def:
	make -C /lib/modules/\$(shell uname -r)/build M=\$(shell pwd) modules
clean:
	make -C /lib/modules/\$(shell uname -r)/build M=\$(shell pwd) clean
" > Makefile
 
cp pro_mod.c $2.c
make 2> null > null

#filebench -f oltp.f &
pidNow=$(pgrep -x -o $1)

g++ profileX.cpp -o profileX.out

insmod $2.ko pid_tmp=$pidNow timeX=$3 typex=$4 & 
#echo "" > coreData

indX=0
echo "starting"
while [ $indX -lt $3 ]
do
	sleep $5
	indX=$(( $indX + $5 ))
	dmesg --read-clear | grep "promod $pidNow" > logX
	./profileX.out $3 $indX < logX >> coreData
done

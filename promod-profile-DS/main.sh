# Profile DS from log
# Read(and clear) log every $2-s(time gap) for $1-s(total duration) and profile it to generate data
# profileX.out is the profiler that generates data from dmesg log

g++ profileX.cpp -o profileX.out

echo -n "" > coreData-Q2
#echo -n "" > coreData-W
#echo -n "" > coreData-Q1
#echo -n "" > coreData-S1
#echo -n "" > coreData-S2

indX=0
echo "Starting"
while [ $indX -lt $1 ]
do
	echo $indX
	sleep $2
	indX=$(( $indX + $2 ))
	dmesg --read-clear | grep "profmod" > logX

	cat logX | grep "profmod S2" > logX-S2	
	#cat logX | grep "profmod W1" > logX-W
	#cat logX | grep "profmod Q1" > logX-Q1
	#cat logX | grep "profmod S1" > logX-S1
	#cat logX | grep "profmod Q2" > logX-Q2
	
	
	./profileX.out $indX < logX-Q2 >> coreData-Q2
	#./profileX.out $indX < logX-Q1 >> coreData-Q1
	#./profileX.out $indX < logX-S1 >> coreData-S1	
	#./profileX.out $indX < logX-W >> coreData-W
	#./profileX.out $indX < logX-S2 >> coreData-S2
done

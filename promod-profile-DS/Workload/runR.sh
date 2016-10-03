# Create Workload mutiple threads and large memory
i=0
cd ../shRCU/rlu-master/

while [ $i -lt 800 ]
do
	./run_all.sh	
	i=$(($i + 5))
done

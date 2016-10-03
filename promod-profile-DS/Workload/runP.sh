# Create multiple Threads
i=0
gcc -pthread processX.c -o processX.out

while [ $i -lt 800 ]
do
	./processX.out 1900 
	sleep 5
	i=$(($i + 5))
done

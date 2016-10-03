# Filebench OLTP Workload

i=0
while [ $i -lt 800 ]
do
	filebench -f oltp.f 
done

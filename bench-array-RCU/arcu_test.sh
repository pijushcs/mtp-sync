n=1
nT=$1
echo $nT

rm arcu_out_2
make clean > null
make 2> null > null

while [ $n -le $nT ]
do
	echo -n $n" "
	./bench-arcu -b$2 -d10000 -i10000 -r20000 -w$3 -u$4 -n$n | grep '#ops' | gawk -v var=$n '{print var" "$3}' >> arcu_out_2
	n=`expr $n + 1`

	tail -1 arcu_out_2
	sleep 2
done

cat arcu_out_2 | gawk '{print $1" "$2/10000}' > $5

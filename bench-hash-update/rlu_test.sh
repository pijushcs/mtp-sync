n=1
nT=$1
echo $nT

rm rlu_out_2

while [ $n -lt $nT ]
do
	echo $n
	make clean > null
	make nsize=64 2> null > null
	./bench-rlu -b$2 -d10000 -i10000 -r20000 -w$3 -u$4 -n$n | grep '#ops' | gawk -v var=$n '{print var" "$3}' >> rlu_out_2
	n=`expr $n + 1`
	sleep 2
done

cat rlu_out_2 | gawk '{print $1" "$2/10000}' > $5


n=0
nT=`expr $1 \* 4 \* 1024`
echo $nT

rm rlu_out_2

while [ $n -lt $nT ]
do
	echo $n
	make clean > null
	make nsize=$n > null 2>null
	./bench-rlu -a -b$2 -d10000 -i10000 -r20000 -w$3 -u$4 -n16 | grep '#ops' | gawk -v var=$n '{print var" "$3}' >> rlu_out_2
	n=`expr $n + 128`
	sleep 2
done

cat rlu_out_2 | gawk '{print $1" "log($2)}' > $5

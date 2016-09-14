set term png size 600, 600
set boxwidth 4.5
set style fill solid 1.00 border lt -1
set yrange [0:2]
set title "Per Core Contetntion"
set xlabel "Time(s)"
set ylabel "Contention per-core(us) / Write Percentage[cdf]"
set output "pro-con.png"
plot 'coreData' using 1:2 with boxes title 'core 0', 'coreData' using 1:4 with boxes title 'core 1', 'coreData' using 1:6 with boxes title 'core 2', 'coreData' using 1:8 with boxes title 'core 3', 'coreData' using 1:10 with points title 'write-readd ratio'

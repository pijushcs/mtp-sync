set term png size 800, 800
set boxwidth 5.5
set style fill transparent pattern 1.00 border lt -1
set yrange [0:1]
set xrange [0:615]
set title "Per Core Contetntion"
set xlabel "Time(s)"
set ylabel "Contention per-core(ms)"
set output "pro-con.png"
plot 'coreData' using 1:2 with boxes title 'core 0', 'coreData' using 1:4 with boxes title 'core 1', 'coreData' using 1:6 with boxes title 'core 2', 'coreData' using 1:8 with boxes title 'core 3'

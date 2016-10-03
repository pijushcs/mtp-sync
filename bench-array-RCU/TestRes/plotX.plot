set term png size 600, 600
set boxwidth 0.2
set style fill solid 1.00 border lt -1
set yrange [0:2000]
set xrange [0:17]
set title "Comparison between RCU and RLU"
set xlabel "No of Threads"
set ylabel "No of ops/ms"
set output "res-read.png"
plot 'arcu_out_read' using 1:2 with boxes title 'A-RCU' , 'rcu_out_read' using 1:2 with boxes title 'RCU' 

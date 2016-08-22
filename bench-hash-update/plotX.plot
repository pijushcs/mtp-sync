set term png size 600, 600
# set size 0.5, 0.5
set yrange [0:100000]
set xrange [1:16]
set title "Comparison between RCU and RLU"
set xlabel "No of Threads"
set ylabel "No of ops"
set output "comp.png"
plot 'rcu_out' using 1:2 with lines title 'RCU', 'rlu_out' using 1:2 with lines title 'RLU' 

# to-do: auto all tests [done] :D
# test.sh n_threads:31 n_buckets:20 n_wset:10 n_write_ops:200

echo "L: Read"
./testX.sh 16 1 10 1 arcu_out_read rcu_out_read
echo "L: 20"
./testX.sh 16 1 10 200 arcu_out_l20 rcu_out_l20
echo "L: 40"
./testX.sh 16 1 10 400 arcu_out_l40 rcu_out_l40
echo "L: 60"
./testX.sh 16 1 10 600 arcu_out_l60 rcu_out_l60
echo "L: 80"
./testX.sh 16 1 10 800 arcu_out_l80 rcu_out_l80
echo "L: 1000"
./testX.sh 16 1 10 1000 arcu_out_l100 rcu_out_l100

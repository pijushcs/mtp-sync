# to-do: auto all tests [done] :D
# test.sh n_threads:31 n_buckets:20 n_wset:10 n_write_ops:200

echo "L: 20 10 200"
./testX.sh 16 1 10 1 rcu_out_l_read rlu_out_l_read
echo "L: 20 1 200"
./testX.sh 16 1 1 200 rcu_out_l20 rlu_out_l20
echo "L: 20 1 400"
./testX.sh 16 1 1 400 rcu_out_l40 rlu_out_l40
echo "L: 20 10 200"
./testX.sh 16 1 10 200 rcu_out_l20_10 rlu_out_l20_10
echo "L: 40 10 400"
./testX.sh 16 1 10 400 rcu_out_l40_10 rlu_out_l40_10
echo "L: 20 20 200"
./testX.sh 16 1 20 200 rcu_out_l20_20 rlu_out_l20_20
echo "L: 40 20 400"
./testX.sh 16 1 20 400 rcu_out_l40_20 rlu_out_l40_20

echo "H: 20 10 200"
./testX.sh 16 30 10 1 rcu_out_hl_read rlu_out_hl_read
echo "H: 20 1 200"
./testX.sh 16 30 1 200 rcu_out_hl20 rlu_out_hl20
echo "H: 20 1 400"
./testX.sh 16 30 1 400 rcu_out_hl40 rlu_out_hl40
echo "H: 20 10 200"
./testX.sh 16 30 10 200 rcu_out_hl20_10 rlu_out_hl20_10
echo "H: 40 10 400"
./testX.sh 16 30 10 400 rcu_out_hl40_10 rlu_out_hl40_10
echo "H: 20 20 200"
./testX.sh 16 30 20 200 rcu_out_hl20_20 rlu_out_hl20_20
echo "H: 40 20 400"
./testX.sh 16 30 20 400 rcu_out_hl40_20 rlu_out_hl40_20

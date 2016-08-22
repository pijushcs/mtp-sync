# test.sh n_pages:5 n_buckets:20 n_wset:10 n_write_ops:200
echo -n "[RCU]: "
./rcu_test.sh $1 $2 $3 $4 $5

echo -n "[RLU]: "
./rlu_test.sh $1 $2 $3 $4 $6


CONTENTION PER CORE: 
Cycles wasted per core for threads waiting to get hold of the write lock
[http://www.cse.iitb.ac.in/synerg/doku.php?id=public:students:pijush:read-write]
====================================================================================

Authors
-------
Name:  Pijush Chakraborty
Email: pijush@cse.iitb.ac.in

GENERAL
=====================

To study the level of contention, this test tries to find the no of cycles a writer
wastes inorder to get hold of the lock.

To run the profiler, execute:
./rcu_test.sh [#npages] [#buckets] [#wset] [#update rate] [#file rcu]
./profileX.out [#type] < [#file rcu]  

Note: 
#type: 'C' for RCU/ 'L' for RLU
profileX.cpp must be compiled with g++

Output: 
[#core] [#avg wait %] [#max wait %]

To run the entire tests, execute:
./run_all.sh
./newT.sh

The original benchmark-code can be found here: https://github.com/rlu-sync/rlu

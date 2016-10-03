# Main script to find count of Kernel RCU-list DS

cat log | grep "list_add_rcu*" > RCUset
cat log | grep "list_add_tail_rcu*" > RCUque
cat log | grep "hlist_add_head_rcu*" > RCUhset
cat log | grep "hlist_add_*" > RCUhall
cat log | grep "queue*" | grep "list_add*" > RCUaque

echo "END" >> RCUset
echo "END" >> RCUque
echo "END" >> RCUhset
echo "END" >> RCUhall
echo "END" >> RCUaque

g++ findRCU.cpp -o findRCU.out

./findRCU.out < RCUset > lSet  	#all Set
./findRCU.out < RCUque > lQue   #all Q
./findRCU.out < RCUaque > lQAct #all actQ
./findRCU.out < RCUhset > hlSet #all hSet
./findRCU.out < RCUhall > hlAll #all HL

cSet=$(cat lSet | wc -l )
cQue=$(cat lQue | wc -l )
cHSet=$(cat hlSet | wc -l)
cQAct=$(cat lQAct | wc -l)
cHAll=$(cat hlAll | wc -l)
cHQue=$(($cHAll - $cHSet))

# RCU-lists used as Set
echo "SET: "$cSet		
# RCU-lists used as Queue
echo "QUE: "$cQue
# RCU-lists having queue is list-head name
echo "QAC: "$cQAct
# RCU Hash-Lists
echo "HLS: "$cHSet
# RCU Hash-Lists used as Q?
echo "HQE: "$cHQue

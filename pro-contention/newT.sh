g++ profileX.cpp

echo "RCU L 20% writes [No Defer]" 
./a.out C < rcu_out_l20
echo ""

echo "RLU L 20% writes [No Defer]" 
./a.out L < rlu_out_l20
echo ""

echo "RCU L 40% writes [No Defer]" 
./a.out C < rcu_out_l40
echo ""

echo "RLU L 40% writes [No Defer]" 
./a.out L < rlu_out_l40
echo ""

echo "RCU L 20% writes [Defer]" 
./a.out C < rcu_out_l20_10
echo ""

echo "RLU L 20% writes [Defer]" 
./a.out L < rlu_out_l20_10
echo ""

echo "RCU L 40% writes [Defer]" 
./a.out C < rcu_out_l40_10
echo ""

echo "RLU L 40% writes [Defer]" 
./a.out L < rlu_out_l40_10
echo ""

echo "RCU HL 20% writes [No Defer]" 
./a.out C < rcu_out_hl20
echo ""

echo "RLU HL 20% writes [No Defer]" 
./a.out L < rlu_out_hl20
echo ""

echo "RCU HL 40% writes [No Defer]" 
./a.out C < rcu_out_hl40
echo ""

echo "RLU HL 40% writes [No Defer]" 
./a.out L < rlu_out_hl40
echo ""

echo "RCU HL 20% writes [Defer]" 
./a.out C < rcu_out_hl20_10
echo ""

echo "RLU HL 20% writes [Defer]" 
./a.out L < rlu_out_hl20_10
echo ""

echo "RCU HL 40% writes [Defer]" 
./a.out C < rcu_out_hl40_10
echo ""

echo "RLU HL 40% writes [Defer]" 
./a.out L < rlu_out_hl40_10
echo ""


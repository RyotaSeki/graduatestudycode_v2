#set -e

root -l ccbardeltaeminv.C &  pids[0]=$!
root -l ddbardeltaeminv.C &  pids[1]=$!
root -l ssbardeltaeminv.C &  pids[2]=$!
root -l uubardeltaeminv.C &  pids[3]=$!
root -l eeeedeltaeminv.C  &  pids[4]=$!
root -l ee_ecldigitsdeltaeminv.C & pids[5]=$!
root -l mumu_ecldigitsdeltaeminv.C & pids[6]=$!
root -l eeisrdeltaeminv.C & pids[7]=$!
root -l taupairdeltaeminv.C &  pids[8]=$!
root -l mugammadeltaeminv.C &  pids[9]=$!

wait ${pids[0]}
wait ${pids[1]}
wait ${pids[2]}
wait ${pids[3]}
wait ${pids[4]}
wait ${pids[5]}
wait ${pids[6]}
wait ${pids[7]}
wait ${pids[8]}
wait ${pids[9]}

#set -e


root -l testmugamma.C &  pids[0]=$!
root -l greattestmugamma.C &  pids[1]=$!

wait ${pids[0]}
wait ${pids[1]}

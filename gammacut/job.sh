#set -e

root -l /home/usr/data/belle2/mc/BGx1/uubar_BGx1_0010_pi.root /home/usr/data/belle2/mc/BGx1/uubar_BGx1_0010_gamma.root 'gammacut.C("uubar")' &  pids[0]=$!
root -l /home/usr/data/belle2/mc/BGx1/ssbar_BGx1_0011_pi.root /home/usr/data/belle2/mc/BGx1/ssbar_BGx1_0011_gamma.root 'gammacut.C("ssbar")' &  pids[1]=$!
root -l /home/usr/data/belle2/mc/BGx1/eeee_BGx1_0010_pi.root  /home/usr/data/belle2/mc/BGx1/eeee_BGx1_0010_gamma.root  'gammacut.C("eeee")'  &  pids[2]=$!
root -l /home/usr/data/belle2/mc/BGx1/ccbar_BGx1_0010_pi.root /home/usr/data/belle2/mc/BGx1/ccbar_BGx1_0010_gamma.root 'gammacut.C("ccbar")' &  pids[3]=$!
root -l /home/usr/data/belle2/mc/BGx1/taupair_BGx1_0010_pi.root /home/usr/data/belle2/mc/BGx1/taupair_BGx1_0010_gamma.root 'gammacut.C("taupair")' &  pids[4]=$!

wait ${pids[0]}
wait ${pids[1]}
wait ${pids[2]}
wait ${pids[3]}
wait ${pids[4]}

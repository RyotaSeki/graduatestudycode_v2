#set -e

root -l /home/usr/data/belle2/mc/BGx1/uubar_BGx1_0010_pi.root /home/usr/data/belle2/mc/BGx1/uubar_BGx1_0010_gamma.root 'gammacut.C("uubar")' &  
root -l /home/usr/data/belle2/mc/BGx1/ssbar_BGx1_0011_pi.root /home/usr/data/belle2/mc/BGx1/ssbar_BGx1_0011_gamma.root 'gammacut.C("ssbar")' &  
root -l /home/usr/data/belle2/mc/BGx1/eeee_BGx1_0010_pi.root  /home/usr/data/belle2/mc/BGx1/eeee_BGx1_0010_gamma.root  'gammacut.C("eeee")'  &  
root -l /home/usr/data/belle2/mc/BGx1/ccbar_BGx1_0010_pi.root /home/usr/data/belle2/mc/BGx1/ccbar_BGx1_0010_gamma.root 'gammacut.C("ccbar")' &  
root -l /home/usr/data/belle2/mc/BGx1/taupair_BGx1_0010_pi.root /home/usr/data/belle2/mc/BGx1/taupair_BGx1_0010_gamma.root 'gammacut.C("taupair")' &  


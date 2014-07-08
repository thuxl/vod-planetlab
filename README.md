vod-planetlab
=============

vod planetlab, p2p system

This code is for paper Vod model. It constructs a p2p system, where each peer runs itsself to meet its needs.


usage step:

1. cd bandwidth; make clean; make; ./p_program ;
# the first step is to generate initial data for experiment.
2. cd .. ; make clean; make ;
# to generate pgetip file
3. ./pgetip
# to generate shell files 
4. make -j50 ; ./upload
#to upload files to planetlab nodes. 
5. ./p_server
# the local machine is server, the nodes of planetlab are peers
6. ./vxargs-latest.py -a iplist.txt -o ./result/ -P 200 ssh -l planetlab_username -i id_rsa {} "~/run"
# run peers of planetlab.

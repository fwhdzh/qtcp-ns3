# qtcp-ns3

this is the implementation of the paper "QTCP: Adaptive Congestion Control
with Reinforcement Learning".

this repository is not maintained by the paper's author. It is just created because of my supervisor asked me to implement it in order to do our own peoject.

this implement is not accomplished. In fact, it just in initial phase. So you may feel disappointment if you are looking for a finished version of the paper's code. By the way, I have searched github for the author's code and send an email to the first author and the second author. However, I didn't get the code.

I will complete this repository in the futrue. However, It may be a diffcult task for me as I am an undergraduate who is not outstanding. Therefore, I don't konw when I can finish it. 

If you want to run this respositoty. Besides download this respository in the src folder in you ns3, you also need to create a file in the scratch. After build, you can include "qtcp-module.h" and make call of the function of class in the namespace qtcp such as "qtcp::simulate(argc,argv);" or "qtcp::TerminalApplication app;" in the scratch file you just created. And then build ns3 again and run you scratch. It is designed as a ns3 module and you can lenrn more about the moudle from [Adding a New Module to ns-3](https://www.nsnam.org/docs/manual/html/new-modules.html).

# Abandon

I have given up this project since I am not doing any work about network and reinforcement learning now. If you are interested in this paper, I am sorry for that you may need to implement it with yourself.

#ifndef RLTRAINER_H
#define RLTRAINER_H

#include <fstream>
#include <string>
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/stats-module.h"
#include "ns3/QTCPSimulator.h"

using namespace ns3;
using namespace std;

namespace qtcp
{

    const int actions[] = {10,-1,0};

    struct state
    {
        double avg_send = 0;
        double avg_ack = 0;
        double avg_rtt = 0;

        bool operator<(const qtcp::state &o) const
        {
            if (avg_send < o.avg_send)
                return true;
            if (avg_ack < o.avg_ack)
                return true;
            if (avg_rtt < o.avg_rtt)
                return true;
            return false;
        }
    };

    

    class RLTrainer
    {
    private:
        /* data */
        const double utilityParamA = 0.9;   //论文中未提具体数值
        const double utilityParamB = 0.1;   //论文中未提具体数值
        double learningRate = 0.95;    

        double discountFactor = 0.9; 

        double instantReward = 0; //论文中未提具体数据
        

        qtcp::state lastState;
        qtcp::state currentState;

        map<state, double[3]> qTable;

    public:
        RLTrainer(/* args */);
        ~RLTrainer();

        double utility(double throughput, double RTT);

        double qValue(state state, int action);
    };

    RLTrainer::RLTrainer(/* args */)
    {
    }

    RLTrainer::~RLTrainer()
    {
    }

} // namespace qtcp

#endif
#include "RLTrainer.h"

using namespace ns3;
using namespace qtcp;

namespace qtcp{
    double 
    RLTrainer::utility(double throughput, double RTT){
        return RLTrainer::utilityParamA*throughput - utilityParamB*RTT;
    }

    
}
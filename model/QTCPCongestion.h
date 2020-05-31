#ifndef QTCPCONGESTION_H
#define QTCPCONGESTION_H

#include <fstream>
#include <string>
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/stats-module.h"
#include "TerminalApplication.h"
#include "ns3/csma-module.h"
#include "ns3/flow-monitor-module.h"
#include "ns3/ptr.h"
#include "ns3/point-to-point-layout-module.h"
// #include "ns3/point-to-point-dumbbell.h"

using namespace ns3;
using namespace std;

namespace qtcp{

    

    class QTCPCongestion : public TcpCongestionOps
    {
    private:
        /* data */


    // protected:
    //     virtual uint32_t SlowStart (Ptr<TcpSocketState> tcb, uint32_t segmentsAcked);
    //     virtual void CongestionAvoidance (Ptr<TcpSocketState> tcb, uint32_t segmentsAcked);
  
    public:
        QTCPCongestion(/* args */);
        ~QTCPCongestion();

        static TypeId GetTypeId (void);

        std::string GetName () const;

        virtual void IncreaseWindow (Ptr<TcpSocketState> tcb, uint32_t segmentsAcked);
        virtual uint32_t GetSsThresh (Ptr<const TcpSocketState> tcb,
                                uint32_t bytesInFlight);

        virtual Ptr<TcpCongestionOps> Fork ();

        virtual void PktsAcked (Ptr<TcpSocketState> tcb, uint32_t segmentsAcked, const Time& rtt);
        
    };
    
    QTCPCongestion::QTCPCongestion(/* args */)
    {
        
    }
    
    QTCPCongestion::~QTCPCongestion()
    {
    }
    
}

#endif

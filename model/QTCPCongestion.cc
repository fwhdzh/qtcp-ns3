#include "QTCPCongestion.h"

using namespace ns3;
using namespace qtcp;

namespace qtcp
{
    TypeId
    QTCPCongestion::GetTypeId(void)
    {
        static TypeId tid = TypeId("qtcp::QTCPCongestion")
                                .SetParent<TcpCongestionOps>()
                                .SetGroupName("qtcp")
                                .AddConstructor<QTCPCongestion>();
        return tid;
    }

    QTCPCongestion::QTCPCongestion(void) : TcpCongestionOps()
    {
        NS_LOG_FUNCTION(this);
    }

    QTCPCongestion::QTCPCongestion(const QTCPCongestion &sock)
        : TcpCongestionOps(sock)
    {
        NS_LOG_FUNCTION(this);
    }

    QTCPCongestion::~QTCPCongestion(void)
    {
    }

    void
    QTCPCongestion::PktsAcked(Ptr<TcpSocketState> tcb, uint32_t segmentsAcked, const Time &rtt)
    {
        // interval_ack++;
    }

    //     void
    //     QTCPCongestion::IncreaseWindow(Ptr<TcpSocketState> tcb, uint32_t segmentsAcked)
    //     {
    //         NS_LOG_FUNCTION(this << tcb << segmentsAcked);

    //         if (tcb->m_cWnd < tcb->m_ssThresh)
    //         {
    //             segmentsAcked = SlowStart(tcb, segmentsAcked);
    //         }

    //         if (tcb->m_cWnd >= tcb->m_ssThresh)
    //         {
    //             CongestionAvoidance(tcb, segmentsAcked);
    //         }

    //         /* At this point, we could have segmentsAcked != 0. This because RFC says
    //    * that in slow start, we should increase cWnd by min (N, SMSS); if in
    //    * slow start we receive a cumulative ACK, it counts only for 1 SMSS of
    //    * increase, wasting the others.
    //    *
    //    * // Incorrect assert, I am sorry
    //    * NS_ASSERT (segmentsAcked == 0);
    //    */
    //     }

} // namespace qtcp
#ifndef TERMINALAPPLICATION_H
#define TERMINALAPPLICATION_H


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
  class TerminalApplication : public Application
  {
  public:
    TerminalApplication();
    virtual ~TerminalApplication();

    /**
   * Register this type.
   * \return The TypeId.
   */
    static TypeId GetTypeId(void);
    void Setup(Ptr<Socket> socket, Address address, uint32_t packetSize, uint32_t nPackets, DataRate dataRate);

  private:
    virtual void StartApplication(void);
    virtual void StopApplication(void);

    void ScheduleTx(void);
    void SendPacket(void);

    AsciiTraceHelper asciiHelper;
    Ptr<OutputStreamWrapper> cwndStream;

    Ptr<Socket> m_socket;
    Address m_peer;
    uint32_t m_packetSize;
    uint32_t m_nPackets;
    DataRate m_dataRate;
    EventId m_sendEvent;
    bool m_running;
    uint32_t m_packetsSent;
  };
} // namespace qtcp

#endif
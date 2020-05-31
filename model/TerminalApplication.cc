#include "TerminalApplication.h"

namespace qtcp
{
  TerminalApplication::TerminalApplication()
      : m_socket(0),
        m_peer(),
        m_packetSize(0),
        m_nPackets(0),
        m_dataRate(0),
        m_sendEvent(),
        m_running(false),
        m_packetsSent(0)
  {

  }

  TerminalApplication::~TerminalApplication()
  {
    m_socket = 0;
  }

  /* static */
  TypeId TerminalApplication::GetTypeId(void)
  {
    static TypeId tid = TypeId("TerminalApplication")
                            .SetParent<Application>()
                            .SetGroupName("QTCP")
                            .AddConstructor<TerminalApplication>();
    return tid;
  }

  void
  TerminalApplication::Setup(Ptr<Socket> socket, Address address, uint32_t packetSize, uint32_t nPackets, DataRate dataRate)
  {

    

    m_socket = socket;
    m_peer = address;
    m_packetSize = packetSize;
    m_nPackets = nPackets;
    m_dataRate = dataRate;
  }

  void
  TerminalApplication::StartApplication(void)
  {

    ostringstream oss;
    oss << "qtcp-" << m_node->GetId() << ".cwnd";
    cwndStream =  asciiHelper.CreateFileStream(oss.str());
    this->TraceConnectWithoutContext("CongestionWindow", MakeBoundCallback(&CwndChange, cwndStream));
    
    m_running = true;
    m_packetsSent = 0;
    if (InetSocketAddress::IsMatchingType(m_peer))
    {
      m_socket->Bind();
    }
    else
    {
      m_socket->Bind6();
    }
    m_socket->Connect(m_peer);
    SendPacket();
  }

  void
  TerminalApplication::StopApplication(void)
  {
    m_running = false;

    if (m_sendEvent.IsRunning())
    {
      Simulator::Cancel(m_sendEvent);
    }

    if (m_socket)
    {
      m_socket->Close();
    }
  }

  void
  TerminalApplication::SendPacket(void)
  {
    Ptr<Packet> packet = Create<Packet>(m_packetSize);
    m_socket->Send(packet);

    // cout << Simulator::Now().GetSeconds() << "\t" << m_peer << "\n";
    // this->TraceConnectWithoutContext("Tx", MakeBoundCallback(&qtcp::SendPacketCallBack, qtcp::appTxStream));
    if (++m_packetsSent < m_nPackets)
    {
      ScheduleTx();
    }
  }

  void
  TerminalApplication::ScheduleTx(void)
  {
    if (m_running)
    {
      Time tNext(Seconds(m_packetSize * 8 / static_cast<double>(m_dataRate.GetBitRate())));
      // Time tNext = Simulator::Now()+NanoSeconds(1);
      m_sendEvent = Simulator::Schedule(tNext, &TerminalApplication::SendPacket, this);
    }
  }
} // namespace qtcp

#ifndef QTCPSIMULATOR_H
#define QTCPSIMULATOR_H

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
#include "QTCPCongestion.h"
#include "RLTrainer.h"
// #include "ns3/point-to-point-dumbbell.h"



using namespace ns3;
using namespace std;

namespace qtcp
{
  const string dataRateStr = "40Mbps";
  const string delayStr = "1ns";
  const double errorRate = 0.00001;
  const int nCsma = 5;
  const string csmaDataRateStr = "100Mbps";
  const string appDataRateStr = "100Mbps";
  const int appPackets = 1000;
  // const TimeValue csmaTimeValue = TimeValue (NanoSeconds (6560));
  const TimeValue csmaTimeValue = TimeValue (NanoSeconds (6));
  // const AsciiTraceHelper asciiTraceHelper;
  // const Ptr<OutputStreamWrapper> appTxStream = asciiTraceHelper.CreateFileStream("QTCP.app_Send_packet");

  // NS_LOG_COMPONENT_DEFINE("QTCPSimulator3");

  int interval_send = 0;
  int interval_ack = 0;
  double interval_rtt = 0;
  

  void
  CwndChange(Ptr<OutputStreamWrapper> stream, uint32_t oldCwnd, uint32_t newCwnd);

  //丢包时发生
  void
  RxDrop(Ptr<PcapFileWrapper> file, Ptr<const Packet> p);

  void 
  AckReceive(Ptr<OutputStreamWrapper> stream, SequenceNumber32 oldAck, SequenceNumber32 newAck);

  void 
  SendPacketCallBack(Ptr<OutputStreamWrapper> stream, const Ptr< const Packet > packet, const TcpHeader &header, const Ptr< const TcpSocketBase > socket);

  void 
  ReceivePacketCallBack(Ptr<OutputStreamWrapper> stream, const Ptr< const Packet > packet, const TcpHeader &header, const Ptr< const TcpSocketBase > socket);

  void 
  RttChange(Ptr<OutputStreamWrapper> stream, Time oldValue, Time newValue);

  void
  TcpStateChange(Ptr<OutputStreamWrapper> stream, const TcpSocket::TcpStates_t oldValue, const TcpSocket::TcpStates_t newValue);

  // void 
  // deploy();

  int simulate(int argc, char *argv[]);
}

#endif
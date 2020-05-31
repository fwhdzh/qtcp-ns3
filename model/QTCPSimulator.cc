#include "header.h"
// #include "TerminalApplication.h"
#include "QTCPSimulator.h"

using namespace qtcp;

void qtcp::CwndChange(Ptr<OutputStreamWrapper> stream, uint32_t oldCwnd, uint32_t newCwnd)
{
  // NS_LOG_UNCOND(Simulator::Now().GetSeconds() << "\t" << newCwnd);
  // std::cout<<"Time:"<<Simulator::Now()<<"\n";
  *stream->GetStream() << Simulator::Now().GetSeconds() << "\t" << oldCwnd << "\t" << newCwnd << std::endl;
}

void qtcp::RxDrop(Ptr<PcapFileWrapper> file, Ptr<const Packet> p)
{
  // NS_LOG_UNCOND("RxDrop at " << Simulator::Now().GetSeconds());
  file->Write(Simulator::Now(), p);
}

void qtcp::AckReceive(Ptr<OutputStreamWrapper> stream, SequenceNumber32 oldAck, SequenceNumber32 newAck)
{
  interval_ack++;
  *stream->GetStream() << Simulator::Now().GetSeconds() << "\t" << oldAck.GetValue() << "\t" << newAck.GetValue() << std::endl;
}

void qtcp::SendPacketCallBack(Ptr<OutputStreamWrapper> stream, const Ptr< const Packet > packet, const TcpHeader &header, const Ptr< const TcpSocketBase > socket)
{
  interval_send++;
  *stream->GetStream() << Simulator::Now().GetSeconds() << "\t" <<header <<"\n";
}

void qtcp::ReceivePacketCallBack(Ptr<OutputStreamWrapper> stream, const Ptr< const Packet > packet, const TcpHeader &header, const Ptr< const TcpSocketBase > socket)
{
  *stream->GetStream() << Simulator::Now().GetSeconds() << "\n";
}

void qtcp::RttChange(Ptr<OutputStreamWrapper> stream, Time oldValue, Time newValue)
{
  *stream->GetStream() << Simulator::Now().GetSeconds() << "\t" << oldValue << "\t" << newValue << std::endl;
}

void qtcp::TcpStateChange(Ptr<OutputStreamWrapper> stream, const TcpSocket::TcpStates_t oldValue, const TcpSocket::TcpStates_t newValue)
{
  *stream->GetStream() << Simulator::Now().GetSeconds() << "\t" << oldValue << "\t" << newValue << std::endl;
}

void deploy(){

  // probeType = "ns3::Ipv4PacketProbe";
  // tracePath = "/NodeList/*/$ns3::Ipv4L3Protocol/Tx";

  // PacketSink好像没有用？先注释掉这一部分
  // PacketSinkHelper packetSinkHelper("ns3::TcpSocketFactory",anyAddress);
  // ApplicationContainer sinkApps = packetSinkHelper.Install(nodes.Get(1));
  // sinkApps.Start(Seconds(0.));
  // sinkApps.Stop(Seconds(20.));

  // Ptr<Socket> ns3TcpSocket = Socket::CreateSocket(nodes.Get(0), TcpSocketFactory::GetTypeId());
  
}

int qtcp::simulate(int argc, char *argv[])
{

  /* code */
  CommandLine cmd;
  cmd.Parse(argc, argv);

  NodeContainer p2pNodes;
  p2pNodes.Create(2);

  //公用配置
  InternetStackHelper stack;
  Ipv4AddressHelper address;

  // //p2p
  PointToPointHelper pointToPoint;
  pointToPoint.SetDeviceAttribute("DataRate", StringValue(dataRateStr));
  pointToPoint.SetChannelAttribute("Delay", StringValue(delayStr)); //Delay参数在论文中似乎没有提及，这里使用2ms.

  // NetDeviceContainer p2pDevices;
  // p2pDevices = pointToPoint.Install(p2pNodes);

  // Ptr<RateErrorModel> em = CreateObject<RateErrorModel>();
  // em->SetAttribute("ErrorRate", DoubleValue(errorRate));
  // p2pDevices.Get(1)->SetAttribute("ReceiveErrorModel", PointerValue(em));

  // // stack.Install(p2pNodes);

  // // address.SetBase("10.1.2.0", "255.255.255.0");
  // // Ipv4InterfaceContainer interfaces = address.Assign(p2pDevices);

  // // cout<<"Alu";
  
  // // NodeContainer clientDumbberNodes;
  // // clientDumbberNodes.Add(p2pNodes.Get(0));
  // // clientDumbberNodes.Create(1);


  
  // // NetDeviceContainer 



  // //Csma配置
  // CsmaHelper csma;
  // csma.SetChannelAttribute ("DataRate", StringValue (csmaDataRateStr));
  // csma.SetChannelAttribute ("Delay", csmaTimeValue);

  // //client端
  // NodeContainer clientNodes;
  // clientNodes.Add(p2pNodes.Get(0));
  // clientNodes.Create(nCsma);


  // NetDeviceContainer clientDevice;
  // clientDevice = csma.Install(clientNodes);

  // stack.Install(clientNodes);
  
  // address.SetBase ("10.1.1.0", "255.255.255.0");
  // Ipv4InterfaceContainer clientInterfaces;
  // clientInterfaces = address.Assign (clientDevice);

  // //server端
  // NodeContainer serverNodes;
  // serverNodes.Add(p2pNodes.Get(1));
  // serverNodes.Create(nCsma);
  
  // NetDeviceContainer serverDevice;
  // serverDevice = csma.Install(serverNodes);

  // stack.Install(serverNodes);

  // address.SetBase ("10.1.3.0", "255.255.255.0");
  // Ipv4InterfaceContainer serverInterfaces;
  // serverInterfaces = address.Assign (serverDevice);

  // //为p2p配置ip
  // address.SetBase("10.1.2.0", "255.255.255.0");
  // Ipv4InterfaceContainer interfaces = address.Assign(p2pDevices);
  

  // uint16_t sinkPort = 8080;
  // Address sinkAddress;
  // Address anyAddress;
  // // std::string probeType;
  // // std::string tracePath;

  // // p2p
  // // sinkAddress = InetSocketAddress(interfaces.GetAddress(1), sinkPort);
  // // anyAddress = InetSocketAddress(Ipv4Address::GetAny(), sinkPort);

  // //server端安装SinkApplication
  // for (int i = 1; i<=nCsma; i++)
  // {
  //   sinkAddress = InetSocketAddress(serverInterfaces.GetAddress(i), sinkPort);
  //   anyAddress = InetSocketAddress(Ipv4Address::GetAny(), sinkPort);
  //   PacketSinkHelper packetSinkHelper("ns3::TcpSocketFactory",anyAddress);
  //   ApplicationContainer sinkApps = packetSinkHelper.Install(serverNodes.Get(i));
  //   sinkApps.Start(Seconds(0.));
  //   sinkApps.Stop(Seconds(20.));
  // }

  // Ptr<Socket> serverTcpSocket = Socket::CreateSocket(serverNodes.Get(1), TcpSocketFactory::GetTypeId());
  // Ptr<Socket> clientTcpSocket = Socket::CreateSocket(clientNodes.Get(2), TcpSocketFactory::GetTypeId());

  // Socket::CreateSocket(p2pNodes.Get(0),TcpSocketFactory::GetTypeId());
  // Socket::CreateSocket(p2pNodes.Get(1),TcpSocketFactory::GetTypeId());

  // Ptr<TerminalApplication> app = CreateObject<TerminalApplication>();
  // // app->Setup(ns3TcpSocket, sinkAddress, 1040, 1000, DataRate("1Mbps"));
  // sinkAddress = InetSocketAddress(serverInterfaces.GetAddress(1), sinkPort);
  // // sinkAddress = serverInterfaces.GetAddress(1);
  // cout << serverInterfaces.Get(1).first << "\t" << serverInterfaces.Get(1).second << "\n";
  // app->Setup(clientTcpSocket, sinkAddress, 1040, appPackets, DataRate(appDataRateStr));
  // clientNodes.Get(2)->AddApplication(app);
  // app->SetStartTime(Seconds(1.));
  // app->SetStopTime(Seconds(20.));


  uint16_t sinkPort = 8080;
  Address sinkAddress;
  Address anyAddress;

   // PointToPointDumbbell
  Ipv4AddressHelper leftAddress, rightAddress, routerAddress;
  leftAddress.SetBase("10.1.4.0","255.255.255.252");
  rightAddress.SetBase("10.1.5.0","255.255.255.252");
  routerAddress.SetBase("10.1.6.0","255.255.255.252");
  PointToPointDumbbellHelper p2pDumbbelHelper(nCsma,pointToPoint,nCsma,pointToPoint,pointToPoint);
  
  p2pDumbbelHelper.InstallStack(stack);
  p2pDumbbelHelper.AssignIpv4Addresses(leftAddress, rightAddress, routerAddress);

  

  for (int i = 0; i<nCsma; i++)
  {
    sinkAddress = InetSocketAddress(p2pDumbbelHelper.GetRightIpv4Address(i), sinkPort);
    anyAddress = InetSocketAddress(Ipv4Address::GetAny(), sinkPort);
    PacketSinkHelper packetSinkHelper("ns3::TcpSocketFactory",anyAddress);
    ApplicationContainer sinkApps = packetSinkHelper.Install(p2pDumbbelHelper.GetRight(i));
    sinkApps.Start(Seconds(0.));
    sinkApps.Stop(Seconds(20.));
  }

  Ptr<Socket> clientTcpSocket = Socket::CreateSocket(p2pDumbbelHelper.GetLeft(2), TcpSocketFactory::GetTypeId());
  Ptr<Socket> serverTcpSocket = Socket::CreateSocket(p2pDumbbelHelper.GetRight(1), TcpSocketFactory::GetTypeId());

  Ptr<TerminalApplication> p2pDumbbelClientApp = CreateObject<TerminalApplication>();
  // app->Setup(ns3TcpSocket, sinkAddress, 1040, 1000, DataRate("1Mbps"));
  sinkAddress = InetSocketAddress(p2pDumbbelHelper.GetRightIpv4Address(1), sinkPort);
  // sinkAddress = serverInterfaces.GetAddress(1);
  p2pDumbbelClientApp->Setup(clientTcpSocket, sinkAddress, 1040, appPackets, DataRate(appDataRateStr));
  p2pDumbbelHelper.GetRight(2)->AddApplication(p2pDumbbelClientApp);
  p2pDumbbelClientApp->SetStartTime(Seconds(1.));
  p2pDumbbelClientApp->SetStopTime(Seconds(20.));


  Ipv4GlobalRoutingHelper::PopulateRoutingTables ();

  // // Flow monitor
  Ptr<FlowMonitor> flowMonitor;
  FlowMonitorHelper flowHelper;
  flowMonitor = flowHelper.InstallAll();


  
  


  cout << "\n"<< clientTcpSocket->GetNode()->GetId() << "\n";
  cout << "\n"<< serverTcpSocket->GetNode()->GetId() << "\n";
  cout << sinkAddress << "\n";
 
  AsciiTraceHelper asciiTraceHelper;
  
  Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream("QTCP.cwnd");
  clientTcpSocket->TraceConnectWithoutContext("CongestionWindow", MakeBoundCallback(&CwndChange, stream));


  stream = asciiTraceHelper.CreateFileStream("QTCP.ack");
  clientTcpSocket->TraceConnectWithoutContext("HighestRxAck", MakeBoundCallback(&AckReceive, stream));

  stream = asciiTraceHelper.CreateFileStream("QTCP.send_packet");
  clientTcpSocket->TraceConnectWithoutContext("Tx", MakeBoundCallback(&SendPacketCallBack, stream));

  stream = asciiTraceHelper.CreateFileStream("QTCP.receive_packet");
  serverTcpSocket->TraceConnectWithoutContext("Rx", MakeBoundCallback(&ReceivePacketCallBack, stream));

  stream = asciiTraceHelper.CreateFileStream("QTCP.rtt");
  clientTcpSocket->TraceConnectWithoutContext("RTT", MakeBoundCallback(&RttChange, stream));

  stream = asciiTraceHelper.CreateFileStream("QTCP.qtcp_state");
  clientTcpSocket->TraceConnectWithoutContext("State", MakeBoundCallback(&TcpStateChange, stream));

  // PcapHelper pcapHelper;
  // Ptr<PcapFileWrapper> file; 
  // file = pcapHelper.CreateFile("QTCP_drop.pcap", std::ios::out, PcapHelper::DLT_PPP);
  // p2pDevices.Get(1)->TraceConnectWithoutContext("PhyRxDrop", MakeBoundCallback(&RxDrop, file));

  // file = pcapHelper.CreateFile("QTCP_rx_p2p_1.pcap", std::ios::out, PcapHelper::DLT_PPP);
  // p2pDevices.Get(1)->TraceConnectWithoutContext("MacRx", MakeBoundCallback(&RxDrop, file));

  // file = pcapHelper.CreateFile("QTCP_rx_server_0.pcap", std::ios::out, PcapHelper::DLT_PPP);
  // serverDevice.Get(0)->TraceConnectWithoutContext("MacRx", MakeBoundCallback(&RxDrop, file));

  // file = pcapHelper.CreateFile("QTCP_rx_server_1.pcap", std::ios::out, PcapHelper::DLT_PPP);
  // serverDevice.Get(1)->TraceConnectWithoutContext("MacRx", MakeBoundCallback(&RxDrop, file));

  // file = pcapHelper.CreateFile("QTCP_rx_server_3.pcap", std::ios::out, PcapHelper::DLT_PPP);
  // serverDevice.Get(3)->TraceConnectWithoutContext("MacRx", MakeBoundCallback(&RxDrop, file));

  Simulator::Stop(Seconds(20));
  
  Simulator::Run();
  Simulator::Destroy();


  flowMonitor->CheckForLostPackets ();
  Ptr<Ipv4FlowClassifier> classifier = DynamicCast<Ipv4FlowClassifier> (flowHelper.GetClassifier ());
  std::map<FlowId, FlowMonitor::FlowStats> stats = flowMonitor->GetFlowStats ();

  for (std::map<FlowId, FlowMonitor::FlowStats>::const_iterator iter = stats.begin (); iter != stats.end (); ++iter)
    {

      // std::cout<<"flowid:"<<iter->first<<"\n";
      Ipv4FlowClassifier::FiveTuple t = classifier->FindFlow (iter->first);

      std::cout<<"sourceAddress:"<<t.sourceAddress<<"\tdestinationAddress"<<t.destinationAddress<<"\n";
      // std::cout<<"Throughput: " << iter->second.rxBytes * 8.0 / (iter->second.timeLastRxPacket.GetSeconds()-iter->second.timeFirstTxPacket.GetSeconds()) / 1024 /1024  << " Mbps\n";

      if ((t.sourceAddress == Ipv4Address("10.1.4.9") && t.destinationAddress == Ipv4Address("10.1.5.5")))
        // || (t.sourceAddress == Ipv4Address("10.1.1.3") && t.destinationAddress == Ipv4Address("10.1.1.2")))
        {
          // std::cout<<"Flow ID: " << iter->first << " Src Addr " << t.sourceAddress << " Dst Addr " << t.destinationAddress<<"\n";
          // std::cout<<"Tx Packets = " << iter->second.txPackets<<"\n";
          // std::cout<<"Rx Packets = " << iter->second.rxPackets<<"\n";
          std::cout<<"Throughput: " << iter->second.rxBytes * 8.0 / (iter->second.timeLastRxPacket.GetSeconds()-iter->second.timeFirstTxPacket.GetSeconds()) / 1024 /1024  << " Mbps\n";

        }
    }


  return 0;
}
// namespace qtcp
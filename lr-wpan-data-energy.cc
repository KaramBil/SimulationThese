/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 The Boeing Company
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author:  Tom Henderson <thomas.r.henderson@boeing.com>
 */

/*
 * Try to send data end-to-end through a LrWpanMac <-> LrWpanPhy <->
 * SpectrumChannel <-> LrWpanPhy <-> LrWpanMac chain
 *
 * Trace Phy state changes, and Mac DataIndication and DataConfirm events
 * to stdout
 */
#include <ns3/log.h>
#include <ns3/core-module.h>
#include <ns3/lr-wpan-module.h>
#include <ns3/propagation-loss-model.h>
#include <ns3/propagation-delay-model.h>
#include <ns3/simulator.h>
#include <ns3/single-model-spectrum-channel.h>
#include <ns3/constant-position-mobility-model.h>
#include <ns3/packet.h>
#include "ns3/netanim-module.h"
#include <ns3/gnuplot.h>
#include <ns3/lr-wpan-spectrum-value-helper.h>


#include <ns3/single-model-spectrum-channel.h>
#include <ns3/multi-model-spectrum-channel.h>

#include <iostream>

using namespace ns3;

static uint32_t g_received = 0;

static void DataIndication (McpsDataIndicationParams params, Ptr<Packet> p)
{
 // NS_LOG_UNCOND ("Received packet of size " << p->GetSize ());
  g_received++;
  
}

static void DataConfirm (McpsDataConfirmParams params)
{
 // NS_LOG_UNCOND ("LrWpanMcpsDataConfirmStatus = " << params.m_status);
}
/*
static void StateChangeNotification (std::string context, Time now, LrWpanPhyEnumeration oldState, LrWpanPhyEnumeration newState)
{
  NS_LOG_UNCOND (context << " state change at " << now.As (Time::S)
                         << " from " << LrWpanHelper::LrWpanPhyEnumerationPrinter (oldState)
                         << " to " << LrWpanHelper::LrWpanPhyEnumerationPrinter (newState));
}


static void
LrWpanErrorDistanceCallback (McpsDataIndicationParams params, Ptr<Packet> p)
{
  g_received++;
}
*/
  int nbrpacket = 100;
        double Eelec=50;
        double Eamp=0.1;
  static int recMSG[2];
  static int sentMSG[2];
    static int recBITS[5];
      static int sentBITS[5];
      
    static int RealrecBITS[2];
      static int RealsentBITS[2];
   double en0 =0.0;
      double en1 = 0.0;
      double en2 = 0.0;
      double en3 = 0.0;
            double en4 = 0.0;
                        double en5 = 0.0;
        int TTT = 0;
     
void incREC(int node,int bits, Ptr<Packet> p ){
recMSG[node] += 1;
recBITS[node]+=bits;  
RealrecBITS[node]+=p->GetSize ()*8; 
/*if (node==0){
 
   NS_LOG_UNCOND ("Bits received  " <<RealrecBITS[node]<< "/" << RealsentBITS[1] );

}
 if (node==1){
 
   NS_LOG_UNCOND ("Bits received  " <<RealrecBITS[node]<< "/" << RealsentBITS[0] );

 }*/
 }
void incSENT(int node,int bits, Ptr<Packet> p){
sentMSG[node] +=1;  
RealsentBITS[node]+= p->GetSize ()*8;
sentBITS[node]+= bits;
 /*if (node==0){
   NS_LOG_UNCOND ("Bits sent  " << recBITS[1]<< "/" << RealsentBITS[node] );
 }
 if (node==1){
    NS_LOG_UNCOND ("Bits sent  " << recBITS[0]<< "/" << RealsentBITS[node] );
 }
*/
}

 static void restore(){
        recMSG[0]=nbrpacket;         sentMSG[0]=nbrpacket;
        recMSG[1]=2*nbrpacket;         sentMSG[1]=nbrpacket;
        recBITS[0]=0;        sentBITS[0]=0;
        recBITS[1]=0;        sentBITS[1]=0;
        recBITS[2]=896*nbrpacket;        sentBITS[2]=1024*nbrpacket;
              recBITS[3]=1440*nbrpacket;        sentBITS[3]=1280*nbrpacket;
                            recBITS[4]=1024*nbrpacket;        sentBITS[4]=1504*nbrpacket;
                            recBITS[5]=1500*nbrpacket;        sentBITS[5]=1624*nbrpacket;
        RealrecBITS[0]=0;    RealsentBITS[0]=0;
        RealrecBITS[1]=0;    RealsentBITS[1]=0;

 }
 
 static  void EnergyConsumed( int node ,int distance ) {
 double Etr=0.0; double Erc=0.0;  
 double Etr2=0.0; double Erc2=0.0;
 double Etr3=0.0; double Erc3=0.0;
 double Etr4=0.0; double Erc4=0.0;
 double Etr5=0.0; double Erc5=0.0;
 Etr=(sentBITS[node]*Eelec)+(sentBITS[node]*Eamp*distance*distance);
 Erc=sentBITS[node]*Eelec;
 Etr2=(sentBITS[2]*Eelec)+(sentBITS[2]*Eamp*distance*distance);
 Erc2=sentBITS[2]*Eelec;
 Etr3=(sentBITS[3]*Eelec)+(sentBITS[3]*Eamp*distance*distance);
 Erc3=sentBITS[3]*Eelec;
 Etr4=(sentBITS[4]*Eelec)+(sentBITS[4]*Eamp*distance*distance);
 Erc4=sentBITS[4]*Eelec;
 Etr5=(sentBITS[5]*Eelec)+(sentBITS[5]*Eamp*distance*distance);
 Erc5=sentBITS[5]*Eelec;
 if (node==0){
 en0=(Etr+Erc)/1000;
 en0=en0/nbrpacket;
 
 }
 if (node==1){
 en1=(Etr+Erc)/1000;
 en1=en1/nbrpacket;
 
 en2=(Etr2+Erc2)/1000;
 en2=en2/nbrpacket;
 en3=(Etr3+Erc3)/1000;
 en3=en3/nbrpacket;
 en4=(Etr4+Erc4)/1000;
 en4=en4/nbrpacket;
 en5=(Etr5+Erc5)/1000;
 en5=en5/nbrpacket;
 }
  
 }
 
int main (int argc, char *argv[])
{
  std::ostringstream os;
  std::ofstream berfile ("ART-success-distance.plt");
std::ofstream berfile2 ("ART-Energy-distance.plt");
std::ofstream berfile3 ("ART-Delay-distance.plt");

  bool verbose = false;
  bool extended = false;

 restore();
        
  CommandLine cmd (__FILE__);

  cmd.AddValue ("verbose", "turn on all log components", verbose);
  cmd.AddValue ("extended", "use extended addressing", extended);

  cmd.Parse (argc, argv);

  Gnuplot psrplot = Gnuplot ("SuccessRatioDistance.png");
  Gnuplot2dDataset psrdataset ("SUCCESSPACKETS");
  
  
  Gnuplot energyplot = Gnuplot ("EnergyDistance.png");
  Gnuplot2dDataset EnergyDataBS ("[8]");
    Gnuplot2dDataset EnergyData3 ("[15]");
        Gnuplot2dDataset EnergyData4 ("[17]");
        
        Gnuplot2dDataset EnergyData5 ("[24]");
  Gnuplot2dDataset EnergyData ("Proposed Protocol");
  
  
  Gnuplot delayplot = Gnuplot ("DelayDistance.png");
  Gnuplot2dDataset Delay ("DELAY");

  LrWpanHelper lrWpanHelper;
  if (verbose)
    {
      lrWpanHelper.EnableLogComponents ();
    }

  // Enable calculation of FCS in the trailers. Only necessary when interacting with real devices or wireshark.
  // GlobalValue::Bind ("ChecksumEnabled", BooleanValue (true));

  // Create 2 nodes, and a NetDevice for each one
  Ptr<Node> n0 = CreateObject <Node> ();
  Ptr<Node> n1 = CreateObject <Node> ();

  Ptr<LrWpanNetDevice> dev0 = CreateObject<LrWpanNetDevice> ();
  Ptr<LrWpanNetDevice> dev1 = CreateObject<LrWpanNetDevice> ();

  if (!extended)
    {
      dev0->SetAddress (Mac16Address ("00:01"));
      dev1->SetAddress (Mac16Address ("00:02"));
    }
  else
    {
      Ptr<LrWpanMac> mac0 = dev0->GetMac ();
      Ptr<LrWpanMac> mac1 = dev1->GetMac ();
      mac0->SetExtendedAddress (Mac64Address ("00:00:00:00:00:00:00:01"));
      mac1->SetExtendedAddress (Mac64Address ("00:00:00:00:00:00:00:02"));
    }

  // Each device must be attached to the same channel
  Ptr<SingleModelSpectrumChannel> channel = CreateObject<SingleModelSpectrumChannel> ();
  Ptr<LogDistancePropagationLossModel> propModel = CreateObject<LogDistancePropagationLossModel> ();
  Ptr<ConstantSpeedPropagationDelayModel> delayModel = CreateObject<ConstantSpeedPropagationDelayModel> ();
  channel->AddPropagationLossModel (propModel);
  channel->SetPropagationDelayModel (delayModel);

  dev0->SetChannel (channel);
  dev1->SetChannel (channel);

  // To complete configuration, a LrWpanNetDevice must be added to a node
  n0->AddDevice (dev0);
  n1->AddDevice (dev1);

  // Trace state changes in the phy
 /* dev0->GetPhy ()->TraceConnect ("TrxState", std::string ("phy0"), MakeCallback (&StateChangeNotification));
  dev1->GetPhy ()->TraceConnect ("TrxState", std::string ("phy1"), MakeCallback (&StateChangeNotification));
*/
  Ptr<ConstantPositionMobilityModel> sender0Mobility = CreateObject<ConstantPositionMobilityModel> ();
  sender0Mobility->SetPosition (Vector (0,0,0));
  dev0->GetPhy ()->SetMobility (sender0Mobility);
  Ptr<ConstantPositionMobilityModel> sender1Mobility = CreateObject<ConstantPositionMobilityModel> ();
  // Configure position 10 m distance
  sender1Mobility->SetPosition (Vector (0,10,0));
  dev1->GetPhy ()->SetMobility (sender1Mobility);

  McpsDataConfirmCallback cb0;
  cb0 = MakeCallback (&DataConfirm);
  dev0->GetMac ()->SetMcpsDataConfirmCallback (cb0);

  McpsDataIndicationCallback cb1;
  cb1 = MakeCallback (&DataIndication);
  //  cb1 = MakeCallback (&LrWpanErrorDistanceCallback);
  dev0->GetMac ()->SetMcpsDataIndicationCallback (cb1);

  McpsDataConfirmCallback cb2;
  cb2 = MakeCallback (&DataConfirm);
  dev1->GetMac ()->SetMcpsDataConfirmCallback (cb2);

  McpsDataIndicationCallback cb3;
  cb3 = MakeCallback (&DataIndication);
  dev1->GetMac ()->SetMcpsDataIndicationCallback (cb3);

  // Tracing
  lrWpanHelper.EnablePcapAll (std::string ("lr-wpan-data"), true);
  AsciiTraceHelper ascii;
  Ptr<OutputStreamWrapper> stream = ascii.CreateFileStream ("lr-wpan-data.tr");
  lrWpanHelper.EnableAsciiAll (stream);
 // AnimationInterface anim ("4Msg.xml"); // Mandatory
  double delay ;
  double lastentry=0.0 ;


  for (int j = 0; j < 105;  ) {
      delay = Simulator::Now ().GetSeconds ()*1000-lastentry;
      delay = delay / nbrpacket;
    lastentry=Simulator::Now ().GetSeconds ()*1000;
 NS_LOG_UNCOND ("Distance entre les noeuds :" << j <<" -----------------------------------" );
  // NS_LOG_UNCOND ("entre time in S :" <<lastentry/1000 );
   
    for (int msg = 0; msg < nbrpacket; msg++ ) {
   
  Ptr<Packet> p0 = Create<Packet> (48);  // 50 bytes of dummy data
  McpsDataRequestParams params;
  params.m_dstPanId = 0;
  if (!extended)
    {
      params.m_srcAddrMode = SHORT_ADDR;
      params.m_dstAddrMode = SHORT_ADDR;
      params.m_dstAddr = Mac16Address ("00:02");
    }
  else
    {
      params.m_srcAddrMode = EXT_ADDR;
      params.m_dstAddrMode = EXT_ADDR;
      params.m_dstExtAddr = Mac64Address ("00:00:00:00:00:00:00:02");
    }
  params.m_msduHandle = 0;
  params.m_txOptions = TX_OPTION_ACK;
//  dev0->GetMac ()->McpsDataRequest (params, p0);
  Simulator::ScheduleWithContext (j, Seconds (TTT),
                                  &LrWpanMac::McpsDataRequest,
                                  dev0->GetMac (), params, p0);
                                  incSENT(1,384,p0);
                                  incREC(0,384,p0);

  
  // Send a packet back at time 2 seconds
  Ptr<Packet> p2 = Create<Packet> (48);  // 60 bytes of dummy data

  if (!extended)
    {
      params.m_dstAddr = Mac16Address ("00:01");
    }
  else
    {
      params.m_dstExtAddr = Mac64Address ("00:00:00:00:00:00:00:01");
    }
  Simulator::ScheduleWithContext (j, Seconds (TTT),
                                  &LrWpanMac::McpsDataRequest,
                                  dev1->GetMac (), params, p2);
                                  incSENT(0,384,p2);
                                  incREC(1,384,p2);


Ptr<Packet> p3 = Create<Packet> (68);  // 50 bytes of dummy data  


McpsDataRequestParams params3;
  params3.m_dstPanId = 0;
  if (!extended)
    {
      params3.m_srcAddrMode = SHORT_ADDR;
      params3.m_dstAddrMode = SHORT_ADDR;
      params3.m_dstAddr = Mac16Address ("00:02");
    }
  else
    {
      params3.m_srcAddrMode = EXT_ADDR;
      params3.m_dstAddrMode = EXT_ADDR;
      params3.m_dstExtAddr = Mac64Address ("00:00:00:00:00:00:00:02");
    }
  params3.m_msduHandle = 0;
  params3.m_txOptions = TX_OPTION_ACK;
  //  dev0->GetMac ()->McpsDataRequest (params, p0);
 Simulator::ScheduleWithContext (j, Seconds (TTT),
                                  &LrWpanMac::McpsDataRequest,
                                  dev0->GetMac (), params3, p3);
                                  incSENT(1,544,p3);
                                  incREC(0,544,p3);

  // Send a packet back at time 2 seconds

  Ptr<Packet> p4 = Create<Packet> (30);  // 60 bytes of dummy data
  if (!extended)
    {
      params.m_dstAddr = Mac16Address ("00:01");
    }
  else
    {
      params.m_dstExtAddr = Mac64Address ("00:00:00:00:00:00:00:01");
    }


  Simulator::ScheduleWithContext (j, Seconds (TTT),
                                  &LrWpanMac::McpsDataRequest,
                                  dev1->GetMac (), params, p4);
                                  incSENT(0,240,p4);
                                  incREC(1,240,p4);




  sender1Mobility->SetPosition (Vector (j,j,0));


  
  Simulator::Run ();



}     

      //NS_LOG_UNCOND ("Received " << recMSG[0] << " packets");
      //NS_LOG_UNCOND ("Sent " << sentMSG[0] << " packets");
      
      //NS_LOG_UNCOND ("Received " << recBITS[0] << " bits");
     // NS_LOG_UNCOND ("Sent " << sentBITS[0] << " bits");
      
      EnergyConsumed(0,j);      
      EnergyConsumed(1,j);
      // NS_LOG_UNCOND ("Energy consumed by node 0 " << en0 << " nanoJ");
     // NS_LOG_UNCOND ("Energy consumed by node 1 " << en1 << " nanoJ");
      float success = (g_received/400.0);
            //  NS_LOG_UNCOND ("succes " << success );
      psrdataset.Add (j,success );
      if(   0 < g_received) {
      EnergyData.Add(j,en1); 

      EnergyDataBS.Add(j,en2);

        EnergyData3.Add(j,en3);
        EnergyData4.Add(j,en4);
        
        EnergyData5.Add(j,en5);
                      NS_LOG_UNCOND ("Our energy" << en1 <<" received "  << recBITS[1]  ); 
                NS_LOG_UNCOND ("[22] energy " << en3 <<" received "  << recBITS[4]  ); 
                        NS_LOG_UNCOND ("[23]  energy " << en4 <<" received "  << recBITS[5]  ); 
      Delay.Add(j,delay);
      restore();
      }
     
      else {
      j=120;
      Simulator::Destroy ();
    }
    /*    recMSG[0]=0;
        sentMSG[0]=0;
        recMSG[1]=0;
        sentMSG[1]=0;
 */
 
       // NS_LOG_UNCOND ("Received " << g_received << " / "<< nbrpacket*4<< " packets for distance " << j);
        g_received = 0;
    NS_LOG_UNCOND ("Delay = :" << delay<<"mS -----------------------------------" );
    j =j+2;
    
    
     

}
   
   
    psrplot.AddDataset (psrdataset);

  psrplot.SetTitle (os.str ());
  psrplot.SetTerminal ("png size 500,400 enhanced font  \"Times-BoldItalic\"");
  psrplot.SetLegend ("distance (m)", "Packet Success Rate (PSR)");
  psrplot.SetExtra  ("set xrange [0:100]\n\
set yrange [0:1.5]\n\
set grid\n\
set style line 1 linewidth 2\n\
set style increment user");
  psrplot.GenerateOutput (berfile);
  berfile.close ();



    energyplot.AddDataset (EnergyData);
    //energyplot.AddDataset (EnergyDataBS);
   // energyplot.AddDataset (EnergyData3);
    //energyplot.AddDataset (EnergyData4);
    energyplot.AddDataset (EnergyData5);
  energyplot.SetTitle (os.str ());
  energyplot.SetTerminal ("png size 500,400 enhanced font  \"Times-BoldItalic\"");
  energyplot.SetLegend ("Distance (m)", "Energy (nJ)");
  energyplot.SetExtra  ("set xrange [0:100]\n\
set yrange [0:2000]\n\
set grid\n\
set style line 1 linewidth 2\n\
set style line 2 linewidth 2\n\
set style line 3 linewidth 2\n\
set style line 4 linewidth 2\n\
set style line 5 linewidth 2\n\
set style increment user");
  energyplot.GenerateOutput (berfile2);
  berfile2.close ();

delayplot.AddDataset (Delay);
delayplot.AddDataset (psrdataset);

  delayplot.SetTitle (os.str ());
  delayplot.SetTerminal ("png size 500,400 enhanced font  \"Times-BoldItalic\"");
  delayplot.SetLegend ("Distance (m)", "Delay (mS)");
  delayplot.SetExtra  ("set xrange [0:100]\n\
set yrange [0:70]\n\
set y2tics 0,0.1\n\
set ytics nomirror\n\
set y2range [0:1.2]\n\
set grid\n\
set style line 1 linewidth 2\n\
set style line 2 linewidth 2\n\
set style increment user");
  delayplot.GenerateOutput (berfile3);
  berfile3.close ();



  Simulator::Destroy ();
  return 0;
}

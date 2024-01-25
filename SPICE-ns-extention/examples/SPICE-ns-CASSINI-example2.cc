/////////////////////////////////////////////////////////////////////////////////////////////
// This Simulation is Prepared for WNS3-2024 Conference Paper
// "A Novel, Realistic Mobility Model for Deep Space Network Simulations Under ns-3"
//
//
//     Design and Implementation of Novel Protocols for Deep Space Network 
//            Using SPICE Toolkit and Kernels Under ns-3
// 
// Developed by :           Jason Pandian,(pandiajason@gmail.com)
//                          Assistant Professor, Department of Computer Science and Engineering,
//                          Tamilnadu College of Engineering, Coimbatore.
//                          Affiliated to Anna University, Chennai,
//                          India.
// 
// 
// Declaration"
// This project uses binary version of NASA/NAIF's SPICE tool kit and
// Some of the Text and Binary version of SPICE Kernels/Data
/////////////////////////////////////////////////////////////////////////////////////////////
#include "ns3/core-module.h"
#include "ns3/SPICE-ns-helper.h"
#include "ns3/applications-module.h"
#include "ns3/internet-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/log.h"
#include "ns3/callback.h"
#include "ns3/mobility-module.h"
#include "ns3/netanim-module.h" 
#include "ns3/spice-mobility-model.h"



#include <fstream>
#include <iostream>



// Include the header files that is needed for CSPICE
#include <stdio.h>
#include "ns3/SPICE-ns.h"

using namespace ns3;
using namespace NASA_SPICE;

NS_LOG_COMPONENT_DEFINE("SPICE-ns-CASSINI-example2");

// We may Call functions from the NASA_SPICE namespace
SPICE_NS spice;

int
main(int argc, char* argv[])
{
    CommandLine cmd(__FILE__);
    cmd.Parse(argc, argv);
	
    //Create only one node to represent CASSINI Spacecraft
    NodeContainer SpiceObjects;
    SpiceObjects.Create (5);
	
    //spice.test();

    const char* homeFolder = std::getenv("HOME");
    std::string filePath = std::string(homeFolder) + "/ns-3.40/data/CASSINI/CASSINI_Meta_Kernel.txt";


	// Specify the path to the CSPICE meta-kernel
    const char* metaKernelPath = filePath.c_str();

    // Specify the time interval
    const char* UTCstart = "Jun 20, 2004";
    const char* UTCend = "Dec 1, 2005";

 
    //spice.furnsh("./CASSINI_Meta_Kernel.txt")
    spice.loadSPICEMetaKernel(metaKernelPath,UTCstart,UTCend);

  
     // Convert UTC times to ephemeris time (ET)
    SpiceDouble etStart, etEnd, StepSize, TimeDuration;
    
    //StepSize=1;

    str2et_c(UTCstart, &etStart);
    str2et_c(UTCend, &etEnd);


    TimeDuration= etEnd -  etStart;

    
    StepSize=TimeDuration/4000;


    std::cout<<etStart<<"  "<< etStart<< "  "<< TimeDuration << " (" << Seconds(TimeDuration) << ") " << StepSize <<"************\n";

    //str2et_c(j2000StartTime, &etStart);

	//Testing :  getting possition, velosity and light time distance at different time
    const char* Observer = "SATURN BARYCENTER";
    const char* Target1 = "Cassini";
    const char* Target2 = "Titan";
    const char* Target3 = "Rhea";
    const char* Target4 = "Iapetus";
    const char* Target5 = "Dione";
    
    const char* ReferenceFrame="J2000";


    //spice.PrintPositionAndVelocity("SATURN", "Cassini", "J2000",0);
    //Vector pos = spice.GetPosition("SATURN", "Cassini", "J2000",etStart+0);
    //std::cout<<pos<<"\n";

    MobilityHelper SpiceMobility;
    SpiceMobility.SetMobilityModel ("ns3::SpiceMobilityModel");
    
    SpiceMobility.Install (SpiceObjects);
    //SpiceObjects.Get (0)->GetObject<SpiceMobilityModel>() ->TestGetPosition(Observer, Target1, ReferenceFrame,etStart);
    SpiceObjects.Get (0)->GetObject<SpiceMobilityModel>() ->SetParameters(Observer, Target1, ReferenceFrame,etStart,StepSize);
    SpiceObjects.Get (1)->GetObject<SpiceMobilityModel>() ->SetParameters(Observer, Target2, ReferenceFrame,etStart,StepSize);
    SpiceObjects.Get (2)->GetObject<SpiceMobilityModel>() ->SetParameters(Observer, Target3, ReferenceFrame,etStart,StepSize);
    SpiceObjects.Get (3)->GetObject<SpiceMobilityModel>() ->SetParameters(Observer, Target4, ReferenceFrame,etStart,StepSize);
    SpiceObjects.Get (4)->GetObject<SpiceMobilityModel>() ->SetParameters(Observer, Target5, ReferenceFrame,etStart,StepSize);



    // Additional functionality from the NASA_SPICE namespace
    // ...
  AnimationInterface anim ("CASSINI-And-Moons-NetAnim-Trace.xml"); 

  
  AsciiTraceHelper ascii;
  MobilityHelper::EnableAsciiAll (ascii.CreateFileStream ("CASSINI-And-Moons-ns-3-Mobility-Trace.mob"));

  Simulator::Stop (Seconds(TimeDuration));
  Simulator::Run ();
  Simulator::Destroy ();
  //system("python CASSINI-And-Moons-ns-3-Mobility-Trace.py CASSINI-And-Moons-ns-3-Mobility-Trace.mob");
  return 0;
}

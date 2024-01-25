/////////////////////////////////////////////////////////////////////////////////////////////
// This Simulation is Prepared for WNS3-2024 Conference Paper
// "A Novel, Realistic Mobility Model for Deep Space Network Simulations Under ns-3"
//
// A ns-3 Simulation Script developed for the Research work on
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

// ns-3 related header files
#include "ns3/core-module.h"
#include "ns3/applications-module.h"
#include "ns3/internet-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/log.h"
#include "ns3/callback.h"
#include "ns3/mobility-module.h"
#include "ns3/netanim-module.h" 

// spice mobility model related header files
#include "ns3/SPICE-ns-helper.h" // not yet implemented any helpers
#include "ns3/spice-mobility-model.h" // contains spice mobility model implementation
#include "ns3/SPICE-ns.h"       // contains the class definitions of SPICE_NS and SPICE api interface

// other header files
#include <fstream>
#include <iostream>
#include <stdio.h>


using namespace ns3;

//SPICE API functions kernel pools are kept under separate namespace
using namespace NASA_SPICE;

NS_LOG_COMPONENT_DEFINE("EvaluationOfSPICE-ns-MobilityModel");

// The class used to Call functions from the NASA_SPICE namespace
SPICE_NS spice;

int
main(int argc, char* argv[])
{
    // etTimeStep in seconds; 
    // The default is set as 11426.4 to compare the CASSINI trajectory output 
    // of previous python example of SpiceyPy

    SpiceDouble etTimeStep=11426.4;
    CommandLine cmd(__FILE__);
    cmd.AddValue("etTimeStep", "The Ephemeris step time in seconds", etTimeStep);

    cmd.Parse(argc, argv);
	
    // Create only one node to represent CASSINI Spacecraft
    NodeContainer SpiceObjects;
    SpiceObjects.Create (5);
	
    // Uncomment this 'test' for testing the functioning of spice api 
    // (path should be correctly given at test function of SPICE-ns.cc)

    //spice.test();


    // Set the path according to the installation of Kernels and CSPICE meta-kernel
    // CASSINI_Meta_Kernel.txt may be needed to edit according to the kernel path

    const char* homeFolder = std::getenv("HOME");
    std::string filePath = std::string(homeFolder) + "/ns-3.40/data/CASSINI/CASSINI_Meta_Kernel.txt";

    const char* metaKernelPath = filePath.c_str();

    // Specify the time interval 
    // It is the whole duration within that we are going to step in to (etTimeStep)

    const char* UTCstart = "Jun 20, 2004";
    const char* UTCend = "Dec 1, 2005";


    // This function will use ' furnsh_c ' api call.
    // The furnsh_c function is part of the SPICE Toolkit API 
    // (Navigation and Ancillary Information Facility for Spacecraft) 
    // provided by NASA's Jet Propulsion Laboratory. 
    // This function is used to load SPICE kernels into the SPICE system
    // spice.loadSPICEMetaKernel(metaKernelPath,UTCstart,UTCend);

    spice.loadSPICEMetaKernel(metaKernelPath,UTCstart,UTCend);

 
    // str2et_c Convert a string representing an epoch time 
    // to ephemeris seconds past the J2000 epoch.
    // Here, we convert UTC times to ephemeris time (ET)

    SpiceDouble etStart, etEnd, TimeDuration;
    str2et_c(UTCstart, &etStart);
    str2et_c(UTCend, &etEnd);


    //Calculate the time duration of the simulation in ephemeris time

    TimeDuration= etEnd -  etStart;

    //just for testing...
    std::cout<<etStart<<"  "<< etStart<< "  "<< TimeDuration << " (" << Seconds(TimeDuration) << ") " << etTimeStep <<"************\n";



	//Testing :  getting position, velocity and light time distance at different time
    //spice.PrintPositionAndVelocity("SATURN", "Cassini", "J2000",0);
    //Vector pos = spice.GetPosition("SATURN", "Cassini", "J2000",etStart+0);
    //std::cout<<pos<<"\n";


    // setting Observer and Targets

    const char* Observer = "SATURN BARYCENTER";
    const char* Target1 = "Cassini";
    const char* Target2 = "Titan";
    const char* Target3 = "Rhea";
    const char* Target4 = "Iapetus";
    const char* Target5 = "Dione";




    const char* ReferenceFrame="J2000";

    //Initialize spice mobility model in nodes

    MobilityHelper SpiceMobility;
    SpiceMobility.SetMobilityModel ("ns3::SpiceMobilityModel");
    SpiceMobility.Install (SpiceObjects);

    //The following line is for testing the working of a Spice API call from with in our mobility model
    
    //SpiceObjects.Get (0)->GetObject<SpiceMobilityModel>() ->TestGetPosition(Observer, Target1, ReferenceFrame,etStart);


    // Configure Observer, target Reference frame, et start time, et step time in the mobility model of the nodes.

    SpiceObjects.Get (0)->GetObject<SpiceMobilityModel>() ->SetParameters(Observer, Target1, ReferenceFrame,etStart,etTimeStep);
    SpiceObjects.Get (1)->GetObject<SpiceMobilityModel>() ->SetParameters(Observer, Target2, ReferenceFrame,etStart,etTimeStep);
    SpiceObjects.Get (2)->GetObject<SpiceMobilityModel>() ->SetParameters(Observer, Target3, ReferenceFrame,etStart,etTimeStep);
    SpiceObjects.Get (3)->GetObject<SpiceMobilityModel>() ->SetParameters(Observer, Target4, ReferenceFrame,etStart,etTimeStep);
    SpiceObjects.Get (4)->GetObject<SpiceMobilityModel>() ->SetParameters(Observer, Target5, ReferenceFrame,etStart,etTimeStep);



    // Even though the traces are logged correctly in the xml file,
    // the Network Animator was unable to animate those events correctly
    // So, commenting the unnecessary creation of that xml trace
    
    //AnimationInterface anim ("CASSINI-And-Moons-NetAnim-Trace.xml"); 

    // Setting up a mobility trace output file to log the locations and velocities during the simulation
    // Mobility model will automatically log those values in this file on every CourseChange event.
    
    AsciiTraceHelper ascii;
    MobilityHelper::EnableAsciiAll (ascii.CreateFileStream ("CASSINI-And-Moons-ns-3-Mobility-Trace.mob"));
    
    // Stop the Stimulation at the end of ephemeris time (here mentioned in ns-3 time format)
    Simulator::Stop (Seconds(TimeDuration));

    // Run the simulation
    
    Simulator::Run ();
    
    // Destroy the simulator instance (will clear all the memory)
    Simulator::Destroy ();


    // Un comment the following line to visualize the mobility traces 
    //system("python CASSINI-And-Moons-ns-3-Mobility-Trace.py CASSINI-And-Moons-ns-3-Mobility-Trace.mob");

    // Return 0 to the shell (no error)
    return 0;
}

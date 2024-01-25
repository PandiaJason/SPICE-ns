/////////////////////////////////////////////////////////////////////////////////////////////
// The SPICE-ns DSN Network Simulation Extention developed for the research work on
//
//     Design and Implementation of Novel Protocols for Deep Space Network 
//            Using SPICE Toolkit and Kernels Under ns-3
// 
// Developed by :           Jason Pandian,(pandiajason@gmail.com)
//                          Department of Computer Science and Engineering,
//                          Anna University, Chennai,
//                          India.
// 
// Under the Supervision of: 
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

// Include the header files that is needed for CSPICE
#include <stdio.h>
#include "ns3/spice_namespace.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("FirstScriptExample");

int
main(int argc, char* argv[])
{
    CommandLine cmd(__FILE__);
    cmd.Parse(argc, argv);
	
    // Call functions from the NASA_SPICE namespace
    NASA_SPICE::initializeSPICE();

    // Specify the paths to SPICE kernels
    //std::vector<std::string> kernelPaths = {"path/to/kernel1.bsp", "path/to/kernel2.tls"};

    // Load SPICE kernels
    //NASA_SPICE::loadSPICEKernels(kernelPaths);

    // Additional functionality from the NASA_SPICE namespace
    // ...

    Simulator::Run();
    Simulator::Destroy();
    return 0;
}

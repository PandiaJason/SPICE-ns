/////////////////////////////////////////////////////////////////////////////////////////////
// The SPICE-ns MobilityModel developed for the research work on
//
//     Design and Implementation of Novel Protocols for Deep Space Network 
//            Using SPICE Toolkit and Kernels Under ns-3
// 
// Developed by :           Jason Pandian,(pandiajason@gmail.com)
//                          Department of Computer Science and Engineering,
//                          Tamilnadu College of Engineering, Coimbatore,
//                          Anna University, Chennai,
//                          India.
// 
// Under the Supervision of: 
// 
// Declaration"
// This project uses binary version of NASA/NAIF's SPICE tool kit and
// Some of the Text and Binary version of SPICE Kernels/Data
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef SPICE_MOBILITY_MODEL_H
#define SPICE_MOBILITY_MODEL_H

#include "ns3/simulator.h"
#include "ns3/log.h"
#include "ns3/nstime.h"

#include "ns3/mobility-model.h"
#include "ns3/constant-velocity-helper.h"
#include "cspice/SpiceUsr.h"  // Include SPICE toolkit header - should be kept under any directory which is in include path

#include "ns3/event-id.h"
#include "ns3/object.h"



// Sorry

// This part of the code will be published after getting approval from the Grantor
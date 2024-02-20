# 📡 SPICE-ns - An Extension for ns-3 to Simulate DSN and DTN

- 🌐 Idealized the Proof of Concept for integrating CSPICE with ns3.
- 🚧 SPICE-ns is under development, an extension for ns3 that supports various aspects of deep space network simulations.
- ✅ Successfully Integrated CSPICE under ns3.
- ✅ Developed an Accurate Deep Space Mobility Model under ns3 with SPICE-ns.
- 🚀 As a first step, we have successfully implemented a mobility model for SPICE-ns and a paper is proposed to be presented at WNS3, Spain 2024.

## 📡 About SPICE ns
SPICE ns is a modular extension for deep space networks simulation under Network Simulator 3 (ns3). It uses NAIF/NASA's space geometrical data modular toolkit Spacecraft, Planet, Instrument, C-matrix, Events (SPICE)  for modeling astrodynamics of natural and artifical satilites and spacecrafts. In general SPICE finds applications from mission concept development to post-mission data analysis in a realisitic simulated enviornment. With SPICE ns, it can perform various deep space networking tasks, deep space network scheduling, space packet loss tests, network path finding/planning, and network cost analysis through its simulations.


## 🔥 Motivation for SPICE ns Contribution

SPICE, developed by NAIF/NASA, is extensively utilized in various space organizations such as ISRO and ESA. It serves diverse purposes, including spacecraft and satellite mission planning, astrodynamics analysis, and deep space network studies. SPICE has played a pivotal role in SPICE enhanced Cosmosphia, widely adopted tool across the space organizations.

In terms of network aspects, these organizations rely on in-house software sollutions. Projects like DTNDevKit2.0's CORE provide network and visualization for deep space network simulations. The limitations in simulating natural astrodynamics, particualry(For Example: Not handling Mobility in natual way) within DTNDevKit2.0 CORE. And the closed nature of other existing deep space network simulation environments serve as motivation for us to contribute to SPICE ns under ns3. Our goal is to enhance deep space network stack and simulation aspects with the integration of SPICE, providing a more comprehensive solution.

![image](https://github.com/PandiaJason/SPICE-ns-Project/assets/100123063/ccc75658-b665-4c3f-a8fe-c60ff24cefd8)

### 🚧 Note 
The code and information presented in this document are currently under development and are not ready for public distribution. This is a work in progress, and certain features may not be fully implemented or tested. Any use or distribution of the code is discouraged until an official release is made.

📊 Meantime, one can check some of the preliminary results in "Outputs" Folder.

### 📜 Declaration
We are actively processing an application for getting grant to support the future development of SPICE-ns. Consequently, the source code for SPICE-ns, inclusive of the grantor's affiliation, will soon be made accessible on this page.

### 🎯 Long-term Goal

The long-term goal of this project is to develop a complete extension called 'SPICE-ns' for ns-3 to perform DSN/DTN simulations.

In the future, we plan to incrementally implement other aspects necessary to simulate a complete DSN/DTN.

## 🌐 SPICE-ns Modules 
 
- ⌛ SPICE-ns Application Models,
- ⌛ SPICE-ns DSN Data Traffic Generator,
- ⌛ SPICE-ns Network Layer Modelling
- ⌛ SPICE-ns Phy Model
- ⌛ SPICE-ns MAC Model
- ⌛ SPICE-ns Spectrum Model
- ⌛ SPICE-ns Antenna Model
- ⌛ SPICE-ns Propagation Model
- ⌛ SPICE-ns Obstacle Model
- ✅ SPICE-ns Mobility Model
- ⌛ SPICE-ns Energy Model
- ✅ SPICE-ns Visualization Tools

   
### 🚀 Project Status 

As a first step, we have successfully implemented a mobility model for SPICE-ns.


###############################################################################
# The GNUplot Script developed for the Research work on
#
#     Design and Implementation of Novel Protocols for Deep Space Network 
#            Using SPICE Toolkit and Kernels Under ns-3
# 
# Developed by :           Jason Pandian,(pandiajason@gmail.com)
#                          Assistant Professor, Department of Information and Technology,
#                          Nehru Institute of Technology, Coimbatore,
#                          India.
# 
# 
# Declaration"
# This project uses binary version of NASA/NAIF's SPICE tool kit and
# Some of the Text and Binary version of SPICE Kernels/Data
###############################################################################
#!usr/bin/gnuplot

set terminal pngcairo  enhanced  font "arial,14"  size 700,500	linewidth 2
#set terminal png nocrop enhanced font "arial,14" size 700,500
#set terminal png linewidth 2

set xtics nomirror rotate by -0 font "arial,14"
set ytics nomirror rotate by -0 font "arial,14"

set style data linespoints


set xlabel font "arial,15"
set ylabel font "arial,15"

set key right
set key font "arial,15"
set title font "arial,16"

set pointsize 1.5


set output "./'SPICE-ns-MobilityModelCPUTimeUsageLog.Plot.png"
set title 'Ephemeris Step Time vs Simulation Run Time'
set xlabel 'Ephemeris Step Time (in seconds)'
set ylabel 'CPU Time (in seconds)'
plot 'SPICE-ns-MobilityModelRamAndCPUTimeUsageLog.txt' using 1:2 title "CASSINI + 4 moons of Saturn"


set output "./'SPICE-ns-MobilityModelRamUsageLog.Plot.png"
set title 'Ephemeris Step Time vs RAM Consumed'
set xlabel 'Ephemeris Step Time (in seconds)'
set ylabel 'RAM Consumed (in MB)'
plot 'SPICE-ns-MobilityModelRamAndCPUTimeUsageLog.txt' using 1:($3/1024) title "CASSINI + 4 moons of Saturn"

###############################################################################

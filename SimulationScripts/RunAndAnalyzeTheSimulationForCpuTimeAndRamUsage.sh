###############################################################################
# The Shell Script developed for the Research work on
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
#!/bin/bash

# compile to update the latest version in /build directory

# cd ns-3 installation folder
./ns3 


# The simulation is approximately simulating 4.57056e+07 seconds / 528.6 days /  17.37months 
# of movement of CASSINI and 4 moons of the planet SATURN

etTimeSteps="125 250 500 1000 2000 4000 8000"

>SPICE-ns-MobilityModelRamAndCPUTimeUsageLog.txt


for etTimeStep in $etTimeSteps
do
	#set path according to the installation folder of ns-3
	./build/scratch/ns3.40-EvaluationOfSPICE-ns-MobilityModel-default --etTimeStep=$etTimeStep &  # Start your application in the background

	pid=$!  # Get the PID of the last background command

	echo "Process ID (PID): $pid  etTimeStep : $etTimeStep"

	start_time=$(date +%s)
	
	sum=0
	while ps -p $pid > /dev/null; do
		  total_memory=$(pmap -x $pid | grep "total" | awk '{print $4}')
		  sum=$((sum + total_memory))
		  # Log $etTimeStep and total memory usage(in kB)	   
		  sleep 1  # Adjust the interval as needed
	done
	end_time=$(date +%s)	
	
	execution_time=$((end_time - start_time))

        averageMemUsage=$((sum / 7))

	#echo "Process Terminated"
	
	echo "$etTimeStep $execution_time $averageMemUsage"
	echo "$etTimeStep $execution_time $averageMemUsage" >>SPICE-ns-MobilityModelRamAndCPUTimeUsageLog.txt
done

###############################################################################





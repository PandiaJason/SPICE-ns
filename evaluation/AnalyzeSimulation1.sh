#!/bin/bash



./build/scratch/ns3.40-SPICE-ns-CASSINI-example1-default &  # Start your application in the background



pid=$!  # Get the PID of the last background command

echo "Process ID (PID): $pid"

start_time=$(date +%s)

> ns3.40-SPICE-ns-CASSINI-example1Process-log.txt

while ps -p $pid > /dev/null; do
   
  # Log CPU usage using ps
  ps -p $pid -o %cpu,%mem --no-headers >> ns3.40-SPICE-ns-CASSINI-example1Process-log.txt
  
  total_memory=$(pmap -x $pid | grep "total" | awk '{print $4}')

  # Log total memory usage
  echo "Total Memory Usage: $total_memory KB" >>  ns3.40-SPICE-ns-CASSINI-example1Process-log.txt

   
  sleep 1  # Adjust the interval as needed
done

end_time=$(date +%s)

echo "Process Terminated"
execution_time=$((end_time - start_time))


echo "Elapsed Time: $execution_time seconds"

echo "Elapsed Time: $execution_time seconds" >> ns3.40-SPICE-ns-CASSINI-example1Process-log.txt
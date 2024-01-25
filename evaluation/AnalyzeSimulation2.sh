#!/bin/bash



./build/scratch/ns3.40-SPICE-ns-CASSINI-example2-default &  # Start your application in the background

pid=$!  # Get the PID of the last background command

echo "Process ID (PID): $pid"

> ns3.40-SPICE-ns-CASSINI-example2Process-log.txt

start_time=$(date +%s)
while ps -p $pid > /dev/null; do
  ps -p $pid -o %cpu,%mem --no-headers >> ns3.40-SPICE-ns-CASSINI-example2Process-log.txt
  sleep 1  # Adjust the interval as needed
done
end_time=$(date +%s)

echo "Process Terminated"
execution_time=$((end_time - start_time))


echo "Elapsed Time: $execution_time seconds"

echo "Elapsed Time: $execution_time seconds" >> ns3.40-SPICE-ns-CASSINI-example2Process-log.txt
#!/bin/bash

queue=(98 183 37 122 14 124 65 67)
head=53
seek=0

echo "FCFS Disk Scheduling"
echo "Request Queue : ${queue[*]}"
echo "Initial Head Position : $head"

for req in "${queue[@]}"
do
    diff=$((req - head))

    if [ $diff -lt 0 ]
    then
        diff=$((-diff))
    fi

    seek=$((seek + diff))
    head=$req
done

echo "Total Head Movement = $seek"

#!/bin/bash

queue=(98 183 37 122 14 124 65 67)
head=53
disk_size=200
seek=0

echo "C-SCAN Disk Scheduling"
echo "Request Queue : ${queue[*]}"
echo "Initial Head Position : $head"
echo "Disk Size : $disk_size"

# Sort request queue
IFS=$'\n' sorted=($(sort -n <<<"${queue[*]}"))
unset IFS

# Move towards higher cylinders
for req in "${sorted[@]}"
do
    if [ $req -ge $head ]
    then
        diff=$((req - head))
        seek=$((seek + diff))
        head=$req
    fi
done

# Move to the end
seek=$((seek + (disk_size - 1 - head)))
head=$((disk_size - 1))

# Jump to beginning
seek=$((seek + (disk_size - 1)))
head=0

# Service remaining requests
for req in "${sorted[@]}"
do
    if [ $req -lt 53 ]
    then
        diff=$((req - head))
        seek=$((seek + diff))
        head=$req
    fi
done

echo "Total Head Movement = $seek"

#!/bin/bash

queue=(98 183 37 122 14 124 65 67)
head=53
seek=0
visited=()
count=0
n=${#queue[@]}

echo "SSTF Disk Scheduling"
echo "Request Queue : ${queue[*]}"
echo "Initial Head Position : $head"

while [ $count -lt $n ]
do
    min=9999
    index=-1

    for ((i=0; i<n; i++))
    do
        if [[ ! " ${visited[*]} " =~ " $i " ]]
        then
            diff=$((queue[i] - head))

            if [ $diff -lt 0 ]
            then
                diff=$((-diff))
            fi

            if [ $diff -lt $min ]
            then
                min=$diff
                index=$i
            fi
        fi
    done

    seek=$((seek + min))
    head=${queue[index]}
    visited+=($index)
    count=$((count + 1))
done

echo "Total Head Movement = $seek"

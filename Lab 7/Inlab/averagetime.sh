#!/bin/bash

# Alisha Meena Gursahaney
# Inlab 7
# amg9zd

# some code taken from previous averagetime.sh file

echo "enter the exponent for counter.cpp" 
read exponent

# exit if input is quit
if (( exponent == "quit" )) 
then
	exit 0
fi

sum=0


# googled shell script for loop
#sum = 0
#for((i=0 ; i < 5 ; i++)); do
	#sum += RUNNING_TIME=`./a.out $dict $grid | tail -1`
#done

for (( i=0; i<5; i++))
do
	echo "Running iteration ${i} ..."
	RUNNING_TIME=`./a.out $exponent | tail -1`
	sum=`expr $sum + $RUNNING_TIME `
	echo "time taken: ${RUNNING_TIME} ms"
done

# googled expression syntax for shell script

average=`expr $sum/5`

echo "Average time: ${average} ms"

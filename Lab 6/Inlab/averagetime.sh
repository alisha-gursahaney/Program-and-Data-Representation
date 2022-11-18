#!/bin/bash
# first line of code to use the right shell

# 5 lines without a loop
# no spaces by = signs

# how to take in dict and grid inputs


# copied and pasted from PDR


# take in parameters dictionary and grid and save them as a variable name
# echo "Input dictionary file"
read "Input dictionary file" dict

# echo "Input grid file"
read "Input grid file" grid


# googled shell script for loop
#sum = 0
#for((i=0 ; i < 5 ; i++)); do
	#sum += RUNNING_TIME=`./a.out $dict $grid | tail -1`
#done
RUNNING_TIME1=`./a.out $dict $grid | tail -1`
RUNNING_TIME2=`./a.out $dict $grid | tail -1`
RUNNING_TIME3=`./a.out $dict $grid | tail -1`
RUNNING_TIME4=`./a.out $dict $grid | tail -1`
RUNNING_TIME5=`./a.out $dict $grid | tail -1`

# sum=`expr$RUNNING_TIME1+$RUNNING_TIME2+$RUNNING_TIME3+$RUNNING_TIME4+$RUNNING_TIME5`
# can only add 2 variables at once

# googled expression syntax for shell script

sum1=`expr $RUNNING_TIME1 + $RUNNING_TIME2`
sum2=`expr $RUNNING_TIME3 + $RUNNING_TIME4`
sum3=`expr $sum1 + $sum2`
sum4=`expr $sum3 + $RUNNING_TIME5`


average=`expr $sum4 / 5`

echo $average


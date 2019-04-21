#!/bin/sh
#nohup ./mpu6500 > /dev/null &
echo "MPU6500 Demo Program";
desc="mpu6500"
pid=""

if [ $1 == "stop" ]; then
	echo "Stopping..."
	pid=`ps aux|grep $desc | grep -v grep | awk '{print $2}'`
	if [[ $pid != "" ]]
	then
		kill -9 $pid
	fi
elif [ $1 == "start" ]; then
	echo "Starting..."
	nohup ./mpu6500 > /dev/null &
fi
echo "done"

#!/bin/bash

echo RELATED > /sys/bus/msm_subsys/devices/subsys3/restart_level 
echo RELATED > /sys/bus/msm_subsys/devices/subsys4/restart_level 
insmod /golden/dsp-offset_taskset_cpustat_mqueue.ko
sysctl -w kernel.sched_rt_runtime_us=-1

export ROS_HOME=/eng/ros
export ROS_PACKAGE_PATH=/home/root/quest_ws/src:/opt/ros/indigo/share:/opt/ros/indigo/stacks
export PYTHONPATH=/home/root/quest_ws/devel/lib/python2.7/site-packages:/opt/ros/indigo/lib/python2.7/site-packages
export ROS_ETC_DIR=/opt/ros/indigo/etc/ros
export ROS_ROOT=/opt/ros
export ROS_DISTRO=indigo
export PATH=$PATH:/opt/ros/indigo/bin
export LD_LIBRARY_PATH=/opt/ros/indigo/lib
export ROS_HOSTNAME=127.0.0.1
export ROS_MASTER_URI=http://127.0.0.1:11311
export CMAKE_PREFIX_PATH=/opt/ros/indigo


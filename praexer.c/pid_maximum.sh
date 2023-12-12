#!/bin/bash
pid_maximum=$(cat /proc/sys/kernel/pid_max)
echo "MAXIMUM PID VALUE: $pid_maximum"

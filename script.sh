#!/bin/bash
#SCRIPT FOR RUNNING C++ CODE IN BASH
echo -e "enter file path to run : "
read src
clear
g++ $src
./a
read
echo  -e "
...execution complete"
rm a

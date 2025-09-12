#!/bin/bash

gcc hello_exit.c -o hello_exit
./hello_exit
status=$?
if [ $status -eq 0 ]; then
	echo "OS sees: Program succeeded."
else
	echo "OS sees: Program failed with code $status."
fi

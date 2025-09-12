############## run.sh ###############

#!/bin/bash
set -e

# Compile both programs
gcc gen_data.c -o gen_data
gcc sum_from_file.c -o sum_from_file

# Run first program, redirect output to file
./gen_data > numbers.txt

# Run second program, taking input from file
./sum_from_file < numbers.txt

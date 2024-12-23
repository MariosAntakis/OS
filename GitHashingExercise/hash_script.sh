#!/bin/bash

if [ "$#" -eq 0 ]; then
	echo "No arguments provided. Please input a number with more than 4 digits: "
	read input
else
	input=$1
fi

last_four_digits="${input: -4}"

hash=$(echo -n "$input" | sha256sum | awk '{print $1}')

echo $hash > hash_output.txt

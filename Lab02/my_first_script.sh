#!/bin/bash

date

if [ -d "/etc" ] && [ -f "/etc/passwd" ]; then
	echo "Both the /etc directory and the /etc/passw file exist."
fi

if [ ! -f "example.txt" ]; then
	echo "The file example.txt does not exist."
fi

number=5
echo $number
let number=number+number
echo $number

# Using $( )
current_date=$(date)
echo "Today's date is : $current_date"

# Using backticks ` `
current_user=`whoami`
echo "Current user: $current_user"

# Nested Command substitution
file_count=$(ls -1 $(pwd) | wc -l)
echo "Number of files in the current directory: $file_count"


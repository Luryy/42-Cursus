#!/bin/sh

RESET="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"

BOLDBLACK="\033[1m\033[30m"
BOLDRED="\033[1m\033[31m"
BOLDGREEN="\033[1m\033[32m"
BOLDYELLOW="\033[1m\033[33m"
BOLDBLUE="\033[1m\033[34m"
BOLDMAGENTA="\033[1m\033[35m"
BOLDCYAN="\033[1m\033[36m"
BOLDWHITE="\033[1m\033[37m"

TEST_PARSED="test"
function exec_test()
{
	printf $YELLOW
	TEST=$(echo $1 | ./minishell 2>&-)
	TEST_PARSED=$(sed '1d; $d' <<< $TEST)
	sleep 0.1
}

# MIXS

# Testing RF and PIPE
echo
printf $WHITE"------Testing RF and PIPE------\n"
exec_test 'echo test1 > file | echo test2'
COMPARE_RETURN="test2"
COMPARE_FILE="test1"
if grep -q "$COMPARE_FILE" file && echo $TEST_PARSED | grep -q "$COMPARE_RETURN"; then
	printf " $BOLDGREEN%s$RESET" "✓ "
else
	printf " $BOLDRED%s$RESET" "✗ "
fi
rm file
echo












# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 20:49:02 by passunca          #+#    #+#              #
#    Updated: 2024/06/16 20:49:06 by passunca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

print_test() {
   N_ARGS=$(wc -w < rand.txt | awk '{print $1}')
   N_OPS=$(wc -l < out.txt)
   echo "*** ${N_ARGS} elements sorted in: ${N_OPS} ops"
}

test_subject() {
   echo "Running push_swap tests from subject"
   echo "*** Error Handling Tests ***"
   echo "1/5 : Success test (correct args)"
  ./push_swap 2 1 3 6 5 8
   echo "2/5 : Failure test (wrong args)"
  ./push_swap 0 one 2 3
  echo "3/5 : Failure test (wrong args)"
  ./push_swap 0 "" 2 3
  echo "4/5 : Error handling (for n > INT_MAX test)"
  ./push_swap 2147483648 1 2
  ./push_swap 0 21474836848 1 2
  ./push_swap "0 1 2147483648 2"
  echo "5/5 : Error handling (No args)"
  ./push_swap
  echo "*** Identity Tests ***"
  echo "1/1 : no output expected (Sorted stacks)"
  ./push_swap 42
  ./push_swap 2 3
  ./push_swap 0 1 2 3
  ./push_swap 0 1 2 3 4 5 6 7 8 9
  ./push_swap 1 3 5 6 8 9
  echo "*** \$ARG Tests ***"
  echo "1/4 : Simple test (sort 3 elements)"
  ARG="2 1 0";./push_swap $ARG |./checker_linux $ARG
  echo "2/4 : Simple test (sort 4 elements)"
  ARG="2 1 0 3";./push_swap $ARG |./checker_linux $ARG
  echo "3/4 : Simple test (sort 5 elements)"
  ARG="1 5 2 4 3";./push_swap $ARG |./checker_linux $ARG
  echo "4/4 : Simple test (sort 5 elements)"
  ARG="7 3 9 11 0";./push_swap $ARG |./checker_linux $ARG
}

echo "Starting tests..."

test_subject

echo "All tests completed."

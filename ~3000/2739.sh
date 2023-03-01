#!/bin/sh

function answer(){
  local num=$1
  local star="*"
  for var in {1..10}
    do
      echo -e "$num "
      echo "${star}"
      echo -e "$var  =  $((num * var)) \n"

    done
}

result=$(answer 2)
#echo -e $result

local num=2
local star="*"
for var in {1..10}
  do
    echo -e "$num "
    echo "${star}"
    echo -e "$var  =  $((num * var)) \n"

  done
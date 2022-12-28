#!/bin/bash

fun ()
{ 
	shuf -i 0-1000 -n 500 | tr "\\n" " "
	echo " "
}

fun
exit 0
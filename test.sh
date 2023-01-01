#!/bin/bash

fun ()
{ 
	shuf -i 0-30 -n 15 | tr "\\n" " "
	echo " "
}

fun
exit 0
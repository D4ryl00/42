#!/bin/sh

touch -A -01 -a bomb.txt
stat -f %a bomb.txt

exit 0

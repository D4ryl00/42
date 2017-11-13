#!/bin/sh

if [ $# -eq 0 ]
then
	exit 1
fi

grep -E -i '(^nicolas\tbauer|^bauer\tnicolas)' "$1" | grep -E '\t([0-9()-]{10,})\t' | cut -f 3

exit 0

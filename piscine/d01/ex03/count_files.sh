#!/bin/sh

find . -type d -or -type f | wc -l | sed 's/ //g'

exit 0

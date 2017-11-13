#!/bin/sh

find . -type f -regex ".*\.sh$" | sed 's:.*/::' | sed 's/.sh$//'

exit 0

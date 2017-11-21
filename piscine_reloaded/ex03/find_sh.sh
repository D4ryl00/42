#!/bin/sh

find . -type f -regex ".*/.*\.sh" | sed 's/.*\///g' | sed 's/\.sh$//'

exit 0

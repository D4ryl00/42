#!/bin/sh

ls -l | sed -n '1,$ {p;n;}'

exit 0

#!/bin/sh

ldapsearch sn='*bon*' sn | grep "^sn:" | wc -l | tr -d '[:blank:]'

exit 0

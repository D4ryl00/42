#!/bin/sh

ldapsearch uid='z*' cn | grep "^cn:" | sed 's/cn: //g' | sort -fr

exit 0


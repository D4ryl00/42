#!/bin/sh

ifconfig | grep ether | sed 's/ether//' | tr -d '[:blank:]'

exit 0

#!/bin/sh

ldapwhoami | cut -d ':' -f 2

exit 0

#!/bin/sh

echo $(date)

# UPDATE PACKAGE LIST
apt update

# UPGRADE SYSTEM
apt -y upgrade

exit 0

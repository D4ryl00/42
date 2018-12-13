#!/bin/sh

# Flush
iptables -F

# Default policy
iptables -P FORWARD DROP
iptables -P INPUT DROP
iptables -P OUTPUT ACCEPT

# Allow established connections (the responses to our outgoing traffic)
iptables -A INPUT -m state --state ESTABLISHED,RELATED -j ACCEPT

# Allow local programs that use loopback (Unix sockets)
iptables -A INPUT -s 127.0.0.0/8 -d 127.0.0.0/8 -i lo -j ACCEPT

# Allow sshd connections
iptables -A INPUT -p tcp --dport 62222 -m state --state NEW -m limit --limit 2/second --limit-burst 2 -j ACCEPT

# Allow HTTP AND HTTPS connections
iptables -A INPUT -p tcp --dport 8080 -m state --state NEW -m limit --limit 10/second --limit-burst 5 -j ACCEPT
iptables -A INPUT -p tcp --dport 4443 -m state --state NEW -m limit --limit 10/second --limit-burst 5 -j ACCEPT

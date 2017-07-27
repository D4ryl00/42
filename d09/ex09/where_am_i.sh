#/bin/sh

IPS=$( ifconfig | grep -E 'inet ' | grep -v 127.0.0.1 | tr -d '\t' | cut -d ' ' -f2 )
if [ -z "$IPS" ]
then
	echo 'Je suis perdu!'
else
	echo "$IPS"
fi

exit 0

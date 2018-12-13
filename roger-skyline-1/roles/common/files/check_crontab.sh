#!/bin/sh

FILE=/etc/crontab
DEST=crontab_sum

MD5=$(md5sum $FILE)
if [ ! -e crontab_sum ]
then
	echo "$MD5" > $DEST 
else
	MD5_BACK=$(cat $DEST)
	if [ "$MD5" != "$MD5_BACK" ]
	then
		echo "The $FILE has been modified!" | mail -s "crontab modified" root
		echo "$MD5" > $DEST 
	fi
fi

exit 0

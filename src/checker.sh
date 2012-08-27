#!/bin/sh
if pgrep -u root careful ; then
        exit 0
else
        /usr/bin/careful <yourIP> 1 5 & 
        exit 0
fi

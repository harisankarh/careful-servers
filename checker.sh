#!/bin/sh
if pgrep -u root suicide ; then
        exit 0
else
        /usr/bin/suicide 10.6.9.200 1 5 & 
        exit 0
fi

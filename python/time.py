#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# epoch
# The epoch is the point where the time starts. On January 1st of that year, at 0 hours, the “time since the epoch” is zero.
# For Unix, the epoch is 1970.

import time

# get seconds since epoch (unix time)
seconds_since_epoch = time.time()
print('seconds_since_epoch: {0:.2f}'.format(seconds_since_epoch) )

# seconds since epoch to struct time in UTC
time_struct = time.gmtime(seconds_since_epoch)
#print(  )

# get unixtime
print(time.time())

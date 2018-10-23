#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Script to provide basic example of HTTP POST-request sending

import requests
import json
import getpass


print('Get github user info')
login = raw_input('login: ')
password = getpass.getpass('password: ')
result = requests.get('https://api.github.com/user', auth=(login, password)) #GET
print("HTTP GET request code: " + str(result.status_code))
print("Content-type: " + str(result.headers['content-type']))

user_info = result.json()
for k in sorted(user_info.keys(), key=lambda x: len(str(x))):
    print('{0:25} {1}'.format( k, user_info[k]) )
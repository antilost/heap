#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import time
import re
import telepot
import random
from telepot.loop import MessageLoop


def main(token):
    bot = telepot.Bot(token)

    def handle(msg):
        content_type, chat_type, chat_id = telepot.glance(msg)
        print(content_type, chat_type, chat_id)

        try:
            if (chat_id == 224681791) or ( (content_type == 'text') and (msg['text'] == 'asshole') ):
                m = 10 + int( random.random() * 11 )
                bot.sendMessage(chat_id, '❤️' * m)
                return
            if content_type != 'text':
                return
            if re.match('^[0-9]+$', msg['text']):
                number = int(msg['text'])
                result = number ** 2
                bot.sendMessage(chat_id, str(result))
            else:
                bot.sendMessage(chat_id, "Me want number! INTEGER-R-R!!!")
        except:
            print('error')
            return;

    MessageLoop(bot, handle).run_as_thread()
    print('Listening ...')
    while 1:
        time.sleep(5)

if __name__ == '__main__':
    token = sys.argv[1]
    main(token)

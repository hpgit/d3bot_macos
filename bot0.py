import matplotlib.pyplot as plt
import numpy as np

import opencv



def get_win_info(username):
    window_x, window_y = 0, 0
    w, h = 0, 0

    with open('/Users/'+username+'/Library/Application Support/Blizzard/Diablo III/D3Prefs.txt') as f:
        ss = [s for s in f.read().splitlines()]
        for s in ss:
            if 'DisplayModeWinLeft' in s:
                window_x = int(s.split('"')[1])
            elif 'DisplayModeWinTop' in s:
                window_y = int(s.split('"')[1])
            elif 'DisplayModeWinWidth' in s:
                w = int(s.split('"')[1])
            elif 'DisplayModeWinHeight' in s:
                h = int(s.split('"')[1])
            # elif 'DisplayModeWidth' in s:
            #     w = int(s.split()[1])
            # elif 'DisplayModeHeight' in s:
            #     h = int(s.split()[1])

    return window_x, window_y, w, h


# print(get_win_info('trif'))

opencv.opencv_test()

from controller import *
import key_code
from time import sleep

# mouse_move(30, 50)
# mouse_move(1400, 870)
# mouse_move(1700, 880)
# mouse_move(2200, 700)
# mouse_move(2400, 850)


# sleep(0.5)


if False:
    for i in range(6):
        for j in range(3):
            mouse_down(1, 1700, 880)
            sleep(0.05)
            mouse_up(1, 1700, 880)

            sleep(0.2)

            mouse_down(0, 2200+i*40, 700+j*75)
            sleep(0.05)
            mouse_up(0, 2200+i*40, 700+j*75)

            sleep(0.2)

            mouse_down(1, 1400, 870)
            sleep(0.05)
            mouse_up(1, 1400, 870)

            sleep(3)

            mouse_down(1, 1400, 870)
            sleep(0.05)
            mouse_up(1, 1400, 870)


# for _ in range(5):
#     key_press(key_code.kVK_Shift)
#     key_press(key_code.kVK_ANSI_Z)
#     key_release(key_code.kVK_ANSI_Z)
#     key_release(key_code.kVK_Shift)


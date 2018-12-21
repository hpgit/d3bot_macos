//
// Created by trif on 2018-12-14.
//

#include <ApplicationServices/ApplicationServices.h>
#include <unistd.h>

#include "controller.h"

#include <boost/python.hpp>


BOOST_PYTHON_MODULE(controller)
{
    boost::python::def("mouse_move", &mouse_move);
    boost::python::def("mouse_up", &mouse_up);
    boost::python::def("mouse_down", &mouse_down);
    boost::python::def("key_press", &key_press);
    boost::python::def("key_release", &key_release);
}

void mouse_move(int x, int y)
{
    CGEventRef move = CGEventCreateMouseEvent(
            NULL, kCGEventMouseMoved,
            CGPointMake(x, y),
            kCGMouseButtonLeft // ignored
    );
    CGEventPost(kCGHIDEventTap, move);
    CFRelease(move);
    usleep(60);
}

void mouse_up(int side, int x, int y)
{
    if (side == 0) {
        // Right side
        CGEventRef click_up = CGEventCreateMouseEvent(
                NULL, kCGEventRightMouseUp,
                CGPointMake(x, y),
                kCGMouseButtonRight
        );
        CGEventPost(kCGHIDEventTap, click_up);
        CFRelease(click_up);
    }
    else if (side == 1) {
        // Left side
        CGEventRef click_up = CGEventCreateMouseEvent(
                NULL, kCGEventLeftMouseUp,
                CGPointMake(x, y),
                kCGMouseButtonLeft
        );
        CGEventPost(kCGHIDEventTap, click_up);
        CFRelease(click_up);
    }
    usleep(60);
}


void mouse_down(int side, int x, int y)
{
    if (side == 0) {
        // Right side
        CGEventRef click_down = CGEventCreateMouseEvent(
                NULL, kCGEventRightMouseDown,
                CGPointMake(x, y),
                kCGMouseButtonRight
        );
        CGEventPost(kCGHIDEventTap, click_down);
        CFRelease(click_down);
    }
    else if (side == 1) {
        // Left side
        CGEventRef click_down = CGEventCreateMouseEvent(
                NULL, kCGEventLeftMouseDown,
                CGPointMake(x, y),
                kCGMouseButtonLeft
        );
        CGEventPost(kCGHIDEventTap, click_down);
        CFRelease(click_down);
    }
    usleep(60);
}

void key_press(int key)
{
    CGEventSourceRef src = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);
    CGEventRef down = CGEventCreateKeyboardEvent(src, (CGKeyCode) key, true);

    CGEventPost(kCGHIDEventTap, down);

    CFRelease(down);
    CFRelease(src);

    usleep(60);
}


void key_release(int key)
{
    CGEventSourceRef src = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);
    CGEventRef up = CGEventCreateKeyboardEvent(src, (CGKeyCode) key, false);

    CGEventPost(kCGHIDEventTap, up);
    CFRelease(up);
    CFRelease(src);

    usleep(60);
}
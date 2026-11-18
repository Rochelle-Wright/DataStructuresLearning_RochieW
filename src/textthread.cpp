#include "textthread.h"
#include <iostream>

TextThread::TextThread() {
    head_ = nullptr;
    tail_ = nullptr;
    messageCount_ = 0;
}
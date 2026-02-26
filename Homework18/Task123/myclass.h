#pragma once

#include "counter.h"

class MyClass {
public:

    MyClass() {
        Counter::onDefault();
    }


    MyClass(const MyClass&) {
        Counter::onCopy();
    }


    MyClass(MyClass&&) noexcept {
        Counter::onDefault();
    }


    ~MyClass() {
        Counter::onDestroy();
    }
};
#include "calc.h"
#include <cassert>

calc::calc(/* args */) {
}

calc::~calc() {
}

size_t calc::add(size_t a, size_t b) {
    return a + b;
}
size_t calc::sub(size_t a, size_t b) {
    return a - b;
}

size_t calc::div(size_t a, size_t b) {
    if (b == 0) {
        assert(b);
        return 0;
    }
    return a / b;
}

size_t calc::mul(size_t a, size_t b) {
    return a * b;
}
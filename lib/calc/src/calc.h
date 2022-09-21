#ifndef __CALC_H__
#define __CALC_H__

#include <stdint.h>
#include <stddef.h>

class calc
{
private:
    /* data */
public:
    calc(/* args */);
    size_t add(size_t a, size_t b);
    size_t sub(size_t a, size_t b);
    size_t div(size_t a, size_t b);
    size_t mul(size_t a, size_t b);
    ~calc();
};



#endif
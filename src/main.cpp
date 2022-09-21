#if defined(ARDUINO)
#include <Arduino.h>

#include "calc.h"
calc mycal;
// cppcheck-suppress unusedFunction
void setup() {
    // put your setup code here, to run once:
    mycal.add(1, 2);
    mycal.sub(1, 2);
    mycal.div(1, 2);
    mycal.mul(1, 2);
}

// cppcheck-suppress unusedFunction
void loop() {
    // put your main code here, to run repeatedly:
}
#else
#include <stdio.h>

#include "calc.h"
calc mycal;
int main(int argc, char **argv) {
    mycal.add(1, 2);
    mycal.sub(1, 2);
    mycal.div(1, 2);
    mycal.mul(1, 2);
    return 0;
}
#endif

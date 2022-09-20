#include <gtest/gtest.h>

TEST(DemoTest, Passing) {
    EXPECT_EQ(1, 1);
}

TEST(DemoTest, Falling) {
    EXPECT_NE(1, 0);
}

#if defined(ARDUINO)
#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    delay(1000);

    testing::InitGoogleTest();
    if (RUN_ALL_TESTS())
        ;
}

void loop() {
    // nothing to be done here.
    delay(100);
}
#else
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    // if you plan to use GMock, replace the line above with
    // ::testing::InitGoogleMock(&argc, argv);

    if (RUN_ALL_TESTS())
        ;

    // Always return zero-code and allow PlatformIO to parse results
    return 0;
}
#endif
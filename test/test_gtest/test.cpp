#include <gtest/gtest.h>
#include "Queue.h"

// prototype
bool test_prediction_n1(int n1) { return n1 == 1; }
bool test_prediction_n2(int n1, int n2) { return ((n1 == 1) && (n2 == 2)); }
bool test_prediction_n3(int n1, int n2, int n3) { return ((n1 == 1) && (n2 == 2) && (n3 == 3)); }
bool test_prediction_n4(int n1, int n2, int n3, int n4) { return ((n1 == 1) && (n2 == 2) && (n3 == 3) && (n4 == 4)); }
bool test_prediction_n5(int n1, int n2, int n3, int n4, int n5) { return ((n1 == 1) && (n2 == 2) && (n3 == 3) && (n4 == 4) && (n5 == 5)); }

testing::AssertionResult test_prediction_form_n2(const char *a_expr, const char *b_expr, int a, int b) {
    if (a == b)
        return testing::AssertionSuccess();
    return testing::AssertionFailure() << a_expr << " and " << b_expr << " is not equal";
}

// EXPECT, ASSERT
TEST(DemoTest, ExpectTest) {
    EXPECT_EQ(1, 1);
    EXPECT_NE(1, 3);
    EXPECT_LT(1, 3);
    EXPECT_LE(2, 2);
    EXPECT_GT(10, 5);
    EXPECT_GE(15, 15);
    EXPECT_TRUE(true);
    EXPECT_FALSE(false);
}

TEST(DemoTest, FloatTest) {
    float val1 = 25.551122;
    float val2 = 25.551124;
    double dval1 = 25.55115522;
    double dval2 = 25.55115522;
    double dval3 = 25.55115532;
    EXPECT_FLOAT_EQ(val1, val2);
    EXPECT_DOUBLE_EQ(dval1, dval2);
    EXPECT_NEAR(dval1, dval3, 0.00000020);
}

TEST(DemoTest, StringTest) {
    const char *str1 = "hello world";
    const char *str2 = "hello world";
    const char *str3 = "Hello World 11";
    const char *str4 = "Hello World";
    EXPECT_STREQ(str1, str2);
    EXPECT_STRNE(str1, str4);
    EXPECT_STRCASEEQ(str1, str4);
    EXPECT_STRCASENE(str1, str3);
}

TEST(DemoTest, SkipTest) {
    EXPECT_EQ(1, 1);
    GTEST_SKIP() << "Skipping Test...";
    ASSERT_EQ(1, 1);
}

TEST(DemoTest, PredictTest) {
    EXPECT_PRED1(test_prediction_n1, 1);
    EXPECT_PRED2(test_prediction_n2, 1, 2);
    EXPECT_PRED3(test_prediction_n3, 1, 2, 3);
    EXPECT_PRED4(test_prediction_n4, 1, 2, 3, 4);
    EXPECT_PRED5(test_prediction_n5, 1, 2, 3, 4, 5);
}

TEST(DemoTest, PredictFormTest) {
    int x = 10;
    int y = 10;
    int z = 11;
    EXPECT_PRED_FORMAT2(test_prediction_form_n2, x, y);
    // EXPECT_PRED_FORMAT2(test_prediction_form_n2, x, z);
}

TEST(DemoTest, ScopeTrace) {
    {
        SCOPED_TRACE("trace point....");
        EXPECT_EQ(1, 1);        // EXPECT_NE(1, 1);
    }
    EXPECT_EQ(1, 1);            // EXPECT_EQ(1, 1);
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
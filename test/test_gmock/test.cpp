#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "bankServer.h"
using ::testing::AtLeast;
using ::testing::Return;

class MockBankServer : public BankServer {
   private:
    /* data */
   public:
    MockBankServer(/* args */) {}
    ~MockBankServer() {}

    MOCK_METHOD0(Connect, void());
    MOCK_METHOD2(Credit, void(int, int));
    MOCK_METHOD2(Debit, void(int, int));
    MOCK_METHOD1(GetBalance, int(int));
    MOCK_METHOD0(Disconnect, void());
};

TEST(ATMMachine, Withdraw) {
    MockBankServer bank;
    ATMMachine<MockBankServer> ATM(&bank);
    
    EXPECT_CALL(bank, Connect)
        .Times(AtLeast(1));
    EXPECT_CALL(bank, Debit)
        .Times(AtLeast(1));
    EXPECT_CALL(bank, Disconnect)
        .Times(AtLeast(1));
    EXPECT_CALL(bank, GetBalance)
        .Times(AtLeast(1)).WillRepeatedly(Return(2000));

    bool result = ATM.Withdraw(111, 1500);
    EXPECT_TRUE(result);
}

#if defined(ARDUINO)
#include <Arduino.h>

void setup() {
    delay(5000);
    Serial.begin(115200);
    delay(1000);
    ::testing::InitGoogleMock();
    if (RUN_ALL_TESTS())
        ;
}

void loop() {
    // nothing to be done here.
    delay(100);
}

#else

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
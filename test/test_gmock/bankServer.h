#ifndef _BANKSERVER_H_
#define _BANKSERVER_H_

class BankServer {
   private:
    /* data */
   public:
    BankServer(/* args */) {}
    void Connect() {
    }

    void Disconnect() {
    }

    void Credit(int account_num, int value) {
    }

    void Debit(int account_num, int value) {
    }

    int GetBalance(int account_num) {
        return 0;
    }

    ~BankServer() {}
};

template <typename T>
class ATMMachine {
   private:
    /* data */
    T *_bankserver;

   public:
    ATMMachine(T *bankServer) { _bankserver = bankServer; }
    bool Withdraw(int account_number, int val) {
        bool result = false;

        _bankserver->Connect();

        int availableBal = _bankserver->GetBalance(account_number);
        if (availableBal >= val) {
            _bankserver->Debit(account_number, val);
            result = true;
        }

        _bankserver->Disconnect();
        return result;
    }
    ~ATMMachine(){}
};



#endif
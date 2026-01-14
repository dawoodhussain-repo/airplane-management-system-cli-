#ifndef PAYMENT_ACCOUNT_H
#define PAYMENT_ACCOUNT_H

#include <string>

class Payment_Account {
private:
    std::string Acc_num;
    std::string CVV;
    std::string Expire_date;

public:
    Payment_Account();
    Payment_Account(std::string an, std::string cvv, std::string expire_date);
    Payment_Account(const Payment_Account& P);

    std::string getexp();
    std::string getacc();
    std::string getcvv();
};

#endif // PAYMENT_ACCOUNT_H
#include "Payment_Account.h"

Payment_Account::Payment_Account() {
    Acc_num = "N/A";
    CVV = "N/A";
    Expire_date = "N/A";
}

Payment_Account::Payment_Account(std::string an, std::string cvv, std::string expire_date) {
    Acc_num = an;
    CVV = cvv;
    Expire_date = expire_date;
}

Payment_Account::Payment_Account(const Payment_Account& P) {
    Acc_num = P.Acc_num;
    CVV = P.CVV;
    Expire_date = P.Expire_date;
}

std::string Payment_Account::getexp() {
    return Expire_date;
}

std::string Payment_Account::getacc() {
    return Acc_num;
}

std::string Payment_Account::getcvv() {
    return CVV;
}
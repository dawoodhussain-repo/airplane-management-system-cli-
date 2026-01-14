#include "Utilities.h"

bool Finaincial_Verification(Payment_Account P) {
    if (P.getacc().length() != 14) {
        return false;
    }
    if (P.getcvv().length() != 3) { // Fixed: was checking > 3 instead of != 3
        return false;
    }
    if (P.getexp().length() != 4 || P.getexp()[0] < '0' || P.getexp()[0] > '1') { // Fixed: was checking [0] < 51 which is wrong
        return false;
    }
    return true;
}
#include "PaymentHandlers.h"
#include <sstream>

std::string handlePayPal(double amount) {
    std::ostringstream oss;
    oss << "Processing PayPal payment of $" << amount;
    return oss.str();
}

std::string handleGooglePay(double amount) {
    std::ostringstream oss;
    oss << "Processing GooglePay payment of $" << amount;
    return oss.str();
}

std::string handleCreditCard(double amount) {
    std::ostringstream oss;
    oss << "Processing Credit Card payment of $" << amount;
    return oss.str();
}

std::string handleInvalid(double amount) {
    std::ostringstream oss;
    oss << "Invalid payment mode selected! Amount $" << amount << " not processed.";
    return oss.str();
}

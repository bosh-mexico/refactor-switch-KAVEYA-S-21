#include <iostream>
#include "CheckoutService.h"

int main() {
    double amount = 150.75;

    std::cout << checkout(PaymentType::PayPal, amount) << std::endl;
    std::cout << checkout(PaymentType::GooglePay, amount) << std::endl;
    std::cout << checkout(PaymentType::CreditCard, amount) << std::endl;
    std::cout << checkout(PaymentType::Unknown, amount) << std::endl;

    std::cout << checkout(PaymentType::PayPal, -10) << std::endl;
    return 0;
}

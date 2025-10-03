#include <cassert>
#include "CheckoutService.h"

int main() {
    // Valid payments
    assert(checkout(PaymentType::PayPal, 100.0) == "Processing PayPal payment of $100");
    assert(checkout(PaymentType::GooglePay, 50.5) == "Processing GooglePay payment of $50.5");
    assert(checkout(PaymentType::CreditCard, 200) == "Processing Credit Card payment of $200");

    // Invalid payment type
    assert(checkout(PaymentType::Unknown, 100) == "Invalid payment mode selected! Amount $100 not processed.");

    // Invalid amounts
    assert(checkout(PaymentType::PayPal, 0) == "Invalid amount! Payment not processed.");
    assert(checkout(PaymentType::GooglePay, -5) == "Invalid amount! Payment not processed.");
    assert(checkout(PaymentType::CreditCard, -1) == "Invalid amount! Payment not processed.");

    return 0;
}

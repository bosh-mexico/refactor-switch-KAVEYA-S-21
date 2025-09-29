#include "CheckoutService.h"
#include "PaymentHandlers.h"

std::string checkout(PaymentType type, double amount) {
    if (amount <= 0) {
        return "Invalid amount! Payment not processed.";
    }

    switch (type) {
        case PaymentType::PayPal:
            return handlePayPal(amount);
        case PaymentType::GooglePay:
            return handleGooglePay(amount);
        case PaymentType::CreditCard:
            return handleCreditCard(amount);
        default:
            return handleInvalid(amount);
    }
}

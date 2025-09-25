#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Enum for Payment Modes
enum class PaymentMode {
    PayPal,
    GooglePay,
    CreditCard,
    Unknown
};

// Base Interface for Payment Strategy
class IPayment {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~IPayment() = default;
};

// PayPal Payment
class PayPalPayment : public IPayment {
public:
    void processPayment(double amount) override {
        cout << "Processing PayPal payment of $" << amount << endl;
    }
};

// GooglePay Payment
class GooglePayPayment : public IPayment {
public:
    void processPayment(double amount) override {
        cout << "Processing GooglePay payment of $" << amount << endl;
    }
};

// Credit Card Payment
class CreditCardPayment : public IPayment {
public:
    void processPayment(double amount) override {
        cout << "Processing Credit Card payment of $" << amount << endl;
    }
};

// Unknown Payment (Graceful handling)
class UnknownPayment : public IPayment {
public:
    void processPayment(double amount) override {
        cout << " Invalid payment mode! Amount $" << amount << " not processed." << endl;
    }
};

// Factory Method to create Payment object
unique_ptr<IPayment> createPaymentHandler(PaymentMode mode) {
    switch (mode) {
        case PaymentMode::PayPal:      return make_unique<PayPalPayment>();
        case PaymentMode::GooglePay:   return make_unique<GooglePayPayment>();
        case PaymentMode::CreditCard:  return make_unique<CreditCardPayment>();
        default:                       return make_unique<UnknownPayment>();
    }
}

// Checkout Function (depends only on abstraction)
void checkout(PaymentMode mode, double amount) {
    auto payment = createPaymentHandler(mode);
    payment->processPayment(amount);
}

// Example Usage
int main() {
    double amount = 150.75;

    checkout(PaymentMode::PayPal, amount);
    checkout(PaymentMode::GooglePay, amount);
    checkout(PaymentMode::CreditCard, amount);
    checkout(PaymentMode::Unknown, amount);

    return 0;
}

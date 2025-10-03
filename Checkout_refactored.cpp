#include <iostream>
#include <string>
#include <map>
#include <functional>

enum class PaymentType {
    PayPal,
    GooglePay,
    CreditCard,
    Unknown
};

// Example handlers
std::string handlePayPal(double amount) {
    return "Processed PayPal payment of " + std::to_string(amount);
}
std::string handleGooglePay(double amount) {
    return "Processed GooglePay payment of " + std::to_string(amount);
}
std::string handleCreditCard(double amount) {
    return "Processed CreditCard payment of " + std::to_string(amount);
}
std::string handleInvalid(double amount) {
    return "Invalid payment method. Amount " + std::to_string(amount) + " not processed.";
}

// --------------------------------------------------
// Parameterized Service Locator
// --------------------------------------------------
template<typename Key, typename Handler>
class ServiceLocator {
public:
    static ServiceLocator& instance() {
        static ServiceLocator locator;
        return locator;
    }

    void registerHandler(Key key, Handler handler) {
        handlers[key] = handler;
    }

    Handler getHandler(Key key, Handler defaultHandler) const {
        auto it = handlers.find(key);
        if (it != handlers.end()) {
            return it->second;
        }
        return defaultHandler;
    }

private:
    std::map<Key, Handler> handlers;
    ServiceLocator() = default;
};

// --------------------------------------------------
// Checkout using parameterized locator
// --------------------------------------------------
std::string checkout(PaymentType type, double amount) {
    if (amount <= 0) {
        return "Invalid amount! Payment not processed.";
    }

    using Handler = std::function<std::string(double)>;
    auto& locator = ServiceLocator<PaymentType, Handler>::instance();
    auto handler = locator.getHandler(type, handleInvalid);
    return handler(amount);
}

// --------------------------------------------------
// Example usage
// --------------------------------------------------
int main() {
    using Handler = std::function<std::string(double)>;
    auto& locator = ServiceLocator<PaymentType, Handler>::instance();

    locator.registerHandler(PaymentType::PayPal, handlePayPal);
    locator.registerHandler(PaymentType::GooglePay, handleGooglePay);
    locator.registerHandler(PaymentType::CreditCard, handleCreditCard);

    std::cout << checkout(PaymentType::PayPal, 150.0) << "\n";
    std::cout << checkout(PaymentType::GooglePay, 200.0) << "\n";
    std::cout << checkout(PaymentType::CreditCard, 300.0) << "\n";
    std::cout << checkout(PaymentType::Unknown, 400.0) << "\n";
    std::cout << checkout(PaymentType::PayPal, -10.0) << "\n";
}

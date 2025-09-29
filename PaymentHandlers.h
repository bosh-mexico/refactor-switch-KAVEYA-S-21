#pragma once
#include <string>
#include "PaymentTypes.h"

std::string handlePayPal(double amount);
std::string handleGooglePay(double amount);
std::string handleCreditCard(double amount);
std::string handleInvalid(double amount);

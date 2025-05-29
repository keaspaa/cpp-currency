#pragma once
#include "currency_structs.h"
#include <vector>
#include <string>

std::vector<CurrencyRate*> filterByBank(const std::vector<CurrencyRate*>& data, const std::string& bank);
std::vector<CurrencyRate*> filterBySellBelow(const std::vector<CurrencyRate*>& data, double threshold);
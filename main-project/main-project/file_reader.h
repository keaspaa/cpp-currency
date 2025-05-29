#pragma once
#include "currency_structs.h"
#include <vector>
#include <string>

std::vector<CurrencyRate*> readCurrencyData(const std::string& filename);
#include "filters.h"

std::vector<CurrencyRate*> filterByBank(const std::vector<CurrencyRate*>& data, const std::string& bank) {
    std::vector<CurrencyRate*> result;
    for (auto* entry : data) {
        if (entry->bank == bank) result.push_back(entry);
    }
    return result;
}

std::vector<CurrencyRate*> filterBySellBelow(const std::vector<CurrencyRate*>& data, double threshold) {
    std::vector<CurrencyRate*> result;
    for (auto* entry : data) {
        if (entry->sell < threshold) result.push_back(entry);
    }
    return result;
}
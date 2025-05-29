#include "processing.h"
#include <cmath>

double process(const std::vector<CurrencyRate*>& rates) {
    double max_diff = 0.0;

    for (const auto& r : rates) {
        double diff = std::abs(r->buy_price - r->sell_price);
        if (diff > max_diff) {
            max_diff = diff;
        }
    }

    return max_diff;
}

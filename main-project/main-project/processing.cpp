#include "processing.h"

double process(const std::vector<CurrencyRate*>& data) {
    double maxDiff = 0.0;
    for (auto* entry : data) {
        double diff = entry->sell - entry->buy;
        if (diff > maxDiff) {
            maxDiff = diff;
        }
    }
    return maxDiff;
}

#include "file_reader.h"
#include <fstream>
#include <sstream>

std::vector<CurrencyRate*> readCurrencyData(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<CurrencyRate*> data;
    std::string bank, address;
    double buy, sell;

    while (file >> bank >> buy >> sell) {
        std::getline(file >> std::ws, address);
        auto* entry = new CurrencyRate{ bank, buy, sell, address };
        data.push_back(entry);
    }
    return data;
}
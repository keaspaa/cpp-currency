#include <iostream>
#include "file_reader.h"
#include "filters.h"
#include "sorting.h"
#include "constants.h"

void printData(const std::vector<CurrencyRate*>& data) {
    for (auto* d : data)
        std::cout << d->bank << "\t" << d->buy << "\t" << d->sell << "\t" << d->address << '\n';
}

int main() {
    setlocale(LC_ALL, "ru");

    auto data = readCurrencyData("data.txt");

    std::cout << "1. Курсы валют в Беларусбанк:\n";
    auto filtered1 = filterByBank(data, TARGET_BANK);
    printData(filtered1);

    std::cout << "\n2. Курсы валют с продажей < " << SELL_THRESHOLD << ":\n";
    auto filtered2 = filterBySellBelow(data, SELL_THRESHOLD);
    printData(filtered2);

    std::cout << "\n3. Выберите метод сортировки (0 - bubble, 1 - merge): ";
    int sortMethod; std::cin >> sortMethod;
    std::cout << "Выберите критерий сортировки (0 - по разности, 1 - по банку и адресу): ";
    int cmpMethod; std::cin >> cmpMethod;

    SortFunc sortFuncs[] = { bubbleSort, mergeSort };
    CompareFunc cmpFuncs[] = { compareByDiffDesc, compareByBankAddressAsc };

    sortFuncs[sortMethod](data, cmpFuncs[cmpMethod]);

    std::cout << "\nОтсортированные данные:\n";
    printData(data);

    for (auto* d : data) delete d;
    return 0;
}

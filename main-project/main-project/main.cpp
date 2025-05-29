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

    std::cout << "1. ����� ����� � �����������:\n";
    auto filtered1 = filterByBank(data, TARGET_BANK);
    printData(filtered1);

    std::cout << "\n2. ����� ����� � �������� < " << SELL_THRESHOLD << ":\n";
    auto filtered2 = filterBySellBelow(data, SELL_THRESHOLD);
    printData(filtered2);

    std::cout << "\n3. �������� ����� ���������� (0 - bubble, 1 - merge): ";
    int sortMethod; std::cin >> sortMethod;
    std::cout << "�������� �������� ���������� (0 - �� ��������, 1 - �� ����� � ������): ";
    int cmpMethod; std::cin >> cmpMethod;

    SortFunc sortFuncs[] = { bubbleSort, mergeSort };
    CompareFunc cmpFuncs[] = { compareByDiffDesc, compareByBankAddressAsc };

    sortFuncs[sortMethod](data, cmpFuncs[cmpMethod]);

    std::cout << "\n��������������� ������:\n";
    printData(data);

    for (auto* d : data) delete d;
    return 0;
}

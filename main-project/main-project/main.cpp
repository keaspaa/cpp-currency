#include <iostream>
#include <vector>
#include "book_subscription.h"
#include "file_reader.h"
#include "sorting.h"

int main() {
    std::cout << "������� 4. ���� �����\n";
    std::cout << "���: ������ ����\n";
    std::cout << "������: 123045\n\n";

    std::vector<CurrencyInfo*> currencies;

    if (!readFile("data.txt", currencies)) {
        std::cerr << "������ ������ ����� ������.\n";
        return 1;
    }

    int choice;
    std::cout << "�������� ����������:\n1 - �� ������� ����� �������� � ��������\n2 - �� �������� �����\n> ";
    std::cin >> choice;

    if (choice == 1) mergeSort(currencies, 0, currencies.size() - 1, compareByDiff);
    else if (choice == 2) bubbleSort(currencies, compareByName);

    for (auto* cur : currencies) {
        std::cout << cur->bank << " - �������: " << cur->buy
            << ", �������: " << cur->sell
            << ", �����: " << cur->address << '\n';
    }

    for (auto* c : currencies) delete c;

    return 0;
}

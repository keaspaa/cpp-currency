#include "sorting.h"
#include <algorithm>

int compareByDiffDesc(CurrencyRate* a, CurrencyRate* b) {
    return (b->sell - b->buy) - (a->sell - a->buy);
}

int compareByBankAddressAsc(CurrencyRate* a, CurrencyRate* b) {
    if (a->bank != b->bank) return a->bank < b->bank ? -1 : 1;
    return a->address < b->address ? -1 : 1;
}

void bubbleSort(std::vector<CurrencyRate*>& data, CompareFunc cmp) {
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data.size() - i - 1; ++j) {
            if (cmp(data[j], data[j + 1]) > 0)
                std::swap(data[j], data[j + 1]);
        }
    }
}

void merge(std::vector<CurrencyRate*>& data, int l, int m, int r, CompareFunc cmp) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<CurrencyRate*> L(data.begin() + l, data.begin() + m + 1);
    std::vector<CurrencyRate*> R(data.begin() + m + 1, data.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (cmp(L[i], R[j]) <= 0)
            data[k++] = L[i++];
        else
            data[k++] = R[j++];
    }
    while (i < n1) data[k++] = L[i++];
    while (j < n2) data[k++] = R[j++];
}

void mergeSortUtil(std::vector<CurrencyRate*>& data, int l, int r, CompareFunc cmp) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortUtil(data, l, m, cmp);
        mergeSortUtil(data, m + 1, r, cmp);
        merge(data, l, m, r, cmp);
    }
}

void mergeSort(std::vector<CurrencyRate*>& data, CompareFunc cmp) {
    mergeSortUtil(data, 0, data.size() - 1, cmp);
}
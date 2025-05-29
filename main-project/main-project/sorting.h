#pragma once
#include "currency_structs.h"
#include <vector>

typedef int (*CompareFunc)(CurrencyRate*, CurrencyRate*);

typedef void (*SortFunc)(std::vector<CurrencyRate*>&, CompareFunc);

void bubbleSort(std::vector<CurrencyRate*>& data, CompareFunc cmp);
void mergeSort(std::vector<CurrencyRate*>& data, CompareFunc cmp);

int compareByDiffDesc(CurrencyRate* a, CurrencyRate* b);
int compareByBankAddressAsc(CurrencyRate* a, CurrencyRate* b);
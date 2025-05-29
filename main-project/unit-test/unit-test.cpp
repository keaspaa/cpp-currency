#include "pch.h"
#include "CppUnitTest.h"

#include "../main-project/currency_structs.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
    TEST_CLASS(unittestproject)
    {
    public:

        TEST_METHOD(TestMaxDifference)
        {
            std::vector<CurrencyRate*> rates = {
                new CurrencyRate{"USD", 85.0, 90.0, "Branch1"},  // diff = 5.0
                new CurrencyRate{"EUR", 87.0, 88.0, "Branch1"},  // diff = 1.0
                new CurrencyRate{"GBP", 70.0, 75.0, "Branch2"}   // diff = 5.0
            };

            double result = process(rates);
            Assert::AreEqual(5.0, result);

            for (auto p : rates) delete p;
        }

        TEST_METHOD(TestZeroRates)
        {
            std::vector<CurrencyRate*> rates;
            double result = process(rates);
            Assert::AreEqual(0.0, result);
        }

        TEST_METHOD(TestNegativeSpread)
        {
            std::vector<CurrencyRate*> rates = {
                new CurrencyRate{"JPY", 100.0, 98.0, "Branch1"}, // diff = 2.0
                new CurrencyRate{"CNY", 95.0, 97.0, "Branch1"}    // diff = 2.0
            };

            double result = process(rates);
            Assert::AreEqual(2.0, result);

            for (auto p : rates) delete p;
        }
    };
}

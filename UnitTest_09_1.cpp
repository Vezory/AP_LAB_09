#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

#include "var.h"
#include "dod.h"
#include "sum.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nsVar;
using namespace nsDod;
using namespace nsSum;

namespace UnitTest091
{
    TEST_CLASS(UnitTest091)
    {
    public:
        TEST_METHOD(TestMethod_Dod)
        {
            // Тестування коефіцієнта рекурентності для x = 3.0, n = 1
            // t = (3 - 1)/(3 + 1) = 0.5
            // R = (2*1 - 1)/(2*1 + 1) * 0.5^2 = (1/3) * 0.25 = 1/12
            x = 3.0;
            n = 1;
            a = 1.0;
            dod();
            Assert::AreEqual(1.0 / 12.0, a, 1e-7);
        }

        TEST_METHOD(TestMethod_Sum)
        {
            // Тестування обчислення суми ряду Тейлора для x = 2.0
            x = 2.0;
            e = 1e-5;
            sum();
            Assert::AreEqual(std::log(2.0), s, 1e-4);

            // Тестування для x = 0.5
            x = 0.5;
            e = 1e-5;
            sum();
            Assert::AreEqual(std::log(0.5), s, 1e-4);
        }
    };
}

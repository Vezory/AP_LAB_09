#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TEST
#include "Lab_09_2_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest0921
{
    TEST_CLASS(UnitTest0921)
    {
    public:
        TEST_METHOD(TestMethod_Branch1)
        {
            // w = min((x - z)^2, x - y) при z > 1
            // x = 4.0, y = 2.0, z = 2.0
            // (x - z)^2 = (4 - 2)^2 = 4
            // x - y = 4 - 2 = 2
            // min(4, 2) = 2.0
            double res = calc_branch1(4.0, 2.0, 2.0);
            Assert::AreEqual(2.0, res, 1e-5);
        }

        TEST_METHOD(TestMethod_Branch2)
        {
            // w = max(x - y, y - z) при z <= 1
            // x = 5.0, y = 3.0, z = 0.0
            // x - y = 5 - 3 = 2
            // y - z = 3 - 0 = 3
            // max(2, 3) = 3.0
            double res = calc_branch2(5.0, 3.0, 0.0);
            Assert::AreEqual(3.0, res, 1e-5);
        }

        TEST_METHOD(TestMethod_Macros)
        {
            Assert::AreEqual(9.0, SQR(3.0));
            Assert::AreEqual(10.0, MAX(7.0, 10.0));
            Assert::AreEqual(7.0, MIN(7.0, 10.0));
            Assert::AreEqual(5.0, ABS(-5.0));
        }
    };
}

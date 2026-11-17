#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;

void nsSum::sum() {
    n = 0;
    double t = (x - 1.0) / (x + 1.0);
    a = 2.0 * t;
    s = a;
    do {
        n++;
        dod();
        s += a;
    } while (std::fabs(a) >= e);
}

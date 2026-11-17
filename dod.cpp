#include "dod.h"
#include "var.h"

using namespace nsVar;

void nsDod::dod() {
    double t = (x - 1.0) / (x + 1.0);
    double R = (2.0 * n - 1.0) / (2.0 * n + 1.0) * (t * t);
    a *= R;
}

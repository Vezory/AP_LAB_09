#include <iostream>
#include <iomanip>
#include <cmath>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "e   = "; cin >> e;
    cout << endl;

    cout << fixed;
    cout << "---------------------------------------------------------" << endl;
    cout << "|" << setw(8) << "x" << " |"
         << setw(15) << "ln(x) [ряд]" << " |"
         << setw(15) << "ln(x) [cmath]" << " |"
         << setw(8) << "n" << " |" << endl;
    cout << "---------------------------------------------------------" << endl;

    x = x_p;
    while (x <= x_k) {
        sum();
        cout << "|" << setw(8) << setprecision(2) << x << " |"
             << setw(15) << setprecision(5) << s << " |"
             << setw(15) << setprecision(5) << log(x) << " |"
             << setw(8) << n << " |" << endl;
        x += dx;
    }
    cout << "---------------------------------------------------------" << endl;

    return 0;
}

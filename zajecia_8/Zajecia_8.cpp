#include <iostream>
#include "Vektor.h"
using namespace std;
double a = 2.5, scalar=0;
int main()
{
    Vector Pa("Pa", 1, 2), Pb("Pb", 3, 4), P_add, P_sub, P_mul_int, P_mul_scal;
    Vector vectors[9] = {
      Vector("P1", 0, -2),
      Vector("P2", 4, 4),
      Vector("P3", 6, 8),
      Pa,
      Pb,
      P_add = Pa + Pb, // suma wektorów Pa i Pb
      P_sub = Pa - Pb,
      P_mul_int = Pa * a
    };
    scalar = Pa / Pb;

    for (int i = 0; i < 9; i++)
    {
        vectors[i].show();
    }
    Vector().showdbl(scalar);

}

#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
    Vector vectors[9] = {
      Vector("P1", 0, -2),
      Vector("P2", 4, 4),
      Vector("P3", 6, 8)
    };

    cout << "Istnieje " << Vector::numberOfVectors() << " wektorow." << endl;

    for (int i = 0; i < 9; i++)
    {
        vectors[i].show();
    }


    {
        Vector p1, p2, p3;
        cout << endl;
        cout << "Teraz istnieje " << Vector::numberOfVectors() << " wektorow." << endl;
    }

    cout << "A teraz istnieje " << Vector::numberOfVectors() << " wektorow." << endl;

}

#include <iostream>

using namespace std;

class Ksztalt
{
public:
    virtual void wyswietl() = 0; //czysta funkcja wirtualna
};

class Deltoid :public Ksztalt
{
    float d1, d2;
public:
    Deltoid(float x, float y)
    {
        d1 = x;
        d2 = y;
    }
    virtual void wyswietl()
    {
        cout << "Deltoid"<< endl
            << "dlugoœæ pierwsza d: " << d1 << endl
            << "dlugoœæ druga d: " << d2 << endl
            << "Pole deltoidu: " << d1 * d2 / 2 << endl << endl;
    }
};
class Trojkat :public Ksztalt
{
    float a, h;
public:
    Trojkat(float x, float y)
    {
        a = x;
        h = y;
    }

    virtual void wyswietl()
    {
        cout << "Trojkat" << endl
            << "podstawa trojkata: " << a << endl
            << "wysokoœæ trojkata: " << h << endl
            << "Pole trojkata: " << a * h / 2 << endl << endl;
    }
};
class Prostokat :public Ksztalt
{
    float a, b;
public:
    Prostokat(float x, float y)
    {
        a = x;
        b = y;
    }
    virtual void wyswietl()
    {
        cout << "Prostokat" << endl
            << "dlugoœæ pierwszego boku prostokata: " << a << endl
            << "dlugoœæ  drugiego boku prostokata " << b << endl
            << "Pole prostokata: " << a * b << endl << endl;
    }
};
void dzialania(Ksztalt* x)
{
    x->wyswietl();
}
int main()
{
    Deltoid d(41, 25);
    Trojkat t(3, 7);
    Prostokat p(14, 12);
    Ksztalt* wsk;

    wsk = &d;
    dzialania(wsk);
    wsk = &t;
    dzialania(wsk);
    wsk = &p;
    dzialania(wsk);
    return 0;
}
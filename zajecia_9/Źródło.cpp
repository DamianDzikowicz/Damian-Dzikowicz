#include <iostream>

using namespace std;

class Figura
{
public:
    virtual void wyswietl() = 0;
};

class Deltoid :public Figura
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
        cout << "dl 1 d: " << d1 << endl
            << "dl 2 d: " << d2 << endl
            << "P deltoidu: " << d1 * d2 / 2 << endl << endl;
    }
};
class Trojkat :public Figura
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
        cout << "dl pod trojkata: " << a << endl
            << "wys trojkata: " << h << endl
            << "P trojkata: " << a * h / 2 << endl << endl;
    }
};
class Prostokat :public Figura
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
        cout << "dl 1 boku prostokata: " << a << endl
            << "dl  2 boku prostokata " << b << endl
            << "P prostokata: " << a * b << endl << endl;
    }
};
void dzialania(Figura* x)
{
    x->wyswietl();
}
int main()
{
    Deltoid d(12, 5);
    Trojkat t(6, 9);
    Prostokat p(19, 3);
    Figura* wsk;

    wsk = &d;
    dzialania(wsk);
    wsk = &t;
    dzialania(wsk);
    wsk = &p;
    dzialania(wsk);
    return 0;
}
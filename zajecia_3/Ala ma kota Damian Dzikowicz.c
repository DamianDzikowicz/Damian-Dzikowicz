#include <stdio.h>

void male_litery(char* ciag)
{
    while (*ciag)
    {
        if ('A' <= *ciag && *ciag <= 'Z')
        {
            *ciag += ('a' - 'A');
        }
        ciag++;
    }
}



void wielkie_litery(char* ciag)
{
    while (*ciag)
    {
        if ('a' <= *ciag && *ciag <= 'z')
        {
            *ciag -= ('a' - 'A');
        }
        ciag++;
    }
}



int dlugosc(const char* ciag)
{
    int  i = 0;
    while (ciag[i])
    {
        i++;
    }
    return i;
}



int sprawdz_czy_identyczne(const char* s1, const char* s2)
{
    if (dlugosc(s1) != dlugosc(s2))
    {
        return 0;
    }


    int i = 0;
    while (s1[i])
    {
        if (s1[i] != s2[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}


int polacz(char* s1, char* s2, char* wynik, int suma)
{
    if (dlugosc(s1) + dlugosc(s2) > suma)
    {
        return -1;
    }
    while (*s1)
    {
        *wynik += *s1;
        s1++;
        wynik++;
    }



    while (*s2)
    {
        *wynik += *s2;
        s2++;
        wynik++;
    }
    return 0;
}



int main(int argc, char const argv[]) {
    char tekst[80] = "ALA ma kota.";
    char napis1[80] = "";
    int dlugosc_napisu = 0;
    char napis2[80] = "";
    char wynik[80] = "";
    int suma = 80;

    printf("Wprowadz tekst\n");
    gets(napis1);
    dlugosc_napisu = dlugosc(napis1);

    printf("%s \n", napis1);
    printf("dlugosc wprowadzonego tekstu %d\n", dlugosc(napis1));
    printf("dlugosc wprowadzonego tekstu %d\n", dlugosc_napisu);

    printf("sprawdzam czy identyczne %d\n", sprawdz_czy_identyczne(tekst, napis1));
    printf("polaczone : %s \n", polacz(napis2, tekst, wynik, suma) == -1 ? "tekst jest za dlugi" : wynik);

    male_litery(napis1);
    printf("%s \n", napis1);
    wielkie_litery(napis1);
    printf("%s \n", napis1);

    return 0;
}
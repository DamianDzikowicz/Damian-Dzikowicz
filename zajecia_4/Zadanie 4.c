#include<stdio.h>

void usage(const char* nazwa_programu)
{
	printf("Sposob uzycia: %s <liczba> <dzia³anie> <liczba_2>\n", nazwa_programu);
	exit(1);
}

int identyczne_teksty(const char* tekst, const char* tekst_2)
{
	while (*tekst != '\0' && *tekst_2 != '\0')
	{
		if (*tekst != *tekst_2)
		{
			return  0;
		}

		tekst++;
		tekst_2++;
	}
	return 1;
}

int main(int argc, int const* argv[])
{
	int liczba_1 =0;
	int liczba_2 =0;
	int wynik =0;
	int kod_bledu = 0;

	if (argc < 4)
		usage(argv[0]);

	liczba_1 = atoi(argv[1]);
	liczba_2 = atoi(argv[3]);

	printf("Liczba_1 %d \n", liczba_1);
	printf("Liczba_2 %d \n", liczba_2);
	printf("Dzialanie %s \n", argv[2]);

	if (identyczne_teksty(argv[2], "add"))
	{
		printf("Dodawanie\n");
		wynik = liczba_1 + liczba_2;
	}

	if (identyczne_teksty(argv[2], "div"))
	{
		printf("Dzielenie\n");
		if (liczba_2 == 0)
		{
			kod_bledu = 1;
		}
		else
		{
			wynik = liczba_1 / liczba_2;
		}
	}

	if (identyczne_teksty(argv[2], "sub"))
	{
		printf("Odejmowanie\n");
		wynik = liczba_1 - liczba_2;
	}

	if (identyczne_teksty(argv[2], "mul"))
	{
		printf("Mno¿enie\n");
		wynik = liczba_1 * liczba_2;
	}

	switch (kod_bledu)
	{
	case 0:
		printf("Wynik dzia³ania %d \n", wynik);
		break;

	case 1:
		printf("Nie dzielimy przez 0\n");
		break;

	default:
		printf("B³¹d\n");
		break;
	}


	return 0;

}
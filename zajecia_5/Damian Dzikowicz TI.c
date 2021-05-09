#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include <time.h>
FILE* fptr;
void usage(const char* nazwa_programu)
{
	printf("Sposob uzycia: %s<liczba> <dzialanie> <liczba2>\n dzialania\n add dodawanie\n sub odejmowanie\n mul mnozenie\ndivision dzielenie", nazwa_programu);
	exit(1);
};
double add(const double liczba, const double liczba2)
{
	return liczba + liczba2;
}
double sub(const double liczba, const double liczba2)
{
	return liczba - liczba2;
}
double mul(const double liczba, const double liczba2)
{
	return liczba * liczba2;
}
double division(const double liczba, const double liczba2)
{
	return liczba2 != 0 ? liczba / liczba2 : 0;
}
void log(double cyfra, double cyfra2, const char* jakaoperacja, double rezultat, errno_t kod_bledu)
{
	struct _timeb timebuffer;
	char timeline[26];
	errno_t err;
	_ftime64_s(&timebuffer);
	err = ctime_s(timeline, 26, &(timebuffer.time));
	if (err)
	{
		printf("Invalid argument to ctime_s. ");
	}
	fprintf(fptr, "\n data: %.19s.%hu %s", timeline, timebuffer.millitm,
		&timeline[20]);
	fprintf(fptr, "liczba %lf\n", cyfra);
	fprintf(fptr, "liczba2 %lf\n", cyfra2);
	fprintf(fptr, "typoperacji %s\n", jakaoperacja);
	fprintf(fptr, "wynik %lf\n", rezultat);
	fprintf(fptr, "kod bledu %d\n\n\n", kod_bledu);
}
int main(int argc, const char* argv[])
{
	if (argc < 4)
	{
		usage(argv[0]);
		return 0;
	}
	const char* typoperacji = (*(argv + 2));
	double  liczba = atof(argv[1]);
	double liczba2 = atof(argv[3]);
	double result = 0;
	errno_t kodbledu;
	//otwieram plik
	kodbledu = fopen_s(&fptr, "log.txt", "a");
	if (kodbledu == 0) printf("plik zostal otwary \n");
	else {
		printf("nie udalo sie otworzyc pliku\n");
		exit(1);
	}
	if (strcmp(typoperacji, "add") == 0)
	{
		result = add(liczba, liczba2);
		printf("\n %lf +%lf = %lf", liczba, liczba2, result);
	}
	else if (strcmp(typoperacji, "sub") == 0)
	{
		result = sub(liczba, liczba2);
		printf("\n %lf -%lf = %lf", liczba, liczba2, result);
	}
	else if (strcmp(typoperacji, "mul") == 0)
	{
		result = mul(liczba, liczba2);
		printf("\n %lf *%lf = %lf", liczba, liczba2, result);
	}
	else if (strcmp(typoperacji, "division") == 0)
	{
		if (liczba == 0 || liczba2 == 0)
		{
			printf("\n nie dzial przez 0");
			return 0;
		}
		result = division(liczba, liczba2);
		printf("\n %lf /%lf = %lf", liczba, liczba2, result);
	}
	else
	{
		printf("\n wystapil nieznany blad\n");
	}
	log(liczba, liczba2, typoperacji, result, kodbledu);
	// zamykam plik
	int zamykanie = _fcloseall();
	printf("\n plik zostal zamkniety: %u\n", zamykanie);
	system("pause");
	return 0;
}
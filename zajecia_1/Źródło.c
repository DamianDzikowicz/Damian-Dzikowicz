#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
int x;

int main() {
    bool on = true;
    printf("Dodawanie zawartosci do tablicy 10 elementowej\n\n");
    float tablicaDane[10] = { 0 };

    for (int i = 0; i <= 9; i++) {
        printf("\nProsze wpisac liczbe dla%d komorki:\t", (i + 1));
        scanf_s("%f", &tablicaDane[i]);
    }

    printf("\nKoniec wprowadzania wartosci danych.\n\n");
    while (on) {

        printf("Co dalej? \n1 - Wysmietl maksymalny element \n2 - Wysmietl minimalny element \n3 - Wejscie z programu \n4 ");
        int  akcja = 0;
        scanf_s("%d", &akcja);
        printf("\ n \ n \ n");

        switch (akcja)
        {
        case(1):

            x = 0;
            float max = tablicaDane[0];
            for (int i = 1; i <= 9; i++) {
                if (tablicaDane[i] > max) {
                    max = tablicaDane[i];
                    x = i;
                }
            }
            printf("Maksymalny element zbioru wynosi: %f\n", tablicaDane[x]);
            break;

        case(2):
            x = 0;
            float min = tablicaDane[0];
            for (int i = 1; i <= 9; i++) {
                if (tablicaDane[i] < min) {
                    min = tablicaDane[i];
                    x = i;
                }
            }
            printf("Minimalny element zbioru wynosi: %f\n", tablicaDane[x]);
            break;

        case(3):
            on = false;
            printf("Zapraszamy ponownie\n");
            break;

        default:
            printf("Podano niewlasciwa liczbe, prosze sprobowac ponownie\n");
            break;
        }

        printf("\n\n");




    }
}
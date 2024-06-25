#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE, "Polish");

    // input nr 1 - czestotliwosc kapitalizacji
    int kapitalizacja;
    printf("Podaj czestotliwosc kapitalizacji w miesiacach... ");
    scanf("%i", &kapitalizacja);
    printf("\n\n");

    // czyszczenie bufferu inputu
    while((getchar()) != '\n');


    // input nr 2 - oprocentowanie lokaty
    float oprocentowanie;
    printf("Podaj oprocentowanie lokaty... ");
    scanf("%f", &oprocentowanie);
    printf("\n\n");

    while((getchar()) != '\n');


    // input nr 3 - wysokosc srodkow poczatkowych
    float srodki;
    printf("Podaj wysokosc twoich srodkow wloznych na lokate... ");
    scanf("%f", &srodki);
    printf("\n\n");

    while((getchar()) != '\n');


    // input nr 4 - jednostka czasu lokaty
    char jednostka;
    printf("Podaj jednostke okresu lokaty (m - miesiace, l - lata)... ");
    scanf("%c", &jednostka);

    // sprawdzanie poprawnoœci podanej jednostki
    if (jednostka == 'm' || jednostka == 'l'){
        printf("\nPodano prawidlowa jednostke");
    }else{
        printf("\nPodales zla jednostke.");
        return -1; // returnuje errora
    }
    printf("\n\n");

    while((getchar()) != '\n');


    // input 5 - czasookres lokaty
    int okres;
    printf("Podaj okres lokaty w podanej wczesniej jednostce... ");
    scanf("%i", &okres);
    printf("\n\n");

    // printf("%c", jednostka);


    int okres_w_miesiacach;
    if (jednostka == 'm'){
        okres_w_miesiacach = okres;
    }else{
        okres_w_miesiacach = okres * 12;
    }

    // szczegó³y podanych danych
    printf("\nPodana czestotliwosc kapitalizacji w miesiacach: %i", kapitalizacja);
    printf("\nPodane oprocentowanie lokaty: %f", oprocentowanie);
    printf("\nPodana wysokosc srodków na lokacie: %f", srodki);
    printf("\nPodana jednostka czasu: %c", jednostka);
    printf("\nPodany okres: %i", okres);
    printf(" // To w miesiacach: %i", okres_w_miesiacach);


    float koncowe_srodki = srodki;
    // oblicza oprocentowanie przy kazdej kapitalizacji - nie tak jak przy podawaniu (roczne)
    float oprocentowanie_przy_kapitalizacji = oprocentowanie / (12.0 / kapitalizacja);


    float wysokosc_odsetek_po_kapitalizacji;
    float kwota_podatku_po_kapitalizacji;
    float koncowe_srodki_minus_podatek_po_kapitalizacji;
    for (int i=1; i<=okres_w_miesiacach; i++){
        printf("\nMiesiac: %i", i);
        if (i % kapitalizacja == 0){
            koncowe_srodki = koncowe_srodki * (1+oprocentowanie_przy_kapitalizacji/100);

            wysokosc_odsetek_po_kapitalizacji = koncowe_srodki - srodki;
            kwota_podatku_po_kapitalizacji = wysokosc_odsetek_po_kapitalizacji * 0.19;
            koncowe_srodki_minus_podatek_po_kapitalizacji = koncowe_srodki - kwota_podatku_po_kapitalizacji;

            printf("\nKapitalizacja, srodkow po kapitalizacji: %.2f", koncowe_srodki);
            printf("\nOdsetki po kapitalizacji: %.2f", wysokosc_odsetek_po_kapitalizacji);
            printf("\nKwota podatku od odsetek po kapitalizacji: %.2f", kwota_podatku_po_kapitalizacji);
            printf("\nKapital po kapitalizacji pomniejszony o podatek: %.2f", koncowe_srodki_minus_podatek_po_kapitalizacji);
        }
    }

    float wysokosc_odsetek = koncowe_srodki - srodki;
    float kwota_podatku = wysokosc_odsetek * 0.19;
    float koncowe_srodki_minus_podatek = koncowe_srodki - kwota_podatku;
    printf("\n\n\n------------------------------------------------------");
    printf("\nCalkowity kapital koncowy: %.2f", koncowe_srodki);
    printf("\nOdsetki lokaty wyniosly w sumie: %.2f", wysokosc_odsetek);
    printf("\nKwota podatku od zysku z lokaty: %.2f", kwota_podatku);
    printf("\nW sumie kapital koncowy pomniejszony o podatek: %.2f", koncowe_srodki_minus_podatek);
    printf("\n\n\n");
    return 0;
}

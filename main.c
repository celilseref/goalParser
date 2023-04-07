#include <stdio.h>
#include <string.h>
#include <locale.h> //setlocale fonksiyonu için ekledik.

int main() {
	setlocale(LC_ALL, "Turkish");//türkçe karakter kullanýmý için ekledim.
	printf("Gol Yorumlayýcýsý: String komutlarýný yorumlayabilen bir Gol Parser'a sahibiz komut olarak girdiðimiz G,(),(l) stringlerini alarak orjinal sýrayla Gol yazdýrýr.\n");
    char komut[100];  // Kullanýcýnýn girdiði string komutunu saklamak için bir karakter dizisi oluþturuyoruz.
    char cikti[100];   // Sonuç stringini saklamak için bir karakter dizisi oluþturuyoruz.
    int i, j = 0;
    printf("Komut giriniz: ");
    scanf("%s", komut);  // Kullanýcýdan string komutunu alýyoruz.

    for (i = 0; i < strlen(komut); i++) {  // String komutunu tarayarak her bir karakteri deðerlendiriyoruz.
        if (komut[i] == 'G') {             // Eðer karakter "G" ise, "G" stringini sonuç stringine ekliyoruz.
            cikti[j++] = 'G';
        }
        else if (komut[i] == '(' && komut[i+1] == ')') {  // Eðer karakterler "()" ise, "o" stringini sonuç stringine ekliyoruz.
            cikti[j++] = 'o';
            i++;  // "()" karakterlerinin ikisini bir arada ele almak için i'yi bir artýrýyoruz.
        }
        else if (komut[i] == '(' && komut[i+1] == 'l' && komut[i+2] == ')') {  // Eðer karakterler "(l)" ise, "l" stringini sonuç stringine ekliyoruz.
            cikti[j++] = 'l';
            i += 2;  // "(l)" karakterlerinin üçünü bir arada ele almak için i'yi iki artýrýyoruz.
        }
    }
    cikti[j] = '\0';  // Sonuç stringini sonlandýrmak için null karakteri ekliyoruz.

    printf("Konsol Çýktýsý: %s\n", cikti);  // Sonuç stringini ekrana yazdýrýyoruz.
    return 0;
}


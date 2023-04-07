#include <stdio.h>
#include <string.h>
#include <locale.h> //setlocale fonksiyonu i�in ekledik.

int main() {
	setlocale(LC_ALL, "Turkish");//t�rk�e karakter kullan�m� i�in ekledim.
	printf("Gol Yorumlay�c�s�: String komutlar�n� yorumlayabilen bir Gol Parser'a sahibiz komut olarak girdi�imiz G,(),(l) stringlerini alarak orjinal s�rayla Gol yazd�r�r.\n");
    char komut[100];  // Kullan�c�n�n girdi�i string komutunu saklamak i�in bir karakter dizisi olu�turuyoruz.
    char cikti[100];   // Sonu� stringini saklamak i�in bir karakter dizisi olu�turuyoruz.
    int i, j = 0;
    printf("Komut giriniz: ");
    scanf("%s", komut);  // Kullan�c�dan string komutunu al�yoruz.

    for (i = 0; i < strlen(komut); i++) {  // String komutunu tarayarak her bir karakteri de�erlendiriyoruz.
        if (komut[i] == 'G') {             // E�er karakter "G" ise, "G" stringini sonu� stringine ekliyoruz.
            cikti[j++] = 'G';
        }
        else if (komut[i] == '(' && komut[i+1] == ')') {  // E�er karakterler "()" ise, "o" stringini sonu� stringine ekliyoruz.
            cikti[j++] = 'o';
            i++;  // "()" karakterlerinin ikisini bir arada ele almak i�in i'yi bir art�r�yoruz.
        }
        else if (komut[i] == '(' && komut[i+1] == 'l' && komut[i+2] == ')') {  // E�er karakterler "(l)" ise, "l" stringini sonu� stringine ekliyoruz.
            cikti[j++] = 'l';
            i += 2;  // "(l)" karakterlerinin ���n� bir arada ele almak i�in i'yi iki art�r�yoruz.
        }
    }
    cikti[j] = '\0';  // Sonu� stringini sonland�rmak i�in null karakteri ekliyoruz.

    printf("Konsol ��kt�s�: %s\n", cikti);  // Sonu� stringini ekrana yazd�r�yoruz.
    return 0;
}


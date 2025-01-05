#include <stdio.h>
int baslangic() {
    int islem;

    printf("kutuphane sistemi\n");
    printf("1. yeni kullanici kaydi \n");
    printf("2. kitap teslim alimi \n");
    printf("3. kitap teslimi \n");
    printf("4. cikis \n");
    printf("\nSeciminizi yapin: ");
    scanf("%d", &islem);
    return islem;
}

int main(void) {
    int islem = 0;
    char isim[50];
    char soyisim[50];
    long int tc[50];
    char verilen[50];
    char alinan[50];
    char kitap[300];
    char yildiz[50]= "****************************************";
    int sayac=0;

    while (islem != 4) { //4i secerse döngu bitsin diye yaptik
        int islem;
        islem= baslangic(); //üstte fonksiyonu ayzdik
        while (getchar() != '\n'); // \n sikinti cikartiyor o yuzden böyle bi kod ile \n den sonra yazilan karakteri okumasini sasliyoruz
        switch (islem) {
            case 1:
                printf("yeni kullanici kaydini sectiniz \n\n");
                printf("lutfen isminizi giriniz \n");
                scanf("%s", isim);
                printf("lutfen soyisminizi giriniz \n");
                scanf("%s", soyisim);
                printf("lutfen tc giriniz \n");
                scanf("%ld", &tc);
                if (tc==00000000000) {
                    printf("yonetici girisi yaptiniz!\n");
                }
                    else {
                        FILE *dosya = fopen("deneme.txt", "a");
                        if(dosya == NULL) {
                            printf("dosya acilamadi\n");
                            return 1;
                        }
                        fprintf(dosya,"%s\n",isim);
                        fprintf(dosya,"%s\n",soyisim);
                        fprintf(dosya,"%ld\n",tc);
                        fprintf(dosya,"%s\n",yildiz);
                        fclose(dosya);
                        printf("basariyla kaydedildi\n\n");
                    }
                    break;

            case 2:
                printf("\nkitap teslim alimini sectiniz \n");
                printf("kutuphanemizde bulunan kitaplar: \n");
                FILE *dosya2 = fopen("kitaplar.txt", "r");
            if(dosya2 == NULL) {
                printf("dosya acilamadi \n");
            }
                while (fgets(kitap,sizeof(kitap),dosya2) !=NULL) { //dosya bos kalana kadar hepsini okuyor
                    printf("%s\n",kitap);
                }
                fclose(dosya2);
                printf("\nlutfen istediginiz kitabi yaziniz \n");
                scanf("%49s", verilen);
                printf("%s adiniza kaydedilmistir \n\n",verilen);
                sayac++;
                break; //kitaplari kontrol edicem yoksa hata mesaji !

            case 3:
                printf("kitap teslimini sectiniz \n");
                printf("lutfen birakmak istediginiz kitabi yaziniz \n");
                scanf("%s", &alinan);
                FILE *dosya3 = fopen("kitaplar.txt", "a");
                if(dosya3 == NULL) {
                    printf("dosya acilamadi \n");
                    return 1;
            }
                fprintf(dosya3,"%s\n",alinan);
                fclose(dosya3);
                printf("basariyla birakildi \n\n");
                sayac++;
                break;
            case 4:
                printf("cikis yapiliyor");
            printf("\n %d adet giris yapildi",sayac);
            break;
            default:
                printf("gecersiz islem\n\n");
        }
    }


    return 0;
}
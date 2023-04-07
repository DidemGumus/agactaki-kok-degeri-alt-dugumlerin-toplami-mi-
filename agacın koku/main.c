//
//  main.c
//  agacın koku
//
//  Created by Didem Gümüş on 7.04.2023.
//

#include <stdio.h>//kütüphaneler atanır
#include <stdlib.h>

    struct Dugum {// ağaç düğümünün yapısı tanımlanır
    int deger;
    struct Dugum* sol;//sol alt düğüm tanımlanır
    struct Dugum* sag;//sağ alt düğüm tanımlanır
    };

     // Yeni bir düğüm oluşturmak için yardımcı bir fonksiyon atanır
    struct Dugum* dugumler(int deger)
    {
    struct Dugum* dugum = (struct Dugum*)malloc(sizeof(struct Dugum));// Bellekte yeni bir Dugum nesnesi  oluşturuluyor
    dugum->deger = deger; //düğümün deger özelliği, fonksiyona parametre olarak verilen değere eşitleniyor
    dugum->sol = NULL;// sol düğüm özelliği NULL (hükümsüz)olarak atanıyor.
    dugum->sag = NULL;// sağ düğüm özelliği NULL olarak atanıyor.
    return dugum;// oluşturulan düğümün adresi,çağrıldığı yere geri döner.
    }

    int altdt(struct Dugum* kok)// Verilen ağacın alt düğümlerinin toplamı hesaplanır
    {
    if (kok == NULL) {// kök, NULL ise alt düğüm yoktur ve toplam 0'dır
        return 0;
    }
    int toplam = 0;
    if (kok->sol != NULL) {// sol alt düğüm mevcutsa, değeri toplama eklenir
        toplam += kok->sol->deger;
    }
    if (kok->sag != NULL) {// sağ alt düğüm mevcutsa, değeri toplama eklenir
        toplam += kok->sag->deger;
    }
    return toplam; // toplam değeri geri döndürülür
    
    }

    int main(){
    
    printf("*****************   AGACTAKI KOK DEGERİ ALT DUGUMLERİN TOPLAMI MI ?   ***************\n\n");
    
    // Bu kodla 3 dügümden oluşan ikili bir ağacın kökü verildiğinde bu değerin alt düğümlerin (child) toplamı olup olmadığını buluruz
    
    
    int kd,solad,sagad;//değişkenler atadık.kd=kök değeri,solad= sol alt düğüm,sagad= sağ alt düğüm
    printf("Lutfen 1.kok degerini giriniz: ");//kullanıcıdan kök değeri istenir
    scanf("%d", &kd);
    printf("Lutfen sol alt dugum  degerini giriniz: ");//kullanıcıdan sol alt düğüm  değeri istenir
    scanf("%d", &solad);
    printf("Lutfen sag alt dugum degerini giriniz: ");//kullanıcıdan sağ alt düğüm değeri istenir
    scanf("%d", &sagad);
    
    // 3 düğümden oluşan ikili ağacı oluşturuyoruz
    struct Dugum* kok = dugumler(kd);
    kok->sol = dugumler(solad);
    kok->sag = dugumler(sagad);
        
    // Kök düğümün alt düğümlerinin toplamını hesaplar
    int altdugumtoplam = altdt(kok);
        
    // Kök düğümün değerini yazdırır
    printf("\nAgacın kök degeri: %d\n", kok->deger);
        
    // Kök düğümün alt düğümlerinin toplamını yazdırıyoruz
    printf("Kok dugumun alt dugum toplami: %d\n\n", altdugumtoplam);
    printf("********************************************************\n\n");
        
        // Kök düğümün alt düğümlerinin toplamının kendisi ile aynı olup olmadığını kontrol ediyoruz
        if (kok->deger == altdugumtoplam) {//eğer aynıysa
            printf("CEVAP: Evet,Kok dugumun alt dugumleri toplami kok degerine esittir.\n");
        }
        else {// aynı değilse
            printf("CEVAP: Hayir,Kok dugumun alt dugumleri toplami kok degerine esit degildir.\n");
        }
        
        return 0;
    }

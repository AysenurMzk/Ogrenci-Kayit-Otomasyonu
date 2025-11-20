
#include <stdio.h>
#include <stdlib.h>

/// OGRENCİ İSLERİ OTOMASYONU

struct ogrenci
{
    int numara;
    char ad[10];
    char soyad[10];
    float vize, finall;

    struct ogrenci *next;

};
typedef struct ogrenci notal;
notal *ilk, *yeninotal, *gecit, *enbasarili;


void studenList()
{
    int n, k;

    printf("Kac ogrenci gireceksiniz?: ");
    scanf("%d", &n);

    for(k=0; k<n; k++)
    {
        if(k==0)
        {
            yeninotal= (notal *)malloc(sizeof(notal));
            ilk = yeninotal;
        }
        else
        {
            yeninotal->next = (notal *)malloc(n*sizeof(notal));
            yeninotal = yeninotal->next;
        }
        printf("------BILGILERINIZI GIRINIZ------\n");
        printf("Ogrenci No: ");
        scanf("%d", &yeninotal->numara);
        printf("Ogrenci Adi: ");
        scanf("%s", yeninotal->ad);
        printf("Ogrenci Soyadi: ");
        scanf("%s", yeninotal->soyad);
        printf("Ogrenci Vize Notu: ");
        scanf("%f", &yeninotal->vize);
        printf("Ogrenci Final Notu: ");
        scanf("%f", &yeninotal->finall);
    }
    yeninotal->next = NULL;
}

void ogrenciListele(void)
{
    double donemNotu=0;
    notal *p;
    p = ilk;
    while(p!=NULL)
    {
        printf("******ALINAN BILGILER******\n");
        printf("Ogrenci No: %d\n", p->numara);
        printf("Ogrenci Adi: %s\n", p->ad);
        printf("Ogrenci Soyadi: %s\n", p->soyad);
        printf("Ogrenci Vize Notu: %f\n", p->vize);
        printf("Ogrenci Final Notu: %f\n", p->finall);
        donemNotu = p->vize*0.4+p->finall*0.6;
        printf("Donem Notu: %.2f\t\n", donemNotu);

        p = p->next;
    }
}

void ogrenciEkle()
{
    notal*yeninotal;

    yeninotal = malloc(sizeof(notal));
    if (yeninotal == NULL)
    {
        printf("bellek ayrilamadi\n");
        return;
    }

    printf("Ogrenci Adi: ");
    scanf("%s", yeninotal->ad);
    printf("Ogrenci Soyadi: ");
    scanf("%s", yeninotal->soyad);
    printf("Ogrenci No: ");
    scanf("%d", &yeninotal->numara);
    printf("Ogrenci Vize Notu: ");
    scanf("%f", &yeninotal->vize);
    printf("Ogrenci Final Notu: ");
    scanf("%f", &yeninotal->finall);

    yeninotal->next = ilk;
    ilk = yeninotal;
}








void ogrenciSil()
{
    int kayitNo;
    notal *p, *q;

    printf("Silmek istediginiz ogrencinin numarasini giriniz: ");
    scanf("%d", &kayitNo);

    p = ilk;
    if(p->numara == kayitNo)
    {
        ilk = p->next;
        free(p);
    }
    else
    {
        while(p->next != NULL)
        {
            if(p->numara == kayitNo)
                break;
            else
            {
                q=p;
                p=p->next;
            }
        }
        if(p->numara == kayitNo)
        {
            q->next = p->next;
            free(p);
        }
        else if(p->next == NULL)
        {
            printf("Silinecek ogrenci no yok!\n");
        }
    }
}

double basariNotuHesapla(int vize, int finall)
{
    return (0.4*vize)+(0.6*finall);
}

void enBasariliOgrenci()
{
    double basariNotu = 0;

    notal *p;
    p = ilk;
    enbasarili = ilk;

    while(p->next!=NULL)
    {
        p=p->next;
        if(basariNotuHesapla(p->vize,p->finall)>basariNotuHesapla(enbasarili->vize,enbasarili->finall))
            enbasarili=p;
    }
    printf("En basarili ogrenci:\n");
    printf("No: %d - Ad: %s Basari Notu: %.2f\n", enbasarili->numara, enbasarili->ad, basariNotuHesapla(enbasarili->vize,enbasarili->finall));
}

void sinifBasariOrtalamasi()
{
    double basariNotuOrtalamasi=0;
    double toplam=0;
    int sayac=0;
    notal *p;
    p = ilk;
    if(p == NULL)
    {
        printf("Listede kayit yok!");
    }
    else
    {
        do
        {
            toplam += basariNotuHesapla(p->vize, p->finall);
            p=p->next;
            sayac++;
        }
        while(p!=NULL);

        basariNotuOrtalamasi = toplam/sayac;
        printf("Basari Notu Ortalamasi: %.2f\n", basariNotuOrtalamasi);
    }
}
void ogrenciGuncelle()
{
    int numara1;
    notal *p;
    p = ilk;

    printf("Ogrencinin numarasini giriniz");
    scanf("%d",&numara1);
    if(p->numara == numara1)
    {
        printf("Yeni Ogrenci No: ");
        scanf("%d", &p->numara);
        printf("Yeni Ogrenci Adi: ");
        scanf("%s", p->ad);
        printf("Yeni Ogrenci Soyadi: ");
        scanf("%s", p->soyad);
        printf("Yeni Ogrenci Vize Notu: ");
        scanf("%f", &p->vize);
        printf("Yeni Ogrenci Final Notu: ");
        scanf("%f", &p->finall);


    }
    else
    {


        printf("Kayıtli ogrenci bulunamadi");
    }
}
void listRegisteredStudents()
{
    notal *t;
    t = ilk;
    while (t != NULL)
    {
        printf("Student Number: %d\n", t->numara);
        printf("Student Name: %s\n", t->ad);
        printf("Student Surname: %s\n", t->soyad);
        printf("Student Midterm Grade: %f\n", t->vize);
        printf("Student Final Grade: %f\n", t->finall);
        t = t->next;
    }
}


int main(void)
{
    int secim=0;
    printf("1-Liste Olustur\n");
    printf("2-Yeni Kayit Ekle\n");
    printf("3-Kayit Sil\n");
    printf("4-En Yuksek Basari Notu\n");
    printf("5-Sinif Ortalamasi\n");
    printf("6-Ogrenci Guncelle\n");
    printf("7-Kayitli Ogrencileri Goster\n");
    printf("0-CIKIS\n");
    while(1)
    {
        printf("Secim yap [1-8]?\n");
        scanf("%d", &secim);
        switch(secim)
        {
        case 1:
            studenList();
            ogrenciListele();
            break;
        case 2:
            ogrenciEkle();
            ogrenciListele();
            break;
        case 3:
            ogrenciSil();
            ogrenciListele();
            break;
        case 4:
            enBasariliOgrenci();
            break;
        case 5:
            sinifBasariOrtalamasi();
            break;
        case 6:
            ogrenciGuncelle();
            break;
        case 7:
            listRegisteredStudents();
            break;
        case 0:
            exit(0);
        }
    }
}


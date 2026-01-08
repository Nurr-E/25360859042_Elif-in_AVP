#include <stdio.h>
#include <math.h>
#include <string.h>

/* * Proje: Uzay Simülasyonu
 * Ders: Algoritmalar ve Programlama
 * Açıklama: Gezegenlerde fizik deneyleri simülasyonu.
 */

#define PI 3.14159265358979323846

// Gezegen İsimleri
const char *GEZEGENLER[] = {
    "Merkur", "Venus", "Dunya", "Mars", 
    "Jupiter", "Saturn", "Uranus", "Neptun"
};

// Fonksiyon Prototipleri
void serbest_dusme(double *g_ptr);
void yukari_atis(double *g_ptr);
void agirlik_deneyi(double *g_ptr);
void potansiyel_enerji(double *g_ptr);
void hidrostatik_basinc(double *g_ptr);
void arsimet_kaldirma(double *g_ptr);
void sarka_periyodu(double *g_ptr);
void ip_gerilmesi(double *g_ptr);
void asansor_deneyi(double *g_ptr);
void menu_goster();

int main() {

    char bilim_insani[100];
    printf("--- UZAY SIMULASYONUNA HOS GELDINIZ ---\n");
    printf("Lutfen Bilim Insani Adini ve Soyadini Giriniz: ");
    fgets(bilim_insani, sizeof(bilim_insani), stdin);




    // Merkür, Venüs, Dünya, Mars, Jüpiter, Satürn, Uranüs, Neptün
    double g_values[] = {3.7, 8.87, 9.807, 3.71, 24.79, 10.44, 8.69, 11.15};
    double *g_ptr = g_values; 

    int secim = 0;

    while (secim != -1) {
        printf("\n==========================================\n");
        printf("Bilim Insani: %s\n", bilim_insani);
        menu_goster();
        printf("Seciminiz (Cikis icin -1): ");
        scanf("%d", &secim);
        switch (secim) {
            case 1: serbest_dusme(g_ptr); break;
            case 2: yukari_atis(g_ptr); break;
            case 3: agirlik_deneyi(g_ptr); break;
            case 4: potansiyel_enerji(g_ptr); break;
            case 5: hidrostatik_basinc(g_ptr); break;
            case 6: arsimet_kaldirma(g_ptr); break;
            case 7: sarka_periyodu(g_ptr); break;
            case 8: ip_gerilmesi(g_ptr); break;
            case 9: asansor_deneyi(g_ptr); break;
            case -1: 
                printf("Simulasyon sonlandiriliyor... Iyi calismalar %s.\n", bilim_insani);
                break;
            default:
                printf("Gecersiz secim! Lutfen tekrar deneyiniz.\n");
        }
    }

    return 0;
}

void menu_goster() {
    printf("------------------------------------------\n");
    printf("1. Serbest Dusme Deneyi\n");
    printf("2. Yukari Atis Deneyi\n");
    printf("3. Agirlik Deneyi\n");
    printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
    printf("5. Hidrostatik Basinc Deneyi\n");
    printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
    printf("7. Basit Sarkac Periyodu Deneyi\n");
    printf("8. Sabit Ip Gerilmesi Deneyi\n");
    printf("9. Asansor Deneyi\n");
    printf("------------------------------------------\n");
}

// 1. Serbest Düşme Deneyi
void serbest_dusme(double *g_ptr) {
    double t, h;
    printf("\n--- Serbest Dusme Deneyi ---\n");
    printf("Dusus suresini giriniz (sn): ");
    scanf("%lf", &t);


    t = (t < 0) ? -t : t;
    if(t != (t < 0 ? -t : t)) printf("Negatif deger mutlak degere cevrildi: %.2f\n", t);

    printf("\n%-10s | %-15s\n", "GEZEGEN", "YOL (h) [m]");
    printf("---------------------------\n");

    for (int i = 0; i < 8; i++) {
        double g = *(g_ptr + i);
        h = 0.5 * g * t * t;
        printf("%-10s | %.2f m\n", GEZEGENLER[i], h);
    }
}

// 2. Yukarı Atış Deneyi
void yukari_atis(double *g_ptr) {
    double v0, h_max;
    printf("\n--- Yukari Atis Deneyi ---\n");
    printf("Firlatma hizini giriniz (m/s): ");
    scanf("%lf", &v0);

    v0 = (v0 < 0) ? -v0 : v0;

    printf("\n%-10s | %-15s\n", "GEZEGEN", "MAX YUKSEKLIK (m)");
    printf("---------------------------\n");

    for (int i = 0; i < 8; i++) {
        double g = *(g_ptr + i);
        h_max = (v0 * v0) / (2 * g);
        printf("%-10s | %.2f m\n", GEZEGENLER[i], h_max);
    }
}

// 3. Ağırlık Deneyi
void agirlik_deneyi(double *g_ptr) {
    double m, G;
    printf("\n--- Agirlik Deneyi ---\n");
    printf("Cismin kutlesini giriniz (kg): ");
    scanf("%lf", &m);

    m = (m < 0) ? -m : m;

    printf("\n%-10s | %-15s\n", "GEZEGEN", "AGIRLIK (N)");
    printf("---------------------------\n");

    for (int i = 0; i < 8; i++) {
        double g = *(g_ptr + i);
        G = m * g;
        printf("%-10s | %.2f N\n", GEZEGENLER[i], G);
    }
}

// 4. Potansiyel Enerji Deneyi
void potansiyel_enerji(double *g_ptr) {
    double m, h, Ep;
    printf("\n--- Potansiyel Enerji Deneyi ---\n");
    printf("Cismin kutlesini giriniz (kg): ");
    scanf("%lf", &m);
    printf("Yuksekligi giriniz (m): ");
    scanf("%lf", &h);

    m = (m < 0) ? -m : m;
    h = (h < 0) ? -h : h;

    printf("\n%-10s | %-15s\n", "GEZEGEN", "ENERJI (Joule)");
    printf("---------------------------\n");

    for (int i = 0; i < 8; i++) {
        double g = *(g_ptr + i);
        Ep = m * g * h;
        printf("%-10s | %.2f J\n", GEZEGENLER[i], Ep);
    }
}

// 5. Hidrostatik Basınç Deneyi
void hidrostatik_basinc(double *g_ptr) {
    double rho, h, P;
    printf("\n--- Hidrostatik Basinc Deneyi ---\n");
    printf("Sivinin yogunlugunu giriniz (kg/m3): ");
    scanf("%lf", &rho);
    printf("Derinligi giriniz (m): ");
    scanf("%lf", &h);

    rho = (rho < 0) ? -rho : rho;
    h = (h < 0) ? -h : h;

    printf("\n%-10s | %-15s\n", "GEZEGEN", "BASINC (Pascal)");
    printf("---------------------------\n");

    for (int i = 0; i < 8; i++) {
        double g = *(g_ptr + i);
        P = rho * g * h;
        printf("%-10s | %.2f Pa\n", GEZEGENLER[i], P);
    }
}

// 6. Arşimet Kaldırma Kuvveti
void arsimet_kaldirma(double *g_ptr) {
    double rho, V, Fk;
    printf("\n--- Arsimet Kaldirma Kuvveti Deneyi ---\n");
    printf("Sivinin yogunlugunu giriniz (kg/m3): ");
    scanf("%lf", &rho);
    printf("Cismin batan hacmini giriniz (m3): ");
    scanf("%lf", &V);

    rho = (rho < 0) ? -rho : rho;
    V = (V < 0) ? -V : V;  

    printf("\n%-10s | %-15s\n", "GEZEGEN", "KALDIRMA KUV. (N)");
    printf("---------------------------\n");

    for (int i = 0; i < 8; i++) {
        double g = *(g_ptr + i);
        Fk = rho * g * V;
        printf("%-10s | %.2f N\n", GEZEGENLER[i], Fk);
    }
}

// 7. Basit Sarkaç Periyodu
void sarka_periyodu(double *g_ptr) {
    double L, T;
    printf("\n--- Basit Sarkac Periyodu Deneyi ---\n");
    printf("Sarkac uzunlugunu giriniz (m): ");
    scanf("%lf", &L);

    L = (L < 0) ? -L : L;

    printf("\n%-10s | %-15s\n", "GEZEGEN", "PERIYOT (sn)");
    printf("---------------------------\n");

    for (int i = 0; i < 8; i++) {
        double g = *(g_ptr + i);
        T = 2 * PI * sqrt(L / g);
        printf("%-10s | %.2f s\n", GEZEGENLER[i], T);
    }
}

// 8. Sabit İp Gerilmesi
void ip_gerilmesi(double *g_ptr) {
    double m, T;
    printf("\n--- Sabit Ip Gerilmesi Deneyi ---\n");
    printf("Cismin kutlesini giriniz (kg): ");
    scanf("%lf", &m);

    m = (m < 0) ? -m : m;

    printf("\n%-10s | %-15s\n", "GEZEGEN", "GERILME (N)");
    printf("---------------------------\n");

    for (int i = 0; i < 8; i++) {
        double g = *(g_ptr + i);
        T = m * g;
        printf("%-10s | %.2f N\n", GEZEGENLER[i], T);
    }
}

// 9. Asansör Deneyi
void asansor_deneyi(double *g_ptr) {
    double m, a, N;
    int yon_secimi;
    printf("\n--- Asansor Deneyi ---\n");
    printf("1. Asansor YUKARI ivmelenerek hizlaniyor VEYA ASAGI ivmelenerek yavasliyor (N = m(g+a))\n");
    printf("2. Asansor ASAGI ivmelenerek hizlaniyor VEYA YUKARI ivmelenerek yavasliyor (N = m(g-a))\n");
    printf("Durum seciniz (1 veya 2): ");
    scanf("%d", &yon_secimi);
    printf("Cismin kutlesini giriniz (kg): ");
    scanf("%lf", &m);
    printf("Asansor ivmesini giriniz (m/s^2): ");
    scanf("%lf", &a);

    m = (m < 0) ? -m : m;
    a = (a < 0) ? -a : a;

    printf("\n%-10s | %-15s\n", "GEZEGEN", "ETKIN AGIRLIK (N)");
    printf("---------------------------\n");

    for (int i = 0; i < 8; i++) {
        double g = *(g_ptr + i);
        
        if (yon_secimi == 1) {
            N = m * (g + a);
        } else {
            N = m * (g - a);
            
            if(N < 0) N = 0; 
        }
        printf("%-10s | %.2f N\n", GEZEGENLER[i], N);
    }
}
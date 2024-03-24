#include <stdio.h>
struct Vozenje{
    char ime[100];
    int vreme;
    float cena;
    int popust;
};
typedef struct Vozenje vozenje;
struct park{
    char ime[100];
    char lokacija[100];
    vozenje niza[100];
    int broj;
};
typedef struct park park;

void print(park *c, int n)
{
    for (int i = 0; i < n; i++){
        printf("%s %s\n", c[i].ime, c[i].lokacija);
        for (int j = 0; j < c[i].broj; j++){
            printf("%s %d %.2f\n", c[i].niza[j].ime, c[i].niza[j].vreme, c[i].niza[j].cena);
        }
    }
}
void najdobar(park *c, int n)
{
    int vreme,brojac, brojacmax = 0;
    int maxvreme = 0, index = 0;
    for (int i = 0; i < n; i++){
        vreme = 0;
        brojac = 0;
        for (int j = 0; j < c[i].broj; j++){
            if (c[i].niza[j].popust == 1) {
                brojac++;
            }
            vreme += c[i].niza[j].vreme;
        }
        if (brojac > brojacmax) {
            brojacmax = brojac;
            index = i;
            maxvreme = vreme;
        }
        else if(brojac == brojacmax && vreme > maxvreme)
        {
            index = i;
            maxvreme = vreme;
        }

    }
    printf("Najdobar park: %s %s",c[index].ime, c[index].lokacija);
}
int main()
{
    park v[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%s %s", v[i].ime, v[i].lokacija);
        scanf("%d", &v[i].broj);
        for (int j = 0; j < v[i].broj; j++){
            scanf("%s", v[i].niza[j].ime);
            scanf("%d", &v[i].niza[j].vreme);
            scanf("%f", &v[i].niza[j].cena);
            scanf("%d", &v[i].niza[j].popust);
        }
    }
    print(v, n);
    najdobar(v, n);
    return 0;
}

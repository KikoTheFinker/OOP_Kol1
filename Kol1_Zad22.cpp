#include <stdio.h>
#include <string.h>
struct Proizvod{
    char podatoci[20];
    int cena;
    int broj;
};
typedef struct Proizvod proizvod;

struct Narachka{
    char ime[20];
    proizvod niza[10];
    int brojnaracki[10];
    int n;
};
typedef struct Narachka Narachka;

void pecatiFaktura(Narachka n)
{
    int pop[30];
    int brojac = 0;
    int suma = 0;
    int flag = 0;
    char amax[30];
    int flag1 = 0;
    int temp = 0;
    printf("Faktura za %s\n", n.ime);
    for (int i = 0; i < n.n; i++){
        if (n.niza[i].broj < n.brojnaracki[i]){
            brojac ++;
        }
        if (brojac > 0){
            printf("Fakturata ne moze da se izgotvi");
            flag = 1;
            break;
        }
        else
        {
            if (flag1 == 0) {
                int p = 0;
                for (int k = 0; k < n.n - 1; k++) {
                    if (n.niza[k].podatoci[p] > n.niza[k + 1].podatoci[p]) {
                        strcpy(amax, n.niza[k].podatoci);
                        strcpy(n.niza[k].podatoci, n.niza[k + 1].podatoci);
                        strcpy(n.niza[k + 1].podatoci, amax);
                        flag1 = 1;
                        p++;
                    }
                    else if (n.niza[k].podatoci[p] == n.niza[k + 1].podatoci[p])
                    {
                        p++;
                        k++;
                    }

                }
            }
            pop[i] = n.niza[i].cena*n.brojnaracki[i];
            n.niza[i].broj = n.brojnaracki[i];
            suma+= pop[i];
        }
    }
    if (flag == 0) {
        if (flag1 == 1) {
            for (int d = 0; d < n.n - 1; d++) {
                temp = n.brojnaracki[d];
                n.brojnaracki[d] = n.brojnaracki[d + 1];
                n.brojnaracki[d + 1] = temp;
                temp = n.niza[d].cena;
                n.niza[d].cena = n.niza[d + 1].cena;
                n.niza[d + 1].cena = temp;
                suma = 0;
            }
            for (int d = 0; d < n.n; d++){
                pop[d] = n.niza[d].cena*n.niza[d].broj;
                suma+= pop[d];
            }
        }

        for (int i = 0; i < n.n; i++) {
            printf("%s %d %d %d\n", n.niza[i].podatoci,n.niza[i].cena , n.niza[i].broj ,pop[i] );
        }
        printf("Vkupnata suma na fakturata e %d", suma);
    }
}
int main() {

    Narachka narachka;

    scanf("%s", narachka.ime);
    scanf("%d", &narachka.n);
    int i;
    for (i = 0; i < narachka.n; ++i) {
        scanf("%s", narachka.niza[i].podatoci);
        scanf("%d", &narachka.niza[i].cena);
        scanf("%d", &narachka.niza[i].broj);

    }
    int j;
    for (j = 0; j < narachka.n; ++j) {
        scanf("%d", &narachka.brojnaracki[j]);
    }

    pecatiFaktura(narachka);


    return 0;
}
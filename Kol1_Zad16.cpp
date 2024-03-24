#include <stdio.h>
#include <string.h>
#define NEDELI 4
#define DENOVI 5
struct RabotnaNedela{
    int casovi[100];
};

typedef struct RabotnaNedela RN;

struct Rabotnik{
    char ime[50];
    RN nedeli[4];
};

typedef struct Rabotnik R;

void table(R *r, int n) {
    int den = 0;
    int vkupno = 0;
    printf("Rab\t1\t2\t3\t4\tVkupno\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t", r[i].ime);
        for (int j = 0; j < NEDELI; j++) {
            for (int k = 0; k < DENOVI; k++){
                den+= r[i].nedeli[j].casovi[k];
            }
            printf("%d\t", den);
            vkupno+=den;
            den = 0;
        }
        printf("%d\n", vkupno);
        vkupno = 0;

    }
}
int maxnedela(R *r)
{
    int cas = 0, casmax = 0, index = 0;
    for (int j = 0; j < NEDELI; j++){
        for (int k = 0; k < DENOVI; k++){
            cas+= r->nedeli[j].casovi[k];
        }
        if (cas > casmax){
            casmax = cas;
            index = j;
        }
        cas = 0;
    }
    return index;
}

int main() {
    int n;
    scanf("%d", &n);
    R rabotnici[n];
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", rabotnici[i].ime);
        int j;
        for (j = 0; j < NEDELI; ++j) {
            int k;
            for (k = 0; k < DENOVI; ++k) {
                scanf("%d", &rabotnici[i].nedeli[j].casovi[k]);
            }
        }
    }
    printf("TABLE\n");
    table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", rabotnici[n / 2].ime);
    printf("%d\n", maxnedela(&rabotnici[n / 2])+1);
    return 0;
}

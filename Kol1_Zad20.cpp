#include<stdio.h>
typedef struct Pacient{
    char ime[100];
    int zdrastveno;
    int pregledi;
}Pacient;

typedef struct MaticenDoktor{
    char ime[100];
    int br_pac;
    Pacient niza[50];
    float cena;
}doktor;

void najuspesen_doktor(doktor *p, int n) {
    int brpreg = 0;
    float suma = 0;
    int index = 0;
    float sumamax = 0;
    int brpregmax = 0;
    for (int i = 0; i < n; i++){
        brpreg = 0;
        suma = 0;
        for (int j = 0; j < p[i].br_pac; j++){
            if (p[i].niza[j].zdrastveno == 0)
            {
                suma+= p[i].niza[j].pregledi;
            }
            brpreg += p[i].niza[j].pregledi;
        }
        suma *= p[i].cena;
        if (suma > sumamax)
        {
            sumamax = suma;
            index = i;
            brpregmax = brpreg;
        }
        else if(suma == sumamax)
        {
            if (brpreg > brpregmax)
            {
                brpregmax = brpreg;
                index = i;

            }
        }
    }

    printf("%s %.2f %d", p[index].ime, sumamax, brpregmax);
}
int main()
{
    int i, j, n, broj;
    doktor md[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        //ime na doktor
        scanf("%s", md[i].ime);
        //broj na pacienti
        scanf("%d", &md[i].br_pac);
        //cena na pregled
        scanf("%f", &md[i].cena);

        for (j = 0; j < md[i].br_pac; j++){
            scanf("%s", md[i].niza[j].ime);
            scanf("%d", &md[i].niza[j].zdrastveno);
            scanf("%d", &md[i].niza[j].pregledi);
        }
    }
    najuspesen_doktor(md, n);

    return 0;
}

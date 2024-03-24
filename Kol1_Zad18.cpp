#include<stdio.h>
#include<string.h>
typedef struct Skilift{
    char ime[20];
    int broj;
    int dali;
}skilift;

typedef struct Skicenter{
    char ime[20];
    char drzhava[20];
    skilift niza[20];
    int broj;
}skicenter;


void najgolemKapacitet(skicenter *sc, int n)
{
    skicenter max;
    int skijacimax = 0, pro = 0;
    int brliftmax = 0, maxy = 0;
    for (int i = 0; i < n; i++){
        brliftmax = 0;
        skijacimax = 0;
        for (int j = 0; j < sc[i].broj; j++)
        {
            if (sc[i].niza[j].dali == 1) {
                skijacimax += sc[i].niza[j].broj;
            }
            brliftmax += sc[i].broj;
        }
        if (skijacimax > pro)
        {
            pro = skijacimax;
            max = sc[i];
        }
        else if(skijacimax == pro)
        {
            if (brliftmax > maxy)
            {
                maxy = brliftmax;
                max = sc[i];
            }
        }
    }
    printf("%s\n%s\n%d", max.ime, max.drzhava, pro);
}
int main()
{
    int n;
    skicenter p[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%s", p[i].ime);
        scanf("%s", p[i].drzhava);
        scanf("%d", &p[i].broj);
        for(int j = 0; j < p[i].broj; j++){
            scanf("%s",p[i].niza[j].ime);
            scanf("%d %d", &p[i].niza[j].broj, &p[i].niza[j].dali);
        }



    }
    najgolemKapacitet(p, n);

    //povik na funkcijata najgolemKapacitet

    return 0;
}

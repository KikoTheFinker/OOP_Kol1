#include <stdio.h>
struct laptop{
    char ime[100];
    double inchi;
    int touch;
    int cena;
};
typedef struct laptop laptop;

struct ITStore{
    char ime[100];
    char lokacija[100];
    laptop niza[100];
    int broj;
};
typedef struct ITStore ITStore;

void print(ITStore *s, int n)
{
    for (int j = 0; j < n; j++) {
        printf("%s %s\n",s[j].ime, s[j].lokacija);
        for (int i = 0; i < s[j].broj; i++) {
            printf("%s %g %d\n", s[j].niza[i].ime, s[j].niza[i].inchi, s[j].niza[i].cena);

        }
    }
}
void najevtinaponuda(ITStore *s, int n)
{
    int maxcena = 0;
    int index = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < s[i].broj; j++){
            if (s[i].niza[j].touch == 1)
            {
                if (maxcena == 0){
                    maxcena = s[i].niza[j].cena;
                }
                if (s[i].niza[j].cena < maxcena)
                {
                    maxcena = s[i].niza[j].cena;
                    index = i;
                }
            }
        }
    }
    printf("Najeftina ponuda ima prodavnicata:\n%s %s\n", s[index].ime, s[index].lokacija);
    printf("Najniskata cena iznesuva: %d", maxcena);

}
int main() {
    ITStore s[100];
    int n;
    scanf("%d",&n); //broj na IT prodavnici
    for (int i = 0; i < n; i++) {
        scanf("%s %s", s[i].ime, s[i].lokacija);
        scanf("%d", &s[i].broj);
        for (int j = 0; j < s[i].broj; j++) {
            scanf("%s %lf %d %d", s[i].niza[j].ime, &s[i].niza[j].inchi, &s[i].niza[j].touch, &s[i].niza[j].cena);

        }
    }
    print(s, n);
    najevtinaponuda(s, n);

    return 0;
}
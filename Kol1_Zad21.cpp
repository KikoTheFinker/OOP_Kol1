#include<iostream>
#include<cstring>
using namespace std;
struct tanc{
    char tanc[20];
    char zemja[20];
};
struct tancer{
    char ime[20];
    char prezime[20];
    tanc niza[5];

};

void tancuvanje(tancer *t, int n, char *zemja)
{
    char p[20];
    int flag = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++){
            if (::strcmp(t[i].niza[j].zemja, zemja)== 0){
                if (::strcmp(t[i].ime, p) != 0) {
                    strcpy(p, t[i].ime);
                    cout << t[i].ime << " ";
                    cout << t[i].prezime << ", ";
                    cout << t[i].niza[j].tanc << "\n";
                }

            }
        }
    }
}
int main()
{
    int i, j, n;
    char zemja[15];
    tancer tanceri[5];
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> tanceri[i].ime;
        cin >> tanceri[i].prezime;
        for(j = 0; j < 3; j++){
            cin >> tanceri[i].niza[j].tanc;
            cin >> tanceri[i].niza[j].zemja;
        }
    }
    cin >> zemja;
    tancuvanje(tanceri, n, zemja);
    return 0;
}
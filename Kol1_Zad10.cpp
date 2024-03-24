#include <iostream>
#include <cstring>
using namespace std;
struct igrac{
    char ime[20];
    int nivo;
    int poeni;
};
struct game{
    char game_name[20];
    igrac igraci[30];
    int br;
};
void najdobar(game *lista, int n)
{
    char igramax[20];
    int poenimax = 0;
    int max = 0;
    int index = 0;
    int igracishte = 0;
    char ime[20];
    for (int i = 0; i < n; i++){
        if (lista[i].br > max){
            max = lista[i].br;
            index = i;
        }
    }
    for (int i = 0; i < max; i++) {
        if (lista[index].igraci[i].poeni > poenimax) {
            poenimax = lista[index].igraci[i].poeni;
            strcpy(ime, lista[index].igraci[i].ime);
            strcpy(igramax, lista[index].game_name);
        } else if (lista[index].igraci[i].poeni == poenimax) {
            if (lista[index].igraci[i].nivo > igracishte) {
                igracishte = lista[index].igraci[i].nivo;
                strcpy(igramax, lista[index].game_name);
            }
        }
    }
    cout<<"Najdobar igrac e igracot so korisnicko ime "<<ime<<" koj ja igra igrata "<<igramax;

}
int main(){
    game igra[50];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>igra[i].game_name>>igra[i].br;
        for (int j = 0; j < igra[i].br; j++){
            cin>>igra[i].igraci[j].ime>>igra[i].igraci[j].nivo>>igra[i].igraci[j].poeni;
        }
    }
    najdobar(igra, n);

}
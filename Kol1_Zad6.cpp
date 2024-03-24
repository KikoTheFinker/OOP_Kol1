
#include<iostream>
#include <cstring>
using namespace std;
struct voz{
    char relacija[50];
    int kilometri;
    int patnici;
};
struct stanica{
    char grad[50];
    voz vozovi[30];
    int br;
};

void najkratkaRelacija(stanica *zs, int n, char *gradd)
{
    char relation[50];
    char p[20];
    int kilometrimin = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(zs[i].grad, gradd) == 0) {
            for (int j = 0; j < zs[i].br; j++) {

                if (kilometrimin == 0){
                    kilometrimin = zs[i].vozovi[j].kilometri;
                }
                if (zs[i].vozovi[j].kilometri <= kilometrimin) {
                    kilometrimin = zs[i].vozovi[j].kilometri;
                    strcpy(relation, zs[i].vozovi[j].relacija);
                }
            }
        }
    }
    cout<<"Najkratka relacija: "<<relation<<" ("<< kilometrimin<<" km)";
}
int main(){

    int n;
    cin>>n;
    stanica zStanica[100];
    for (int i=0;i<n;i++){
        cin>>zStanica[i].grad;
        cin>>zStanica[i].br;
        for (int j = 0; j < zStanica[i].br; j++){
            cin>>zStanica[i].vozovi[j].relacija;
            cin>>zStanica[i].vozovi[j].kilometri;
            cin>>zStanica[i].vozovi[j].patnici;
        }
    }

    char grad[25];
    cin>>grad;
    najkratkaRelacija(zStanica, n, grad);

    return 0;
}

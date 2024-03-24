#include<iostream>
#include<cstring>
using namespace std;
enum tip {
    pop,
    rap,
    rok
};
class Pesna{
private:
    char *ime;
    int vreme;
    tip tipp;

    void copy(const Pesna & other)
    {
        this-> ime = new char [strlen(other.ime)+1];
        strcpy(this-> ime, other.ime);
        this-> vreme = other.vreme;
        this-> tipp = other.tipp;
    }
public:
    Pesna(char *ime = new char [0], int vreme = 0, tip tipp = pop)
    {
        this-> ime = new char [strlen(ime)+1];
        strcpy(this-> ime, ime);
        this-> vreme = vreme;
        this-> tipp = tipp;
    }
    Pesna & operator =(const Pesna &p)
    {
        if (this != &p)
        {
            delete[] ime;
            copy(p);
        }
        return *this;
    }
    Pesna(const Pesna & other) {
        copy(other);
    }
    ~Pesna(){
        delete []ime;
    }
    int getvreme()
    {
        return vreme;
    }
    int gettip()
    {
        return tipp;
    }
    void pecati()
    {
        cout<<"\""<<ime<<"\"-" << vreme<<"min"<<endl;
    }

};

class CD{
private:
    Pesna pesni[10];
    int broj;
    int minuti;

public:
    CD(int minuti = 0)
    {
        this->minuti = minuti;
        this->broj = 0;
    }
    ~CD() {
    }
    int getBroj()
    {
        return broj;
    }

    Pesna getPesna(int i)
    {
        return pesni[i];
    }

    void dodadiPesna(Pesna p)
    {
        int max = 0;
        for (int i = 0; i < broj; i++)
        {
            max+= pesni[i].getvreme();
        }
        max += p.getvreme();
        if (max < minuti && broj < 10)
        {
            pesni[broj++] = p;
        }
    }
    void pecatiPesniPoTip(tip t)
    {
        for (int i = 0; i < broj; i++)
        {
            if(pesni[i].gettip() == t)
            {
                pesni[i].pecati();
            }
        }
    }
};
int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
        p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i=0; i<n; i++)
            (omileno.getPesna(i)).pecati();
    }
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i=0; i<omileno.getBroj(); i++)
            (omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }

    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

class Pica{
    char ime[15];
    int cena;
    char *sostojki;
    int namaluvanje;

    void copy(const Pica & other)
    {
        strcpy(this-> ime, other.ime);
        this->cena = other.cena;
        this-> sostojki = new char[strlen(other.sostojki)+1];
        strcpy(this->sostojki, other.sostojki);
        this->namaluvanje = other.namaluvanje;
    }
public:
    Pica(const char *ime = " ", int cena = 0, const char *sostojki = " ", int namaluvanje = 0)
    {
        strcpy(this->ime, ime);
        this->cena = cena;
        this-> sostojki = new char[strlen(sostojki)+1];
        strcpy(this->sostojki, sostojki);
        this-> namaluvanje = namaluvanje;
    }
    Pica(const Pica & other)
    {
        copy(other);
    }
    ~Pica(){
        delete[]sostojki;
    }
    Pica & operator = (const Pica & other)
    {
        if (this != &other)
        {
            delete[]sostojki;
            copy(other);
        }
        return *this;
    }
    void pecati()
    {
        cout<<ime<<" - "<<sostojki<<", "<<cena;
    }
    bool istise(Pica &p)
    {
        return (strcmp(sostojki,p.sostojki) == 0);
    }
    int getnamaluvanje()
    {
        return namaluvanje;
    }
    int getcena()
    {
        return cena;
    }

};

class Picerija{
private:
    char ime[15];
    Pica *niza;
    int broj;

    void copy(const Picerija & other)
    {
        this->broj = other.broj;
        strcpy(this->ime, other.ime);
        this->niza = new Pica[this->broj];
        for (int i = 0; i < broj; i++) {
            this->niza[i] = other.niza[i];
        }
    }
public:
    Picerija(const char *ime = "", Pica *niza = nullptr, int broj = 0)
    {
        strcpy(this->ime, ime);
        this->broj = broj;
        this->niza = new Pica[broj];
        for (int i = 0; i < broj; i++){
            this->niza[i] = niza[i];
        }
    }
    Picerija(const Picerija & other)
    {
        copy(other);
    }
    Picerija & operator = (const Picerija & other)
    {
        if (this!= &other){
            delete[]niza;
            copy(other);
        }
        return *this;
    }
    ~Picerija(){
        delete [] niza;
    }
    Picerija & operator += (Pica & other)
    {
        bool same = false;
        for (int i = 0; i < broj; i++){
            if(niza[i].istise(other) != 0)
            {
                same = true;
            }

        }
        if (!same)
        {
            Pica *tmp = new Pica[broj+1];
            for (int i = 0; i < broj; i++){
                tmp[i] = niza[i];
            }
            tmp[broj++] = other;
            delete [] niza;
            niza = tmp;
        }
        return *this;
    }

    void piciNaPromocija()
    {
        for (int i = 0; i < broj; i++){
            if (niza[i].getnamaluvanje() > 0)
            {
                niza[i].pecati();
                cout << " " << niza[i].getcena() * (1 - niza[i].getnamaluvanje() / 100.0) << endl;
            }

        }
    }
    void setIme(char *imee)
    {
        strcpy(this-> ime, imee);
    }
    char *getIme()
    {
        return ime;
    }

};
int main() {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for (int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp, 100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki, 100);
        int popust;
        cin >> popust;
        Pica p(imp, cena, sostojki, popust);
        p1+=p;
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp, 100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki, 100);
    int popust;
    cin >> popust;
    Pica p(imp, cena, sostojki, popust);
    p2+=p;

    cout << p1.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p1.piciNaPromocija();

    cout << p2.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p2.piciNaPromocija();

    return 0;
}

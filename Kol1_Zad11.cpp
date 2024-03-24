#include <iostream>
#include <cstring>

using namespace std;

class Ucesnik{
private:
    char *ime;
    bool pol;
    int vozrast;
public:
    Ucesnik(char *ime = " ", bool pol = true, int vozrast = 0)
    {
        this->ime = new char [strlen(ime)+1];
        strcpy(this->ime, ime);
        this->pol = pol;
        this->vozrast = vozrast;
    }
    Ucesnik(const Ucesnik & other)
    {
        this->ime = new char [strlen(other.ime)+1];
        strcpy(this->ime, other.ime);
        this->pol = other.pol;
        this->vozrast = other.vozrast;
    }
    int getVozrast()
    {
        return vozrast;
    }
    bool operator > (const Ucesnik & other)
    {
        return (vozrast > other.vozrast);
    }
    friend ostream & operator <<(ostream & out, Ucesnik & other)
    {
        out<<other.ime<<" "<<endl;
        if (other.pol == 0)
        {
            out<<"zhenski"<<endl;
        } else{
            out<<"mashki"<<endl;
        }
        out<<other.vozrast<<endl;
        return out;
    }
};
class Maraton{
    char lokacija[100];
    Ucesnik *niza;
    int n;
public:
    Maraton(char *lokacija = "")
    {
        strcpy(this->lokacija, lokacija);
        this->n = 0;
        this->niza = nullptr;
    }
    Maraton(const Maraton & other)
    {
        this->n = other.n;
        strcpy(this->lokacija, other.lokacija);
        for (int i = 0; i < n; i++){
            this->niza[i] = other.niza[i];
        }
    }
    ~Maraton(){
        delete[] niza;
    }
    Maraton & operator +=(const Ucesnik & other)
    {
        Ucesnik *tmp = new Ucesnik[n+1];
        for (int i = 0; i < n; i++){
            tmp[i] = niza[i];
        }
        tmp[n++]=other;
        delete[]niza;
        niza = tmp;
        return *this;
    }
    void pecatiPomladi(Ucesnik &u)
    {
        for (int i = 0; i < n; i++) {
            if (u.getVozrast() > niza[i].getVozrast())
            {
                cout<<niza[i];
            }
        }
    }
    double prosecnoVozrast(){
        double suma = 0;
        for (int i = 0; i < n; i++)
        {
            suma+= niza[i].getVozrast();
        }
        return suma/double(n);
    }
};
int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
    m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for(int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete [] u;
    return 0;
}
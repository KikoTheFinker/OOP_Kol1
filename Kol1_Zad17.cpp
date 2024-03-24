#include <iostream>
#include <cstring>

using namespace std;

enum Tip {
    LINUX,
    UNIX,
    WINDOWS
};

class OperativenSistem {
private:
    char *ime;
    float verzija;
    Tip tip;
    float GB;

    void copy(const OperativenSistem &other) {
        this->ime = new char[strlen(other.ime) + 1];
        strcpy(this->ime, other.ime);
        this->verzija = other.verzija;
        this->tip = other.tip;
        this->GB = other.GB;
    }

public:
    OperativenSistem(char *ime = new char [0], float verzija = 0, Tip tip = LINUX, float GB = 0) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->verzija = verzija;
        this->tip = tip;
        this->GB = GB;
    }

    OperativenSistem(const OperativenSistem &other) {
        copy(other);
    }

    ~OperativenSistem() {
        delete[] ime;
    }

    OperativenSistem &operator=(const OperativenSistem &other) {
        if (this != &other) {
            delete[] ime;
            copy(other);
        }
        return *this;
    }

    void pecati() {
        cout << "Ime: " << ime << " Verzija: " << verzija << " Tip: " << tip << " Golemina:" << GB <<"GB"<<endl;
    }

    bool ednakviSe(const OperativenSistem &os) {
        return (strcmp(ime, os.ime) == 0 && verzija == os.verzija && GB == os.GB && tip == os.tip);
    }

    int sporediVerzija(const OperativenSistem &os) {
        if (verzija == os.verzija) {
            return 0;
        } else if (os.verzija > verzija) {
            return -1;
        } else {
            return 1;
        }
    }

    bool istaFamilija(const OperativenSistem &sporedba) {
        return (strcmp(ime, sporedba.ime) == 0 && tip == sporedba.tip);
    }
};

class Repozitorium {
private:
    char ime[20];
    OperativenSistem *niza;
    int n;

public:
    Repozitorium(const char *ime = " ") {
        strcpy(this->ime, ime);
        this->n = 0;
        this->niza = nullptr;
    }

    ~Repozitorium() {
        delete[] niza;
    }
    void pecatiOperativniSistemi()
    {
        cout<<"Repozitorium: "<<ime<<endl;
        for (int i = 0; i < n; i++){
            niza[i].pecati();
        }
    }
    void izbrishi(const OperativenSistem &operativenSistem)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (!niza[i].ednakviSe(operativenSistem))
            {
                niza[j++] = niza[i];
            }
        }
        this-> n = j;
    }
    void dodadi(const OperativenSistem &nov)
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (niza[i].istaFamilija(nov) && niza[i].sporediVerzija(nov) == -1)
            {
                niza[i] = nov;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            OperativenSistem * tmp = new OperativenSistem[n+1];
            for (int i = 0; i < n; i++)
            {
                tmp[i] = niza[i];
            }
            tmp[n++] = nov;
            delete[] niza;
            niza = tmp;
        }

    }
};


int main() {
    char repoName[20];
    cin >> repoName;
    Repozitorium repozitorium = Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin >> brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i < brojOperativniSistemi; i++) {
        cin >> ime;
        cin >> verzija;
        cin >> tip;
        cin >> golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin >> ime;
    cin >> verzija;
    cin >> tip;
    cin >> golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
    cout << "=====Brishenje na operativen sistem=====" << endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}
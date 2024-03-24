#include <iostream>
#include <cstring>

using namespace std;

class Gitara {
    char seriski[25];
    float cena;
    int godina;
    char tip[40];

    void copy(const Gitara &other) {
        strcpy(this->seriski, other.seriski);
        this->cena = other.cena;
        this->godina = other.godina;
        strcpy(this->tip, other.tip);
    }

public:
    Gitara(char *tip = "", char *seriski = "", int godina = 0, float cena = 0) {
        strcpy(this->seriski, seriski);
        this->cena = cena;
        this->godina = godina;
        strcpy(this->tip, tip);

    }

    ~Gitara() {

    }

    Gitara(const Gitara &other) {
        copy(other);
    }

    bool daliIsti(Gitara &other) {
        return (strcmp(seriski, other.seriski) == 0);
    }

    char *getTip() {
        return tip;
    }

    char *getSeriski() {
        return seriski;
    }

    int getGodina() {
        return godina;
    }

    float getNabavna() {
        return cena;
    }

    void print() {
        cout << seriski << " " << tip << " " << cena << "\n";
    }
};

class Magacin {
    char ime[30];
    char lokacija[60];
    Gitara *niza;
    int n;
    int otvoranje;

    void copy(const Magacin &other) {
        strcpy(this->ime, other.ime);
        strcpy(this->lokacija, other.lokacija);
        this->n = other.n;
        this->otvoranje = other.otvoranje;
        this->niza = new Gitara[n];
        for (int i = 0; i < n; i++) {
            this->niza[i] = other.niza[i];
        }
    }

public:
    Magacin(char *ime = "", char *lokacija = "", int otvaranje = 0) {
        strcpy(this->ime, ime);
        strcpy(this->lokacija, lokacija);
        this->otvoranje = otvaranje;
        this->niza = nullptr;
        this->n = 0;
    }

    Magacin(const Magacin &other) {
        copy(other);
    }

    ~Magacin() {
    }

    void dodadi(Gitara &d) {
        Gitara *tmp = new Gitara[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = niza[i];
        }
        tmp[n++] = d;
        delete[]niza;
        niza = tmp;
    }

    void prodadi(Gitara &p) {
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (!niza[i].daliIsti(p)) {
                niza[j++] = niza[i];
            }
        }
        this->n = j;
    }

    void pecati(bool daliNovi)
    {
        cout<<ime<<" "<<lokacija<<"\n";
        if (daliNovi)
        {
            for (int i = 0; i < n; i++){
                if (niza[i].getGodina() > otvoranje)
                {
                    niza[i].print();
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                niza[i].print();
            }
        }
    }


    double vrednost() {
        double suma = 0;
        for (int i = 0; i < n; i++) {
            suma += niza[i].getNabavna();
        }
        return suma;
    }
};


int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, godina;
    float cena;
    char seriski[50], tip[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Gitara ======" << endl;
        cin >> tip;
        cin >> seriski;
        cin >> godina;
        cin >> cena;
        Gitara g(tip, seriski, godina, cena);
        cout << g.getTip() << endl;
        cout << g.getSeriski() << endl;
        cout << g.getGodina() << endl;
        cout << g.getNabavna() << endl;
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata Magacin so metodot print() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1");
        kb.pecati(false);
    } else if (testCase == 3) {
        cout << "===== Testiranje na klasata Magacin so metodot dodadi() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2005);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;
            Gitara g(tip, seriski, godina, cena);
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
    } else if (testCase == 4) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2012);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(false);
        kb.prodadi(brisi);
        kb.pecati(false);
    } else if (testCase == 5) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2011);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
        kb.prodadi(brisi);
        cout << "Po brisenje:" << endl;
        Magacin kb3;
        kb3 = kb;
        kb3.pecati(true);
    } else if (testCase == 6) {
        cout << "===== Testiranje na klasata Magacin so metodot vrednost()======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2011);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            kb.dodadi(g);
        }
        cout << kb.vrednost() << endl;
        kb.prodadi(brisi);
        cout << "Po brisenje:" << endl;
        cout << kb.vrednost();
        Magacin kb3;
        kb3 = kb;
    }
    return 0;
}

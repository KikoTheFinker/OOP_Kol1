#include<iostream>
#include<cstring>
using namespace std;

class StockRecord{
private:
    char id[15];
    char ime[50];
    double cena;
    double momentalnacena;
    int broj;
public:
    StockRecord(char *id = "", char *ime = " ", double cena = 0, int broj = 0)
    {
        strcpy(this->id, id);
        strcpy(this->ime, ime);
        this->cena = cena;
        this->momentalnacena = 0;
        this->broj = broj;
    }
    ~StockRecord(){
    }


    StockRecord & operator = (const StockRecord & other)
    {
        if (this!=&other)
        {
            strcpy(this->id, other.id);
            strcpy(this->ime, other.ime);
            this->cena = other.cena;
            this->momentalnacena = other.momentalnacena;
            this->broj = other.broj;
        }
        return *this;
    }
    void setNewPrice(double c)
    {
        momentalnacena = c;
    }
    double value(){
        return double(broj) * momentalnacena;
    }
    double profit(){
        return double(broj) * (momentalnacena - cena);
    }
    friend ostream & operator<<(ostream & out, StockRecord &p)
    {
        out << p.ime <<" "<<p.broj << " "<<p.cena <<" "<<p.momentalnacena<<" "<<p.profit()<<endl;
        return out;
    }
};
class Client{
    char ime[60];
    int id;
    StockRecord *niza;
    int n;
public:
    Client(char *ime = "", int id = 0)
    {
        strcpy(this->ime, ime);
        this->id = id;
        this->n = 0;
        this->niza = new StockRecord[n];
    }

    ~Client(){
        delete[]niza;
    }
    Client & operator = (const Client & other)
    {
        if (this!=&other)
        {
            delete[]niza;
            strcpy(this->ime, other.ime);
            this->id = other.id;
            this->n = other.n;
            this->niza = new StockRecord[n];
            for (int i = 0; i < n; i++)
            {
                this->niza[i] = other.niza[i];
            }
        }
        return *this;
    }
    Client & operator +=(StockRecord & other)
    {
        StockRecord *tmp = new StockRecord[n+1];
        for (int i = 0; i < n; i++)
        {
            tmp[i] = niza[i];
        }
        delete[] niza;
        tmp[n++] = other;
        niza = tmp;
        return *this;
    }
    double totalValue()
    {
        double suma = 0;
        for (int i = 0; i < n; i++)
        {
            suma+=niza[i].value();
        }
        return suma;
    }
    friend ostream & operator <<( ostream & out, Client & p)
    {
        out << p.id << " " <<p.totalValue()<<endl;
        for (int i = 0; i < p.n; i++)
        {
            out << p.niza[i];
        }
        return out;
    }
};

int main(){

    int test;
    cin >> test;

    if(test == 1){
        double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        cout << "Konstruktor OK" << endl;
        cin >> price;
        sr.setNewPrice(price);
        cout << "SET metoda OK" << endl;
    }
    else if(test == 2){
        cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
        char id[12], company[50];
        double price, newPrice;
        int n, shares;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> id;
            cin >> company;
            cin >> price;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            cout << sr.value() << endl;
            cout << sr;
        }
    }
    else if(test == 3){
        cout << "=====TEST NA KLASATA Client=====" << endl;
        char companyID[12], companyName[50], clientName[50];
        int clientID, n, shares;
        double oldPrice, newPrice;
        bool flag = true;
        cin >> clientName;
        cin >> clientID;
        cin >> n;
        Client c(clientName, clientID);
        cout << "Konstruktor OK" << endl;
        for(int i = 0; i < n; ++i){
            cin >> companyID;
            cin >> companyName;
            cin >> oldPrice;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);
            c += sr;
            if(flag){
                cout << "Operator += OK" << endl;
                flag = false;
            }
        }
        cout << c;
        cout << "Operator << OK" << endl;
    }
    return 0;

}
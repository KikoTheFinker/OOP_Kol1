#include <iostream>
#include <cstring>
using namespace std;

class List{
private:
    int *niza;
    int n;

    void copy(const List & other)
    {
        this->niza = new int[other.n];
        this-> n = other.n;
        for (int i = 0; i < other.n; i++){
            this->niza[i] = other.niza[i];
        }
    }
public:
    List(const int *niza = nullptr, int n = 0)
    {
        this-> n = n;
        this->niza = new int [n];
        for (int i = 0; i < n; i++)
        {
            this-> niza[i] = niza[i];
        }
    }
    List(const List & other)
    {
        copy(other);
    }
    List & operator = (const List & other)
    {
        if (this != &other)
        {
            delete [] niza;
            copy(other);
        }
        return *this;
    }

    int getN() const {
        return n;
    }

    int sum()
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += niza[i];
        }
        return sum;
    }
    double average()
    {
        return double(sum())/double(n);
    }
    void pecati()
    {
        cout<<n<<": ";
        for (int i = 0; i < n; i++)
        {
            cout<<niza[i]<<" ";
        }
        cout<<"sum: "<<sum()<<" average: "<<average()<<endl;
    }
    ~List(){
        delete []niza;
    }

};

class ListContainer{
private:
    List *niza;
    int broj;
    int brojac;
    void copy(ListContainer const & other)
    {
        this-> broj = other.broj;
        this-> brojac = other.brojac;
        this -> niza = new List[other.broj];
        for (int  i= 0; i < this->broj; i++)
        {
            this->niza[i] = other.niza[i];
        }
    }
public:
    ListContainer( int broj = 0, int brojac = 0)
    {
        this->broj = broj;
        this->brojac = brojac;
        this-> niza = new List [broj];
        for (int i = 0; i < broj; i++) {
            this->niza[i] = niza[i];
        }
    }
    ListContainer(ListContainer const & other)
    {

        copy(other);
    }
    ListContainer & operator = (const ListContainer  & other)
    {
        if (this != &other)
        {
            delete [] niza;
            copy(other);
        }
        return *this;
    }
    ~ListContainer()
    {
        delete [] niza;
    }
    int sum()
    {
        int sumce = 0;
        for (int i = 0; i < broj; i++)
        {
            sumce+=niza[i].sum();
        }
        return sumce;
    }
    double average()
    {
        int novoSumce = 0;
        for (int i = 0; i < broj; i++) {
            novoSumce += niza[i].sum();
        }
        double brojache = 0;
        for (int i = 0; i < broj; i++) {
            brojache+= niza[i].getN();
        }
        return double(novoSumce)/brojache;
    }
    void print()
    {
        for (int i = 0; i < broj; i++) {
            cout << "List number: "<<i+1;
            cout<<" List info: ";
            niza[i].pecati();
        }
        if (sum() == 0)
        {
            cout<<"The list is empty"<<endl;
        }
        else
        {
            cout<<"Sum: "<<sum()<<" "<<"Average: "<<average()<<endl;
            cout<<"Successful attempts: "<<broj<<" Failed attempts: "<<brojac - broj<<endl;
        }

    }
    void addNewList (List l)
    {
        brojac++;
        int flag = 0;
        int zbir = l.sum();
        List *temp = new List[broj+1];
        for (int i = 0; i < broj; i++){
            if(zbir == niza[i].sum())
            {
                flag = 1;
            }
        }
        if (flag == 0){
            for (int i = 0; i < broj; i++){
                temp[i] = niza[i];
            }

            temp[broj++] = l;
            delete[]niza;
            niza = temp;
        }

    }
};

int main() {

    ListContainer lc;
    int N;
    cin>>N;

    for (int i=0;i<N;i++) {
        int n;
        int niza[100];

        cin>>n;

        for (int j=0;j<n;j++){
            cin>>niza[j];

        }

        List l=List(niza,n);

        lc.addNewList(l);
    }


    int testCase;
    cin>>testCase;

    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1.sum();
        lc1.average();

    }
    else {
        lc.print();
    }
}
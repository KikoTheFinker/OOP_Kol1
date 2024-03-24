#include<iostream>
#include<cstring>

using namespace std;

enum Extension {
    txt,
    pdf,
    exe
};

class File {
private:
    char *ime;
    Extension tip;
    char *sopstvenik;
    int mb;

    void copy(const File &other) {
        this->tip = other.tip;
        this->mb = other.mb;
        this->ime = new char[strlen(other.ime) + 1];
        this->sopstvenik = new char[strlen(other.sopstvenik) + 1];
        strcpy(this->ime, other.ime);
        strcpy(this->sopstvenik, other.sopstvenik);
    }

public:
    File(char *ime = new char [0], char *sopstvenik = new char [0], int mb = 0, Extension tip = txt) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->sopstvenik = new char[strlen(sopstvenik) + 1];
        strcpy(this->sopstvenik, sopstvenik);
        this->tip = tip;
        this->mb = mb;
    }

    File(const File &other) {
        copy(other);
    }

    ~File() {
        delete[] sopstvenik;
        delete[] ime;
    }

    File &operator=(const File &other) {
        if (this != &other) {
            delete[]ime;
            delete[] sopstvenik;
            copy(other);
        }
        return *this;
    }

    void print() {
        cout << "File name: " << ime;
        if(this->tip == 0)
        {
            cout<<".pdf\n";
        }
        else if(this->tip == 1)
        {
            cout<<".txt\n";
        }
        else {
            cout <<".exe\n";
        }
        cout << "File owner: " << sopstvenik << endl;
        cout << "File size: " << mb << endl;
    }

    bool equals (const File & file) {
        return (tip == file.tip) && !strcmp(ime, file.ime)
               && (!strcmp(sopstvenik, file.sopstvenik));
    }

    bool equalsType (const File & file) {
        return (tip == file.tip) && !strcmp(ime, file.ime);
    }
};

class Folder {
private:
    char *ime;
    int n;
    File *niza;

    void copy(const Folder &other) {
        this->ime = new char[strlen(other.ime) + 1];
        strcpy(this->ime, other.ime);
        this->n = other.n;
        this->niza = new File[other.n];
        for (int i = 0; i < n; i++) {
            this->niza[i] = other.niza[i];
        }
    }

public:
    Folder(const char *ime = new char[0], int n = 0, const File *niza = new File [0]) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->n = n;
        this->niza = new File[n];
        for (int i = 0; i < n; i++) {
            this->niza[i] = niza[i];
        }
    }

    ~Folder() {
        delete[] ime;
        delete[] niza;
    }

    Folder(const Folder &other) {
        copy(other);
    }

    void print() {
        cout << "Folder name: " << ime<<endl;
        for (int i = 0; i < n; i++) {
            niza[i].print();
        }
    }


    void remove(const File &file) {
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (!niza[i].equals(file)) {
                niza[j] = niza[i];
                j++;
            }
        }
        this->n = j;
    }

    void add(const File & file) {
        File *tmp = new File[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = niza[i];
        }
        tmp[n++] = file;
        delete[] niza;
        niza = tmp;
    }
};

int main() {
    char fileName[20];
    char fileOwner[20];
    int ext;
    int fileSize;
    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File created = File(fileName, fileOwner, fileSize, (Extension) ext);
        File copied = File(created);
        File assigned = created;

        cout << "======= CREATED =======" << endl;
        created.print();
        cout << endl;
        cout << "======= COPIED =======" << endl;
        copied.print();
        cout << endl;
        cout << "======= ASSIGNED =======" << endl;
        assigned.print();
    } else if (testCase == 2) {
        cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File first(fileName, fileOwner, fileSize, (Extension) ext);
        first.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File second(fileName, fileOwner, fileSize, (Extension) ext);
        second.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File third(fileName, fileOwner, fileSize, (Extension) ext);
        third.print();

        bool equals = first.equals(second);
        cout << "FIRST EQUALS SECOND: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equals = first.equals(third);
        cout << "FIRST EQUALS THIRD: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        bool equalsType = first.equalsType(second);
        cout << "FIRST EQUALS TYPE SECOND: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equalsType = second.equals(third);
        cout << "SECOND EQUALS TYPE THIRD: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

    } else if (testCase == 3) {
        cout << "======= FOLDER CONSTRUCTOR =======" << endl;
        cin >> fileName;
        Folder folder(fileName);
        folder.print();

    } else if (testCase == 4) {
        cout << "======= ADD FILE IN FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        folder.print();
    } else {
        cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File file(fileName, fileOwner, fileSize, (Extension) ext);
        folder.remove(file);
        folder.print();
    }
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa{
    string nama;
    string npm;
    Mahasiswa *next;
};

Mahasiswa *head, *tail, *temp, *curr, *mhs;

void createLinkedList(string nama, string npm){
    if (head == NULL){
        head = new Mahasiswa();
        head->nama = "iqbal";
        head->npm = "22081010217";
        head->next = NULL;
        tail = head;
        cout << "linked list berhasil dibuat" << endl;
        cout << "Mahasiswa " << head->nama << " berhasil ditambahkan" << endl;
    }else{
        cout << "linked list sudah dibuat" << endl;
    }
}

void insertFirst(string nama, string npm){
    if (head != NULL){
        mhs = new Mahasiswa();
        mhs->nama = nama;
        mhs->npm = npm;
        mhs->next = head;
        head = mhs;
        cout << "Mahasiswa " << mhs->nama << " berhasil ditambahkan" << endl;
    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }
}

void insertLast(string nama, string npm){
    if (head != NULL){
        mhs = new Mahasiswa();
        mhs->nama = nama;
        mhs->npm = npm;
        mhs->next = NULL;
        tail->next = mhs;
        tail = mhs;
        cout << "Mahasiswa " << mhs->nama << " berhasil ditambahkan" << endl;
    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }
}

void insertAfter(string nama, string npm, string key){
    if (head != NULL){
        curr = head;
        while( curr->npm != key){
            curr = curr->next;
        }
        mhs = new Mahasiswa();
        mhs->nama = nama;
        mhs->npm = npm;
        mhs->next = curr->next;
        curr->next = mhs;
        cout << "Mahasiswa " << mhs->nama << " berhasil ditambahkan" << endl;
    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }
}

void removeFirst(){
    if (head != NULL){
        temp = head;
        head = head->next;
        cout << "data mahasiswa " << temp->nama  << " telah dihapus" << endl;
        delete temp;
    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }
}

void removeLast(){
    if (head != NULL){
        temp = tail;
        curr = head;
        while (curr->next != temp){
            curr = curr->next;
        }
        curr->next = NULL;
        tail = curr;
        cout << "data mahasiswa " << temp->nama  << " telah dihapus" << endl;
        delete temp;
    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }
}

void removeMhs(string key){
    if (head != NULL){
        curr = head;
        while (curr->next->npm != key){
            curr = curr->next;
        }
        temp = curr->next;
        curr->next = temp->next;
        cout << "data mahasiswa " << temp->nama  << " telah dihapus" << endl;
        delete temp;
    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }
}

void updateMhs(string nama, string npm, string key){
    if (head != NULL){
        curr = head;
        while (curr->npm != key){
            curr = curr->next;
        }
        curr->nama = nama;
        curr->npm = npm;
        cout << "Data mahasiswa berhasil diubah" << endl;
        cout << "NPM\t: " << curr->nama  << endl;
        cout << "Nama\t: " << curr->npm  << endl;
    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }
}

void searchMhs(string key){
    int isFound = 0;

    if (head != NULL){
        curr = head;
        while (curr != NULL && curr->npm != key){
            curr = curr->next;
        }
        if (curr == NULL){
            cout << "data mahasiswa tidak ditemukan" << endl;
        }else{
            cout << "Mahasiswa Ditemukan" << endl;
            cout << "Nama\t: " << curr->nama << endl;
            cout << "NPM\t: " << curr->npm << endl;
        }

    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }
}

void getAllMhs(){
    curr = head;
    if (curr != NULL){
        int i = 1;
        while(curr != NULL){
            cout << "Mahasiswa ke - " << i << endl;
            cout << "Nama\t: " << curr->nama << endl;
            cout << "NPM\t: " << curr->npm << endl;
            curr = curr->next;
            i++;
        }
    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }
}


int main(){
    createLinkedList("iqbal", "22081010217");

    insertLast("hafiz", "22081010031");
    insertFirst("abdul", "22081010200");
    insertAfter("haikal", "22081010210", "22081010031");
    cout << endl;

    updateMhs("firqi", "22081010120", "22081010200");
    cout << endl;

    getAllMhs();
    cout << endl;

    insertFirst("budi", "22081010001");
    cout << endl;

    removeMhs("22081010217");
    removeFirst();
    removeLast();
    cout << endl;
    
    searchMhs("22081010001");
    cout << endl;

    getAllMhs();
    return 0;
}
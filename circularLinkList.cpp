#include <iostream>

using namespace std;

struct Mahasiswa{
    string nama;
    string npm;
    Mahasiswa *next;
};

Mahasiswa *head, *tail, *temp, *curr, *mhs, *after;

void createLinkList(string nama, string npm){
    if (head == NULL){
        head = new Mahasiswa();
        head->nama = nama;
        head->npm = npm;
        head->next = NULL;
        tail = head;
        cout << "circular linked list berhasil dibuat" << endl;
        cout << "Mahasiswa " << head->nama << " berhasil ditambahkan" << endl;
    }else{
        cout << "circular linked list telah dibuat" << endl;
    }
}

void insertFirst(string nama, string npm){
    if (head != NULL){
        mhs = new Mahasiswa();
        mhs->nama = nama;
        mhs->npm = npm;
        mhs->next = head;
        head = mhs;
        tail->next = head;
        cout << "Mahasiswa " << mhs->nama << " berhasil ditambahkan" << endl;
    }else{
        cout << "circular linked list belum dibuat";
    }
}

void insertLast(string nama, string npm){
    if (head != NULL){
        mhs = new Mahasiswa();
        mhs->nama = nama;
        mhs->npm = npm;
        mhs->next = head;
        tail->next = mhs;
        tail = mhs;
        cout << "Mahasiswa " << mhs->nama << " berhasil ditambahkan" << endl;
    }else{
        cout << "circular linked list belum dibuat" << endl;
    }
}

void insertAfter(string nama, string npm, string key){
    if (head != NULL){
        mhs = new Mahasiswa();
        mhs->nama = nama;
        mhs->npm = npm;
        curr = head;
        while(curr != NULL && curr->npm != key && curr != tail){
            curr = curr->next;
        }
        mhs->next = curr->next;
        curr->next = mhs;
        cout << "Mahasiswa " << mhs->nama << " berhasil ditambahkan" << endl;
    }else{
        cout << "circular linked list belum dibuat" << endl;
    }
}

void removeFirst(){
    if (head != NULL){
        temp = head;
        head = head->next;
        tail->next = head;
        cout << "data mahasiswa " << temp->nama  << " telah dihapus" << endl;
        delete temp;
    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }
}

void removeLast(){
    if (head != NULL){
        curr = head;
        while(curr != NULL && curr->next != tail){
            curr = curr->next;
        }
        temp = tail;
        curr->next = head;
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
        while (curr != NULL && curr->next->npm != key && curr != tail){
            curr = curr->next;
        }
        if (curr->next->npm == key){
            temp = curr->next;
            curr->next = temp->next;
            cout << "data mahasiswa " << temp->nama  << " telah dihapus" << endl;
            delete temp;
        }else{
            cout << "data mahasiwa tidak ditemukan" << endl;
        }
    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }
}

void updateMhs(string nama, string npm, string key){
    if (head != NULL){  
        curr = head;
        while (curr != NULL && curr->npm != key && curr != tail){
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
    if (head != NULL){  
        curr = head;
        while (curr != NULL && curr->npm != key && curr != tail){
            curr = curr->next;
        }
        if (curr->npm == key){
            cout << "Data mahasiswa ditemukan" << endl;
            cout << "Nama\t: " << curr->nama << endl;
            cout << "NPM\t: " << curr->npm << endl;
        }else{
            cout << "data mahasiswa tidak ditemukan" << endl;
        }
    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }
}

void getAllMhs(){
    if (head != NULL){
        curr = head;
        int i = 1;
        do{
            cout << "data mahasiswa ke " << i << endl;
            cout << "Nama\t: " << curr->nama << endl;
            cout << "NPM\t: " << curr->npm << endl;
            curr = curr->next;
            i++;
        }while(curr != NULL && curr != head);
    }else{
        cout << "data mahasiswa masih kosong";
    }
}

int main(){
    createLinkList("iqbal", "22081010217");
    insertFirst("hafiz", "22081010031");
    insertLast("ryan", "22081010200");
    insertFirst("haikal", "22081010021");
    insertAfter("jabbar", "22081010035", "22081010031");
    cout << endl;

    updateMhs("gofar", "22081010045", "22081010217");
    cout << endl;

    searchMhs("22081010200");
    cout << endl;

    removeMhs("22081010031");
    removeFirst();
    removeLast();
    cout << endl;

    getAllMhs();
    cout << endl;
    
    return 0;
}
#include <iostream>

using namespace std;

struct Mahasiswa{
    string nama;
    string npm;
    Mahasiswa *prev;
    Mahasiswa *next;
};

Mahasiswa *head, *tail, *temp, *curr, *mhs, *after;

void createLinkList(string nama, string npm){
    if (head == NULL){
        head = new Mahasiswa();
        head->nama = nama;
        head->npm = npm;
        head->prev = NULL;
        head->next = NULL;
        tail = head;
        cout << "double linked list berhasil dibuat" << endl;
        cout << "Mahasiswa " << head->nama << " berhasil ditambahkan" << endl;
    }else{
        cout << "linked list sudah ada";
    }
}

void insertFirst(string nama, string npm){
    if (head != NULL){
        // mhs next ke head
        mhs = new Mahasiswa();
        mhs->nama = nama;
        mhs->npm = npm;
        mhs->prev = NULL;
        mhs->next = head;
        head->prev = mhs;
        head = mhs;
        cout << "Mahasiswa " << mhs->nama << " berhasil ditambahkan" << endl;
    }else{
        cout << "link list belum ada";
    } 
}

void insertLast(string nama, string npm){
    if (head != NULL){
        mhs = new Mahasiswa();
        mhs->nama = nama;
        mhs->npm = npm;
        tail->next = mhs;
        mhs->next = NULL;
        mhs->prev = tail;
        tail = mhs;
        cout << "Mahasiswa " << mhs->nama << " berhasil ditambahkan" << endl;
    }else{
        cout << "link list belum ada";
    } 
}

void insertAfter(string nama, string npm, string key){
    if (head != NULL){
        curr = head;
        while(curr->npm != key){
            curr = curr->next;
        }
        temp = curr->next;
        mhs = new Mahasiswa();
        mhs->nama = nama;
        mhs->npm = npm;
        mhs->next = curr->next;
        mhs->prev = curr;
        temp->prev = mhs;
        curr->next = mhs;
        cout << "Mahasiswa " << mhs->nama << " berhasil ditambahkan" << endl;
    }else{
        cout << "link list belum ada";
    } 
}

void removeFirst(){
    if (head != NULL){
        temp = head;
        head = head->next;
        head->prev = NULL;
        cout << "Mahasiswa " << temp->nama << " berhasil dihapus" << endl;
        delete temp;
    }else{
        cout << "link list belum ada";        
    }
}

void removeLast(){
    if (head != NULL){
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        cout << "Mahasiswa " << temp->nama << " berhasil dihapus" << endl;
        delete temp;
    }else{
        cout << "link list belum ada";        
    }
}

void removeMhs(string npm){
    if (head != NULL){
        curr = head;
        while(curr->npm != npm){
            curr = curr->next;
        }
        curr = curr->prev;
        temp = curr->next;
        after = temp->next;
        curr->next = after;
        after->prev = curr;
        cout << "Mahasiswa " << temp->nama << " berhasil dihapus" << endl;
        delete temp;
    }else{
        cout << "data mahasiswa belum ada";
    }
}

void updateMhs( string nama, string npm, string key){
    if (head != NULL){
        curr = head;
        while(curr->npm != key){
            curr = curr->next;
        }
        curr->nama = nama;
        curr->npm = npm;
        cout << "Data mahasiswa berhasil diubah" << endl;
        cout << "NPM\t: " << curr->npm << endl;
        cout << "Nama\t: " << curr->nama << endl;
    }else{
        cout << "data mahasiswa belum ada";
    }
}

void searchMhs(string key){
    if (head != NULL){
        curr = head;
        while(curr != NULL && curr->npm != key){
            curr = curr->next;
        }

        if (curr != NULL){
            cout << "Data mahasiswa ditemukan" << endl;
            cout << "Nama\t: " << curr->nama << endl;
            cout << "NPM\t: " << curr->npm << endl;
        }else{
            cout << "data mahasiswa tidak ditemukan";
        }


    }else{
        cout << "data mahasiswa belum ada";
    }
}


void displayForward(){
    if (head != NULL){
        curr = head;
        int i = 1;
        cout << "Menampilkan data dari depan" << endl;
        while(curr != NULL){
            cout << "Mahasiswa ke - " << i << endl;
            cout << "Nama\t: " << curr->nama << endl;
            cout << "NPM\t: " << curr->npm << endl;
            curr = curr->next;
            i++;
        }
    }else{
        cout << "link list belum ada";
    }
}

void displayBackward(){
    if (head != NULL){
        curr = tail;
        int i = 1;
        cout << "Menampilkan data dari belakang" << endl;
        while(curr != NULL){
            cout << "Mahasiswa ke - " << i << endl;
            cout << "Nama\t: " << curr->nama << endl;
            cout << "NPM\t: " << curr->npm << endl;
            curr = curr->prev;
            i++;
        }
    }else{
        cout << "link list belum ada";
    }
}



int main(){
    createLinkList("iqbal", "22081010217");

    insertFirst("hafiz", "22081010031");
    insertLast("ryan", "22081010100");
    insertAfter("budi", "22081010200", "22081010031");
    insertFirst("haikal", "22081010400");
    cout << endl;

    displayForward();
    cout << endl;

    displayBackward();
    cout << endl;

    updateMhs("haikal", "22081010300", "22081010400");
    cout << endl;

    searchMhs("22081010300");
    cout << endl;
    
    removeFirst();
    removeLast();
    removeMhs("22081010200");
    cout << endl;


    return 0;
}
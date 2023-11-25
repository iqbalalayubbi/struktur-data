#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa{
    string nama;
    string npm;
    Mahasiswa *next;
};

Mahasiswa *head, *tail, *temp, *curr, *mhs;
int choose = 0;

void insertMahasiswa(){
    string nama, npm;
    cout << "Masukkan Nama : " ;
    cin.get();
    getline(cin, nama);

    cout << "Masukkan NPM : " ;
    getline(cin, npm);

    if(head == NULL){
        // insert first
        head = new Mahasiswa();
        head->nama = nama;
        head->npm = npm;
        head->next = NULL;
        tail = head;
    }else{
        // insert last
        mhs = new Mahasiswa();
        mhs->nama = nama;
        mhs->npm = npm;
        mhs->next = NULL;
        tail->next = mhs;
        tail = mhs;
    }
    cout << "Data mahasiswa berhasil ditambahkan" << endl;
}

void getAllMahasiswa(){
    curr = head;
    cout << "Data Mahasiswa" << endl;
    if (head != NULL){
        while(curr != NULL){
            cout << "Nama : " << curr->nama << endl;
            cout << "NPM : " << curr->npm << endl;
            curr = curr->next;
        }
    }else{
        cout << "Data mahasiswa masih kosong" << endl;
    }
}

void searchMahasiswa(){
    string npm;
    cout << "NPM mahasiswa : " ;
    cin.get();
    getline(cin, npm);

    if (head != NULL){
        curr = head;
        while(curr != NULL && curr->npm != npm ){
            curr = curr->next;
        }
        
        if(curr != NULL){
            cout << "Data mahasiswa" << endl;
            cout << "Nama : " << curr->nama << endl;
            cout << "NPM : " << curr->npm << endl;
        }else{
            cout << npm << " tidak ditemukan" << endl;
        }


    }else{
        cout << "Data mahasiswa masih kosong";
    }
}

void removeMahasiswa(){
    string npm;
    cout << "NPM mahasiswa : " ;
    cin.get();
    getline(cin, npm);

    if (head != NULL){
        curr = head;
        while(curr != NULL && curr->npm != npm ){
            curr = curr->next;
        }
        
        if(curr != NULL){
            // remove first
            if (curr == head){
                head = head->next;
                delete curr;
            }
            // remove last
            else if(curr == tail){
                temp = head;
                while(temp->next != curr){
                    temp = temp->next;
                }
                tail = temp;
                tail->next = NULL;
                delete curr;
            }
            // remove mid
            else{
                temp = head;
                while(temp->next != curr){
                    temp = temp->next;
                }
                temp->next = curr->next;
                delete curr;
            }
            cout << "Data mahasiswa berhasil dihapus" << endl;
        }else{
            cout << npm << " tidak ditemukan" << endl;
        }


    }else{
        cout << "Data mahasiswa masih kosong";
    }
}

void showMenu(){
    cout << endl;
    cout << "Aplikasi Kelola Mahasiswa" << endl;
    cout << "1. Tambah mahasiswa baru" << endl;
    cout << "2. Hapus data mahasiswa" << endl;
    cout << "3. Cari data mahasiswa" << endl;
    cout << "4. Tampilkan data mahasiswa" << endl;
    cout << "Pilih sesuai dengan menu (1-4) : ";
    cin >> choose;
    cout << endl;
}

int main(){
    showMenu();
    while(choose != 0){
        switch (choose)
        {
            case 1:
                insertMahasiswa();
                break;
            case 2:
                removeMahasiswa();
                break;
            case 3:
                searchMahasiswa();
                break;
            case 4:
                getAllMahasiswa();
                break;
            default:
                cout << "menu tidak tersedia" << endl;
                break;
        }
        showMenu();
    }

    // struct Mhs
    // {
    //     string nama;
    //     string npm;
    // };

    // Mhs mahasiswa[5] = {{"iqbal", "217"}, {"hafiz", "031"}, {"haikal", "055"}, {"ganes", "066"}, {"ryan","077"}};
    
    // for(int i=0; i<5; i++){
    //     insertMahasiswa(mahasiswa[i].nama, mahasiswa[i].npm);
    // }

    // getAllMahasiswa();
    // removeMahasiswa(mahasiswa[2].npm);
    // getAllMahasiswa();
    // removeMahasiswa(mahasiswa[1].npm);
    // getAllMahasiswa();
    // removeMahasiswa(mahasiswa[4].npm);
    // getAllMahasiswa();
    // removeMahasiswa(mahasiswa[0].npm);
    // getAllMahasiswa();

    // execute command
    // g++ single.cpp -o single && .\single


    return 0;
}
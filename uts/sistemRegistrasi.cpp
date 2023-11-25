#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Mahasiswa{
    string nama;
    string npm;
    string jurusan;
    string dosenWali;
    Mahasiswa *next;
};

struct OrderMhs{
    int number;
    OrderMhs *next;
};

Mahasiswa *headMhs, *tailMhs, *tempMhs, *currMhs, *mhs;
OrderMhs *headOrder, *tailOrder, *tempOrder, *currOrder, *order;

int totalMhs = 0;
int orderTotal = 0;

string npm = "";

int choice = 0;

void displayTitle(){
    cout << " ___          _    _               _ " << endl;
    cout << "| _ |___ __ _(_)__| |_ _ _ __ _ __(_)" << endl;
    cout << "|   / -_/ _` | (_-|  _| '_/ _` (_-| |" << endl;
    cout << "|_|_|___|__, |_/__/|__|_| |__,_/__|_|" << endl;
    cout << "        |___/                        " << endl;                     

    cout << endl ;
}

void createNPM(){
    string npmTemplate = "22081010";
    string lastNPM = "";

    // ditambah 1 supaya tidak mulai dari 0
    if (totalMhs+1 < 10){
        lastNPM = "00"+to_string(totalMhs+1);
    }else if(totalMhs+1 >= 10 && totalMhs < 100){
        lastNPM = "0"+to_string(totalMhs+1);
    }else{
        lastNPM = to_string(totalMhs+1);
    }
    npm = npmTemplate+lastNPM;
}

int orderEmpty(){
    return tailOrder == NULL;
}

void insertOrder(){
    if (orderEmpty()){
        orderTotal++;
        headOrder = new OrderMhs();
        headOrder->number = orderTotal;
        headOrder->next = NULL;
        tailOrder = headOrder;
    }else{
        orderTotal++;
        order = new OrderMhs;
        order->number = orderTotal;
        order->next = NULL;
        
        tailOrder->next = order;
        tailOrder = order;
    }
    cout << "Antrian nomor " << orderTotal << " telah ditambahkan" << endl;
}

int mhsEmpty(){
    return totalMhs == 0;
}

void removeOrder(){
    tempOrder = headOrder;
    if (headOrder != tailOrder){
        headOrder = headOrder->next;
    }else{
        headOrder = NULL;
        tailOrder = NULL;
    }
    cout << "Antrian " << tempOrder->number << " sedang melakukan registrasi" << endl;
    delete tempOrder;
}

void registerMhs(){
    if (orderEmpty()){
        cout << "Antrian mahasiswa kosong" << endl;
    }else{
        string nama = "";
        string jurusan = "";
        string dosenWali = "";
        cout << "Masukkan nama mahasiswa\t: ";
        cin.get();
        getline(cin, nama);
        cout << "Masukkan jurusan mahasiswa\t: ";
        getline(cin, jurusan);
        cout << "Masukkan Dosen Wali mahasiswa\t: ";
        getline(cin, dosenWali);

        createNPM();
        mhs = new Mahasiswa();
        mhs->nama = nama;
        mhs->npm = npm;
        mhs->jurusan = jurusan;
        mhs->dosenWali = dosenWali;
        mhs->next = NULL;

        if (mhsEmpty()){
            headMhs = mhs;
            tailMhs = headMhs;
        }else{
            tailMhs->next = mhs;
            tailMhs = mhs;
        }
        totalMhs++;
        removeOrder();
        cout << "Registrasi Berhasil" << endl;
        cout << "NPM\t: " << npm << endl;
        cout << "Nama\t: " << nama << endl;
        cout << "Jurusan\t: " << jurusan << endl;
        cout << "Dosen Wali\t: " << dosenWali << endl;
        cout << "Nomor\t: " << totalMhs << endl;
    }
}

void createTable(string tableName){
    const int textLength = 20;

    if (tableName == "mahasiswa"){
        currMhs = headMhs;

        cout << left << setw(textLength) << "NPM" << left << setw(textLength) << "Nama" << left<< setw(textLength)<< "Jurusan" << left << setw(textLength) << "Dosen Wali" << endl;  
        cout << left << setw(80) << "--------------------------------------------------------------------------------" << endl;  
        while (currMhs != NULL)
        {
            cout    << left << setw(textLength) << currMhs->npm
                    << left << setw(textLength) << currMhs->nama
                    << left << setw(textLength) << currMhs->jurusan
                    << left << setw(textLength) << currMhs->dosenWali
                    << endl;
            currMhs = currMhs->next;
        }
    }
}

void getAllMhs(){
    if (mhsEmpty()){
        cout << "Data mahasiswa masih kosong" << endl;
    }else{
        createTable("mahasiswa");      
    }
}

void getAllOrder(){
    if (orderEmpty()){
        cout << "Antrian masih kosong" << endl;
    }else{
        currOrder = headOrder;
        cout << "Daftar antrian saat ini" << endl;
        while (currOrder != NULL)
        {
            cout << currOrder->number << endl;
            currOrder = currOrder->next;
        }
        
    }
}

void searchMhs(){
    string npmVal = "";
    cout << "Masukkan NPM mahasiswa : ";
    cin >> npmVal;

    int isFound = 0;

    if (headMhs != NULL){
        currMhs = headMhs;
        while (currMhs != NULL && currMhs->npm != npmVal){
            currMhs = currMhs->next;
        }
        if (currMhs == NULL){
            cout << "data mahasiswa tidak ditemukan" << endl;
        }else{
            cout << "Data Mahasiswa" << endl;
            cout << "NPM\t: " << currMhs->npm << endl;
            cout << "Nama\t: " << currMhs->nama << endl;
            cout << "Jurusan\t: " << currMhs->jurusan << endl;
            cout << "Dosen Wali\t: " << currMhs->dosenWali << endl;
        }

    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }
}

void getTotalMhs(){
    int totalMhs = 0;
    if (headMhs != NULL){
        currMhs = headMhs;
        while(currMhs != NULL){
            totalMhs++;
            currMhs = currMhs->next;
        }
        cout << "Jumlah Mahasiswa Terdaftar : " << totalMhs << endl;

    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }
}

int isMhs(string npmVal){
    int isFound = 0;

    if (headMhs != NULL){
        currMhs = headMhs;
        while (currMhs != NULL && currMhs->npm != npmVal){
            currMhs = currMhs->next;
        }
        if (currMhs == NULL){
            isFound = 0;
        }else{
            isFound = 1;
        }
    }
    return isFound;
}

void getTotalOrder(){
    int totalOrder = 0;

    if (headOrder != NULL){
        currOrder = headOrder;
        while(currOrder != NULL){
            totalOrder++;
            currOrder = currOrder->next;
        }
        cout << "Jumlah Antrian saat ini : " << totalOrder << endl;

    }else{
        cout << "Antrian masih kosong" << endl;
    }
}

void updateMhs(){
    int updateOption;
    string npmVal;
    string newNama;
    string newDosenWali;

    cout << "Masukkan NPM mahasiswa : ";
    cin.get();
    getline(cin, npmVal);

    if (headMhs != NULL){
        if (isMhs(npmVal)){
            cout << "Pilih Data yang ingin diubah" << endl;
            cout << "1. Nama" << endl;
            cout << "2. Dosen Wali" << endl;
            cout << "Pilih sesuai dengan nomor : ";
            cin >> updateOption;

            currMhs = headMhs;
            while (currMhs->npm != npmVal){
                currMhs = currMhs->next;
            }
            if (updateOption == 1){
                cout << "Masukkan nama baru : ";
                cin.get();
                getline(cin,newNama);
                currMhs->nama = newNama;
            }else if(updateOption == 2){
                cout << "Masukkan Dosen Wali baru : ";
                cin.get();
                getline(cin,newDosenWali);
                currMhs->dosenWali = newDosenWali; 
            }else{
                cout << "input tidak valid" << endl;
            }
            cout << "Data mahasiswa berhasil diubah" << endl;
            cout << "NPM\t: " << currMhs->npm  << endl;
            cout << "Nama\t: " << currMhs->nama  << endl;
            cout << "Jurusan\t: " << currMhs->jurusan  << endl;
            cout << "Dosen Wali\t: " << currMhs->dosenWali  << endl;

        }else{
            cout << "data mahasiswa tidak ditemukan" << endl;
        }
    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }
}

void removeMhs(){
    string npmVal;
    cout << "Masukkan NPM mahasiswa : ";
    cin.get();
    getline(cin, npmVal);

    if (headMhs != NULL){
        currMhs = headMhs;
        while(currMhs != NULL && currMhs->npm != npmVal){
            currMhs = currMhs->next;
        }
        if (isMhs(npmVal)){
            if (currMhs == headMhs){
                // remove first
                tempMhs = headMhs;
                headMhs = headMhs->next;
                cout << "mahasiswa dengan NPM " << tempMhs->npm  << " telah dihapus" << endl;
                delete tempMhs;
            }else if(currMhs == tailMhs){
                // remove last
                tempMhs = tailMhs;
                currMhs = headMhs;
                while (currMhs->next != tempMhs){
                    currMhs = currMhs->next;
                }
                currMhs->next = NULL;
                tailMhs = currMhs;
                cout << "mahasiswa dengan NPM " << tempMhs->npm  << " telah dihapus" << endl;
                delete tempMhs;
            }else{
                currMhs = headMhs;
                while (currMhs->next->npm != npmVal){
                    currMhs = currMhs->next;
                }
                tempMhs = currMhs->next;
                currMhs->next = tempMhs->next;
                cout << "mahasiswa dengan NPM " << tempMhs->npm  << " telah dihapus" << endl;
                delete tempMhs;
            }
        }else{
            cout << "data mahasiswa tidak ditemukan" << endl;
        }
        
    }else{
        cout << "data mahasiswa masih kosong" << endl;
    }

}

void displayMenu(){
    cout << endl;
    cout << "Sistem Registrasi Mahasiswa" << endl;
    cout << "1. Ambil antrian" << endl;
    cout << "2. Daftar Mahasiswa" << endl;
    cout << "3. Lihat daftar mahasiswa" << endl;
    cout << "4. Lihat daftar antrian" << endl;
    cout << "5. Cari Mahasiswa" << endl;
    cout << "6. Jumlah Mahasiswa Terdaftar" << endl;
    cout << "7. Jumlah Antrian" << endl;
    cout << "8. Ubah Data Mahasiwa" << endl;
    cout << "9. Hapus Data Mahasiwa" << endl;
    cout << "Pilih menu (sesuai nomor di atas) : ";
    cin >> choice;
    cout << endl;
}

void runningApp(){
    displayTitle();
    displayMenu();

    while (choice != 0)
    {
        switch (choice)
        {
            case 1:
                insertOrder();
                break;
            case 2:
                registerMhs();
                break;
            case 3:
                getAllMhs();
                break;
            case 4:
                getAllOrder();
                break;
            case 5:
                searchMhs();
                break;
            case 6:
                getTotalMhs();
                break;
            case 7:
                getTotalOrder();
                break;
            case 8:
                updateMhs();
                break;
            case 9:
                removeMhs();
                break;
            default:
                cout << "Menu pilihan tidak tersedia" << endl;
                break;
        }

        displayMenu();
    }

    cout << "Input tidak valid" << endl;
}

int main(){     
    runningApp();
    return 0;
}






// void testingAplikasi(){
//     const int totalData = 3;
//     struct AllMahasiswa{
//         string nama;
//         string jurusan;
//         string dosenWali;
//     };
//     AllMahasiswa mahasiswa[totalData] = {
//         {"iqbal al-ayyubi", "informatika", "hendra"},
//         {"mohammad hafiz", "informatika", "budi"},
//         {"haikal alif", "informatika", "samsul"},
//     };

//     for(int i=0; i<totalData; i++){
//         insertOrder();
//         cout << endl;
//         registerMhs(mahasiswa[i].nama, mahasiswa[i].jurusan, mahasiswa[i].dosenWali);
//         cout << endl;
//     }
//     getAllMhs();
//     cout << endl;
//     getAllOrder();
//     cout << endl;

//     // jika npm ada
//     searchMhs("22081010001");
//     cout << endl;
//     // jika npm tidak ada
//     searchMhs("2208101000100");
//     cout << endl;

//     // cek jumlah mahasiswa
//     getTotalMhs();
//     cout << endl;
//     // cek jumlah antrian
//     getTotalOrder();
//     cout << endl;
    
//     // ubah data

//     // hapus data jika ada
//     removeMhs("22081010001");
//     // hapus data jika tidak ada
//     removeMhs("220810100010");

// }
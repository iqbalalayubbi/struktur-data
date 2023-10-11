#include <iostream>
#include <string>

using namespace std;


struct Mahasiswa{
    string nama;
    string npm;
    string jurusan;
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
    // cout << " _____            _     _                 _ " << endl;
    // cout << "|  __ |          (_)   | |               (_)" << endl;
    // cout << "| |__) |___  __ _ _ ___| |_ _ __ __ _ ___ _ " << endl;
    // cout << "|  _  // _ |/ _` | / __| __| '__/ _` / __| |" << endl;
    // cout << "| | | |  __| (_| | |__ | |_| | | (_| |__ | |" << endl;
    // cout << "|_|  |_|___||__, |_|___/|__|_|  |__,_|___|_|" << endl;
    // cout << "             __/ |                          " << endl;
    // cout << "            |___/                           " << endl;

    cout << " ___          _    _               _ " << endl;
    cout << "| _ |___ __ _(_)__| |_ _ _ __ _ __(_)" << endl;
    cout << "|   / -_/ _` | (_-|  _| '_/ _` (_-| |" << endl;
    cout << "|_|_|___|__, |_/__/|__|_| |__,_/__|_|" << endl;
    cout << "        |___/                        " << endl;

    // cout << " _   _ ___ _  _ " << endl;
    // cout << "| | | | _ | || |" << endl;
    // cout << "| |_| |  _| .` |" << endl;
    // cout << " |___/|_| |_||_|" << endl;                        

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
        // push queue (insert last)
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
        cout << "Masukkan nama mahasiswa\t: ";
        cin.get();
        getline(cin, nama);
        cout << "Masukkan jurusan mahasiswa\t: ";
        getline(cin, jurusan);

        createNPM();
        mhs = new Mahasiswa();
        mhs->nama = nama;
        mhs->npm = npm;
        mhs->jurusan = jurusan;
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
        cout << "Nomor\t: " << totalMhs << endl;
    }
}

void getAllMhs(){
    if (mhsEmpty()){
        cout << "Data mahasiswa masih kosong" << endl;
    }else{
        currMhs = headMhs;
        cout << "Daftar mahasiswa yang telah terdaftar" << endl;
        while (currMhs != NULL)
        {
            cout << "NPM\t: " << currMhs->npm << endl;
            cout << "Nama\t: " << currMhs->nama << endl;
            cout << "Jurusan\t: " << currMhs->jurusan << endl;
            cout << endl;
            currMhs = currMhs->next;
        }
        
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

void displayMenu(){
    cout << endl;
    cout << "Sistem Registrasi Mahasiswa" << endl;
    cout << "1. Ambil antrian" << endl;
    cout << "2. Daftar Mahasiswa" << endl;
    cout << "3. Lihat daftar mahasiswa" << endl;
    cout << "4. Lihat daftar antrian" << endl;
    cout << "Pilih menu (sesuai nomor di atas) : ";
    cin >> choice;
    cout << endl;
}

int main(){       
    displayTitle();     
    // sistem antrian registrasi di UPN
    // user akan mengambil antrian
    // nomor antrian akan bertambah setiap ada mahasiswa yang daftar
    // terdapat pilihan daftarkan mahasiswa
    // npm digenerate bagian 3 digit belakang sesuai dengan antrian
    // setelah melakukan pengecekan berkas maka data user akan dimasukkan kedalam database
    // data dimasukkan dalam bentuk linked list
    displayMenu();

    while (choice != 0)
    {
        if (choice == 1){
            insertOrder();
        }else if(choice == 2){
            registerMhs();
        }else if(choice == 3){
            getAllMhs();
        }else if(choice == 4){
            getAllOrder();
        }else{
            cout << "Menu pilihan tidak tersedia" << endl;
        }

        displayMenu();
    }

    cout << "Input tidak valid" << endl;
    return 0;
}
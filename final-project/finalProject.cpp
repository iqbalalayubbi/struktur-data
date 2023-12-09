#include <iostream>
#include <string>
#include "TextTable.h"
#include "json.hpp"

using namespace std;
TextTable t( '-', '|', '+' );
using json = nlohmann::json;

struct Mahasiswa{
    int npm;
    int height = 0;
    string nama;
    Mahasiswa *left;
    Mahasiswa *right;
};

Mahasiswa *rootMhs, *newMhs;
int choice;
bool isAVL = true;
json dataMhs = json::array();


Mahasiswa *createTree(int npm, string nama){
    newMhs = new Mahasiswa();
    newMhs->nama = nama;
    newMhs->npm = npm;
    newMhs->left = NULL;
    newMhs->right = NULL;
    if (rootMhs == NULL) rootMhs = newMhs;

    cout << "Data mahasiswa dengan NPM " << newMhs->npm << " Berhasil ditambahkan" << endl;

    return newMhs;
}

int maxValue(int a, int b){
    return a > b ? a : b;
}

// get height of node
int heightRoot(Mahasiswa *curr){
    if ( curr == NULL ){
        return 0;
    }else{
        int heightLeft = 1 + heightRoot(curr->left);
        int heightRight = 1 + heightRoot(curr->right);

        return maxValue(heightLeft, heightRight);
    }
}

// rotate
Mahasiswa *rightRotate(Mahasiswa *curr){
    Mahasiswa *leftChild = curr->left;
    curr->left = leftChild->right;
    leftChild->right = curr;
    return leftChild;
}

Mahasiswa *leftRotate(Mahasiswa *curr){
    Mahasiswa *rightChild = curr->right;
    curr->right = rightChild->left;
    rightChild->left = curr;
    return rightChild;
}

int getBalanceFactor(Mahasiswa *curr){
    if (curr == NULL) 
        return 0;
    return heightRoot(curr->left) - heightRoot(curr->right);
}

Mahasiswa *insertMahasiswa(int npm, string nama, Mahasiswa *curr){
    if (curr == NULL)
       return createTree(npm, nama);

    if (npm < curr->npm)            
        curr->left = insertMahasiswa(npm, nama, curr->left);
    else
        curr->right = insertMahasiswa(npm, nama, curr->right);


    if (isAVL){
        int balanceFactor = getBalanceFactor(curr);

        // rotate if  balance faktor > 1 or < -1
        if (balanceFactor > 1 && npm < curr->left->npm)
            return rightRotate(curr);
        if (balanceFactor < -1 && npm > curr->right->npm)
            return leftRotate(curr);
        if (balanceFactor > 1 && npm > curr->left->npm){
            curr->left = leftRotate(curr->left);
            return rightRotate(curr);
        }
        if (balanceFactor < -1 && npm < curr->right->npm){
            curr->right = rightRotate(curr->right);
            return leftRotate(curr);
        }
    }
    return curr;
}

void showAllMahasiswa(Mahasiswa *curr){
    if (curr != NULL){
        showAllMahasiswa(curr->left);
        dataMhs.push_back({curr->nama, to_string(curr->npm)});
        showAllMahasiswa(curr->right);
    }
}

void createTable(json data){
    TextTable t( '-', '|', '+' );
    t.add( "No" );
    t.add( "Nama" );
    t.add( "NPM" );
    t.endOfRow();

    for (int i=0; i<data.size(); i++){
        t.add( to_string(i+1) );
        for (int j=0; j<2; j++){
            t.add( data[i][j] );
        }
        t.endOfRow();
    }

    t.setAlignment( 2, TextTable::Alignment::RIGHT );
    std::cout << t;
}

void showTableMahasiswa(Mahasiswa *curr){
    dataMhs = json::array();
    showAllMahasiswa(curr);
    createTable(dataMhs);
}

Mahasiswa* deleteMahasiswa(int npm, Mahasiswa* curr) {
    if (curr == NULL) {
        cout << "Data Mahasiswa Tidak Ditemukan" << endl;
        return NULL;
    };

    if (npm < curr->npm)
        curr->left = deleteMahasiswa(npm, curr->left);
    else if (npm > curr->npm)
        curr->right = deleteMahasiswa(npm, curr->right);
    else {
        // remove leaf node
        if (curr->left == NULL && curr->right == NULL) {
            cout << "Mahasiswa dengan NPM " << curr->npm << " Berhasil dihapus" << endl;
            delete curr;
            return NULL;
        }
        if (curr->left == NULL) {
            Mahasiswa* childMhs = curr->right;
            cout << "Mahasiswa dengan NPM " << curr->npm << " Berhasil dihapus" << endl;
            delete curr;
            return childMhs;
        }
        else if (curr->right == NULL) {
            Mahasiswa* childMhs = curr->left;
            cout << "Mahasiswa dengan NPM " << curr->npm << " Berhasil dihapus" << endl;
            delete curr;
            return childMhs;
        }
        else {
            Mahasiswa* childMhs = curr->left;
            // find a max value of left child
            while (childMhs->right != NULL)
                childMhs = childMhs->right;

            curr->npm = childMhs->npm;
            curr->left = deleteMahasiswa(childMhs->npm, curr->left);
        }

    }


    if (isAVL){
        int balanceFactor = getBalanceFactor(curr);
        // rotate
        if (balanceFactor > 1) {
            // left case
            if (getBalanceFactor(curr->left) >= 0)
                return rightRotate(curr);

            // left right case
            if (getBalanceFactor(curr->left) < 0) {
                curr->left = leftRotate(curr->left);
                return rightRotate(curr);
            }
        }

        if (balanceFactor < -1) {
            // right case
            if (getBalanceFactor(curr->right) <= 0)
                return leftRotate(curr);

            // right left rotate
            if (getBalanceFactor(curr->right) > 0) {
                curr->right = rightRotate(curr->right);
                return leftRotate(curr);
            }
        }
    }

    return curr;
}

void searchMahasiswa(int npm, Mahasiswa *curr){
    if (curr == NULL)
        cout << "Data Mahasiswa Tidak Ditemukan" << endl;
    else{
        if (npm < curr->npm)
            searchMahasiswa(npm, curr->left);
        else if (npm > curr->npm)
            searchMahasiswa(npm, curr->right);
        else{
            cout << "Data Mahasiswa" << endl;
            cout << "Nama : " << curr->nama << endl;
            cout << "NPM : " << curr->npm << endl;
        }
    }
}

void chooseMethod(){
    cout << endl;
    cout << "Silahkan Pilih Metode" << endl;
    cout << "1. BINARY SEARCH TREE" << endl;
    cout << "2. AVL TREE" << endl;
    cout << "3. Keluar Aplikasi" << endl;
    cout << "Pilih menu (sesuai nomor di atas) : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        isAVL = false;
        break;
    case 2:
        isAVL = true;
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Menu pilihan tidak tersedia" << endl;
        break;
    }
    cout << endl;
}

void displayMenu(){
    cout << endl;
    cout << "Sistem Pendaftaran Mahasiswa" << endl;
    cout << "1. Daftar Mahasiswa" << endl;
    cout << "2. Lihat daftar mahasiswa" << endl;
    cout << "3. Cari Mahasiswa" << endl;
    cout << "4. Hapus Data Mahasiwa" << endl;
    cout << "5. Ganti Metode" << endl;
    cout << "6. Keluar Aplikasi" << endl;
    cout << "Pilih menu (sesuai nomor di atas) : ";
    cin >> choice;
    cout << endl;
}

void displayTitle(){
    if (isAVL){
        cout << "   _________   ____.____      ___________________________________________" << endl;
        cout << "  /  _  \\   \\ /   /|    |     \\__    ___/\\______   \\_   _____/\\_   _____/" << endl;
        cout << " /  /_\\  \\   Y   / |    |       |    |    |       _/|    __)_  |    __)_ " << endl;
        cout << "/    |    \\     /  |    |___    |    |    |    |   \\|        \\ |        \\" << endl;
        cout << "\\____|__  /\\___/   |_______ \\   |____|    |____|_  /_______  //_______  /" << endl;
        cout << "        \\/                 \\/                    \\/        \\/         \\/ " << endl;
        cout << endl;
    }else{
        cout << " ___ _                      ___                 _      _____             "<< endl;
        cout << "| _ (_)_ _  __ _ _ _ _  _  / __|___ __ _ _ _ __| |_   |_   __ _ ___ ___  "<< endl;
        cout << "| _ | | ' \\/ _` | '_| || | \\__ / -_/ _` | '_/ _| ' \\    | || '_/ -_/ -_) "<< endl;
        cout << "|___|_|_||_\\__,_|_|  \\_, | |___\\___\\__,_|_| \\__|_||_|   |_||_| \\___\\___| "<< endl;
        cout << "                     |__/                                                "<< endl;
        cout << endl;

    }
}



int main(){
    // commmand execute
    // g++ finalProject.cpp -o finalProject && .\finalProject
    string nama;
    int npm;

    chooseMethod: // label for choose the method
    chooseMethod();
    rootMhs = insertMahasiswa(217, "iqbal", rootMhs);
    rootMhs = insertMahasiswa(231, "hafiz", rootMhs);
    rootMhs = insertMahasiswa(167, "naufaldy", rootMhs);
    rootMhs = insertMahasiswa(101, "haikal", rootMhs);
    rootMhs = insertMahasiswa(131, "jabbar", rootMhs);
    rootMhs = insertMahasiswa(105, "ryan", rootMhs);
    rootMhs = insertMahasiswa(189, "alex", rootMhs);
    rootMhs = insertMahasiswa(215, "ibnu", rootMhs);
    rootMhs = insertMahasiswa(134, "hendri", rootMhs);
    rootMhs = insertMahasiswa(230, "sultan", rootMhs);
    showTableMahasiswa(rootMhs);

    displayTitle();
    displayMenu();

    while (choice != 0)
    {
        switch (choice)
        {
            case 1:
                cout << "Masukkan Data Mahasiswa" << endl;
                cout << "Nama \t: ";
                cin.get();
                getline(cin, nama);
                cout << "NPM (3 digit terakhir)\t: ";
                cin >> npm;
                rootMhs = insertMahasiswa(npm, nama, rootMhs);
                break;
            case 2:
                cout << "Daftar semua mahasiswa" << endl;
                showTableMahasiswa(rootMhs);
                break;
            case 3:
                cout << "Masukkan NPM \t: ";
                cin >> npm;
                searchMahasiswa(npm, rootMhs);
                break;
            case 4:
                cout << "Masukkan NPM \t: ";
                cin >> npm;
                rootMhs = deleteMahasiswa(npm, rootMhs);
                break;
            case 5:
                goto chooseMethod;
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "Menu pilihan tidak tersedia" << endl;
                break;
        }

        displayMenu();
    } 
    return 0;
}
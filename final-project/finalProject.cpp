#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa{
    int npm;
    int height = 0;
    string nama;
    Mahasiswa *left;
    Mahasiswa *right;
};

Mahasiswa *rootMhs, *newMhs;
int choice;

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
    return curr;
}

void inOrder(Mahasiswa *curr){
    if (curr != NULL){
        inOrder(curr->left);
        cout << "Nama : " << curr->nama << endl;
        cout << "NPM : " << curr->npm << endl;
        inOrder(curr->right);
    }
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

void displayMenu(){
    cout << endl;
    cout << "Sistem Pendaftaran Mahasiswa" << endl;
    cout << "1. Daftar Mahasiswa" << endl;
    cout << "2. Lihat daftar mahasiswa" << endl;
    cout << "3. Cari Mahasiswa" << endl;
    cout << "4. Hapus Data Mahasiwa" << endl;
    cout << "Pilih menu (sesuai nomor di atas) : ";
    cin >> choice;
    cout << endl;
}

void displayTitle(){
    cout << "   _________   ____.____      ___________________________________________" << endl;
    cout << "  /  _  \\   \\ /   /|    |     \\__    ___/\\______   \\_   _____/\\_   _____/" << endl;
    cout << " /  /_\\  \\   Y   / |    |       |    |    |       _/|    __)_  |    __)_ " << endl;
    cout << "/    |    \\     /  |    |___    |    |    |    |   \\|        \\ |        \\" << endl;
    cout << "\\____|__  /\\___/   |_______ \\   |____|    |____|_  /_______  //_______  /" << endl;
    cout << "        \\/                 \\/                    \\/        \\/         \\/ " << endl;
    cout << endl;
}

int main(){
    string nama;
    int npm;

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
                inOrder(rootMhs);
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
            default:
                cout << "Menu pilihan tidak tersedia" << endl;
                break;
        }

        displayMenu();
    } 
    return 0;
    // commmand execute
    // g++ finalProject.cpp -o finalProject && .\finalProject
}

// rootMhs = insertMahasiswa(217, "iqbal", rootMhs);
// rootMhs = insertMahasiswa(206, "haikal", rootMhs);
// rootMhs = insertMahasiswa(205, "hafiz", rootMhs);
// rootMhs = insertMahasiswa(204, "ryan", rootMhs);
// rootMhs = insertMahasiswa(203, "ibnu", rootMhs);
// rootMhs = insertMahasiswa(202, "rama", rootMhs);
// searchMahasiswa(205, rootMhs);
// rootMhs = deleteMahasiswa(217, rootMhs);
// inOrder(rootMhs);
#include <iostream>
#include <string>

using namespace std;
const int MAX_STACK = 5;
string books[MAX_STACK];
int top = -1;

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == MAX_STACK-1;
}

void pushBook(string book){
    if (!isFull()){
        top++;
        books[top] = book;
        cout << "Buku " << book << " berhasil ditambahkan" << endl;
    }else{
        cout << "tumpukan buku masih kosong" << endl;
    }
}

void popBook(){
    if (top > -1){
        cout << "buku yang dihapus adalah "<< books[top] << endl;
        top--;
    }else{
        cout << "Tumpukan buku masih kosong" << endl;
    }
}

void clearAllBook(){
    top = -1;
    cout << "semua buku telah dihapus" << endl;
}

void peekBook(){
    if (top > -1){
        cout << "Buku yang berada paling atas adalah " << books[top] << endl;
    }else{
        cout << "Tumpukan buku masih kosong" << endl;
    }
}

void getBooks(){
    if (top > -1){
        for(int i=0; i<= top; i++){
            cout << "Buku ke-" << i+1 << endl;
            cout << "Judul buku : "<< books[i] << endl;
        }
    }else{
        cout << "Tumpukan buku masih kosong" << endl;
    }
}

int main(){
    pushBook("laskar pelangi");
    pushBook("cantik itu luka");
    pushBook("Bumi manusia");
    pushBook("Ayat-ayat cinta");
    pushBook("cantik itu luka");
    cout << endl;

    getBooks();
    cout << endl;

    peekBook();
    cout << endl;

    popBook();
    cout << endl;

    clearAllBook();
    cout << endl;

    getBooks();
    cout << endl;

    return 0;
}
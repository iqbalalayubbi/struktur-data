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
        cout << "Belum ada buku yang dimasukkan" << endl;
    }
}

void popBook(){
    if (!isEmpty()){
        top--;
        cout << "Buku " << books[top] << " berhasil dihapus" << endl;
    }else{
        cout << "Belum ada buku yang dimasukkan" << endl;
    }
}

void clearAllBook(){
    top = -1;
    cout << "Semua buku telah dihapus" << endl;
}

void peekBook(){
    if (!isEmpty()){
        cout << books[top] << " Berada paling atas" << endl; 
    }else{
        cout << "Belum ada buku yang dimasukkan" << endl;
    }
}

void getBooks(){
    if (!isEmpty()){
        for(int i=0; i<=top; i++){
            cout << "Buku ke-" << i+1 << endl;
            cout << "Judul buku : "<< books[i] << endl;
        }

    }else{
        cout << "Belum ada buku yang dimasukkan" << endl;
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

    // execute command
    // g++ stack.cpp -o stack && .\stack
    return 0;
}

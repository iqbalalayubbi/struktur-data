#include <iostream>

using namespace std;

const int MAX_QUEUE = 5;
string mahasiswa[MAX_QUEUE];
int tail = -1;
int front = -1;

int isEmpty(){
    return tail == -1;
}

int isFull(){
    return tail == MAX_QUEUE-1;
}

void insertMhs(string nama){
    if(isEmpty()){
        front = 0;
    }

    if (isFull()){
        cout << "Antrian Mahasiswa telah penuh" << endl;
    }else{
        tail++;
        cout << "Mahasiswa " << nama << " telah masuk antrian" << endl;
        mahasiswa[tail] = nama;
    }
}

void removeMhs(){
    if (!isEmpty()){
        cout << "mahasiswa " << mahasiswa[front] << " telah keluar dalam antrian" << endl;
        for(int i=0; i<tail; i++){
            mahasiswa[front+i] = mahasiswa[i+1];
        }
        tail--;
    }else{
        cout << "Antrian masih kosong" << endl;
    }
}

void removeAllMhs(){
    if(!isEmpty()){
        front = -1;
        tail = -1;
        cout << "Antrian telah kosong kembali" << endl;
    }else{
        cout << "Antrian masih kosong" << endl;
    }
}

void getFirstMhs(){
    if (!isEmpty()){
        cout << "mahasiswa " << mahasiswa[front] << " berada paling depan" << endl;
    }else{
        cout << "Antrian masih kosong" << endl;
    }
}

void getLastMhs(){
    if (!isEmpty()){
        cout << "mahasiswa " << mahasiswa[tail] << " berada paling belakang" << endl;
    }else{
        cout << "Antrian masih kosong" << endl;
    }
}

void getTotalMhs(){
    if (!isEmpty()){
        cout << "ada " << tail+1 << " mahasiswa dalam antrian" << endl;
    }else{
        cout << "Antrian masih kosong" << endl;
    }
}

void getAllMhs(){
    if (!isEmpty()){
        for (int i=0; i<tail+1; i++){
            cout << "Mahasiswa ke-" << i+1 << endl;
            cout << "Nama\t: " << mahasiswa[i] << endl;
        }

    }else{
        cout << "Antrian masih kosong" << endl;
    }
}

int main(){
    insertMhs("iqbal");
    insertMhs("hafiz");
    insertMhs("ryan");
    insertMhs("danu");
    insertMhs("perdi");
    cout << endl;

    getAllMhs();
    cout << endl;

    removeMhs();
    cout << endl;
    
    getFirstMhs();
    cout << endl;

    getLastMhs();
    cout << endl;

    getTotalMhs();
    cout << endl;

    removeAllMhs();
    cout << endl;

    getTotalMhs();
    cout << endl;

    // execute command
    // g++ queue.cpp -o queue && .\queue
    
    return 0;
}
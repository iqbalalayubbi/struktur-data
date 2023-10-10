#include <iostream>

using namespace std;

struct Mahasiswa{
  char nim[10];
  char nama[10];
  int nilai;

};

int main() {
  Mahasiswa mhs[10];

  int i = 0;
  int n = 0;

  cout << "masukkan jumlah data: ";
  cin >> n;

  for (i=1; i<=n; i++){
    cout << "\n" << "nim = ";
    cin >> mhs[i].nim ;
    cout << "nama = ";
    cin >> mhs[i].nama ;
    cout << "nilai = ";
    cin >> mhs[i].nilai ;
    cout << "\n";
  }
  for (i=1; i<=n; i++){
    cout << "\n" << "nim = " << mhs[i].nim;
    cout << "\n" << "nama = " << mhs[i].nama;
    cout << "\n" << "nilai = " << mhs[i].nilai;
    cout << "\n";
  }
  
}
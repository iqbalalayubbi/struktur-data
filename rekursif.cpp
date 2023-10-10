#include <iostream>

using namespace std;
int perkalian(int a, int b) {
  if (a <= 1) {
    return b;
  } else {
    return perkalian(a - 1, b) + b;
  }
}

int pembagian(int a, int b, int i=0) {
  if (b >= a) {
    return a;
  } else {
    return pembagian(a-b, b, i++);
  }
}

int pangkat(int a, int b){
  if (b == 1){
    return a;
  }else{
    return a*pangkat(a,b-1);
  }
}

int fibo(int n){
  if (n <= 1){
    return n;
  }
  return fibo(n-1) + fibo(n-2);
}

int faktorial(int n){
  if (n == 1){
    return 1;
  }
  return n*faktorial(n-1);
}


int main() {
  cout << "Hasil perkalian\t= " << perkalian(25,5) << endl;
  cout << "Hasil pembagian\t= " << pembagian(25, 5) << endl;
  cout << "Hasil pangkat\t= " << pangkat(2, 4) << endl;
  cout << "Hasil fibonaci\t= " << fibo(6) << endl;
  cout << "Hasil faktorial\t= " << faktorial(5) << endl;
  return 0;
}
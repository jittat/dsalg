#include <iostream>

using namespace std;

template <class T> 
void myswap(T& a, T& b)
{
  T temp = a;
  a = b;
  b = temp;
}

int main()
{
  int a = 10; int b = 100;
  myswap(a,b);
  cout << a << " " << b << endl;
  double ad = 10.7; double bd = 112.233;
  myswap(ad,bd);
  cout << ad << " " << bd << endl;
}

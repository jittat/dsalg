#include <iostream>

using namespace std;

int find_max_index(int x[], int n) 
{
  int mx = x[0];
  int mi = 0;
  for(int i=1; i<n; ++i)
    if(x[i] > mx) {
      mi = i;
      mx = x[i];
    }
  return mi;
}

void sort(int x[], int n)
{
  if(n<=1)
    return;
  int maxi = find_max_index(x,n);
  swap(x[n-1],x[maxi]);
  sort(x,n-1);
}

main()
{
  int a[] = {1,2,4,3,7,5,6,4,3,8,64,3,2,4,5,7};
  int n = 16;
  sort(a,n);
  for(int i=0; i<n; ++i)
    cout << a[i] << endl;
}

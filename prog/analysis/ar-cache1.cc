#include <iostream>

const int n = 10000;

int ar[n][n];

void init()
{
  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      ar[i][j] = i + j;
}

int cal(int c)
{
  int x = c;
  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      x += ar[i][j] + c;
  return x;
}

main()
{
  init();
  for(int i = 0; i < 10; i++)
    std::cout << cal(i) << std::endl;
}

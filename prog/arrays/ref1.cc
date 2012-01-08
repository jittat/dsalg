#include <iostream>

void m1(int a, int b)
{
  b += a;
}

void m2(int a, int& b)
{
  b += a;
}

main()
{
  int x = 10;
  int y = 100;
  m1(x,y);            // (3)
  std::cout << x << " " << y << std::endl;
  m2(x,y);            // (4)
  std::cout << x << " " << y << std::endl;
}

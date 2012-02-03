#include <iostream>

using namespace std;

class counter {
  int c;
public:
  counter(int z=0)
    :c(z) {}
  void inc() { ++c; }
  int get() { return c; }
};

main()
{
  counter a, b(10);
  cout << a.get() << endl;    // outputs 0
  b.inc(); a.inc();
  cout << b.get() << endl;    // outputs 11
  cout << a.get() << endl;    // outputs 1
}

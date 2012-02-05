#include <iostream>

using namespace std;

const int max_list_size = 1000;

class list {
public:
  typedef int* iterator;

  list()
    : size_(0) {}

  int size() { return size_; }
  iterator begin() { return &items_[0]; }
  iterator end() { return &items_[size_]; }

  iterator find(int x);
  iterator append(int x);
  void del(iterator p);
  void insert_after(iterator p, int x);

private:
  int items_[max_list_size];
  int size_;
};

void print(list& lst)
{
  for(list::iterator i = lst.begin();
      i != lst.end(); i++)
    cout << *i << ", ";
  cout << endl;
}

list::iterator list::append(int v)
{
  if(size_ >= max_list_size)
    throw "List overflow";
  items_[size_] = v;
  ++size_;
  return &items_[size_ - 1];
}

int main()
{
  list a, b;

  a.append(1);
  a.append(2);
  cout << a.size() << endl;
  b.append(100);
  b.append(101);
  b.append(12);
  b.append(133);
  print(a);
  print(b);
}

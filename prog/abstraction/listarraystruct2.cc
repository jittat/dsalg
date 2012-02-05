#include <iostream>
using namespace std;

const int max_list_size = 10000;

struct list {
  int items[max_list_size];
  int size;

  typedef int* iterator;

  void init() { size = 0; }
  iterator begin() { return &items[0]; }
  iterator end() { return &items[size]; }
  iterator find(int x);
  iterator append(int x);
  void del(iterator p);
  void insert_after(iterator p, int x);
};

list::iterator list::find(int x)
{
  for(int i = 0; i < size; ++i)
    if(items[i] == x)
      return &items[i];
  return end();
}

list::iterator list::append(int v)
{
  if(size >= max_list_size)
    throw "List overflow";
  items[size] = v;
  ++size;
  return &items[size-1];
}

int main()
{
  list lst;
  lst.init();
  lst.append(10);  lst.append(30);  lst.append(20);
  if(lst.find(5) != lst.end())  // find 5 in list
    cout << "found" << endl;
  else
    cout << "not found" << endl;

  for(list::iterator i = lst.begin();
      i != lst.end(); i++)
    cout << *i << ", ";
  cout << endl;

  cout << lst.find(5) << endl;
  cout << lst.find(10) << endl;
  cout << lst.find(15) << endl;
  cout << lst.find(20) << endl;
}

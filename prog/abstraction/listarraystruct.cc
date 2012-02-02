#include <iostream>
using namespace std;

const int max_list_size = 10000;

struct list {
  int items[max_list_size];
  int size;
};

typedef int* list_itr;

void list_init(list& l)
{
  l.size = 0;
}

list_itr list_itr_end(list& l)
{
  return &l.items[l.size];
}

list_itr list_find(list& l, int x)
{
  for(int i = 0; i < l.size; ++i)
    if(l.items[i] == x)
      return &l.items[i];
  return list_itr_end(l);
}

list_itr list_append(list& l, int v)
{
  if(l.size >= max_list_size)
    throw "List overflow";
  l.items[l.size] = v;
  ++l.size;
  return &l.items[l.size-1];
}

main()
{
  list ll;
  list_init(ll);
  list_append(ll,10);
  list_append(ll,30);
  list_append(ll,20);
  cout << list_find(ll,5) << endl;
  cout << list_find(ll,10) << endl;
  cout << list_find(ll,15) << endl;
  cout << list_find(ll,20) << endl;
}

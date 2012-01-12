#include <iostream>

using namespace std;

const int max_size = 10000;

int list[max_size];
int list_size;

void list_init(int list[], int& size)
{
  size = 0;
}

int list_find(int list[], int size, int q)
{
  for(int i = 0; i < size; i++)
    if(list[i] == q)
      return i;
  return -1;
}


void list_append(int list[], int& size, int val)
{
  if(size >= max_size)
    throw "List overflow";
  list[size] = val;
  size++;
}

void list_delete(int list[], int& size, int i)
{
  if((i < 0) || i >= size)
    throe "Index not valid";
  for(int j = i; j < n-1; j++)
    list[j] = list[j+1];
  size--;
}

void list_delete_all_data(int list[], int& size, int x)
{
  int os;
  do {
    os = size;
    list_delete_data(list, size, x);
  } while(os != size);
}

void print_list(int list[], int& size)
{
  for(int i=0; i<size; i++)
    cout << list[i] << " ";
  cout << endl;
}

main()
{
  list_init(list, list_size);
  print_list(list, list_size);
  list_append(list, list_size, 10);
  list_append(list, list_size, 100);
  print_list(list, list_size);
  list_append(list, list_size, 1000);
  list_append(list, list_size, 10000);
  print_list(list, list_size);
  cout << list_find(list, list_size, 9) << endl;
  cout << list_find(list, list_size, 10) << endl;
  cout << list_find(list, list_size, 900) << endl;
  cout << list_find(list, list_size, 1000) << endl;
  cout << list_find(list, list_size, 10000) << endl;
}

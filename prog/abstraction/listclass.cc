#include <iostream>

using namespace std;

class list {
public:
  typedef int* iterator;

  list(int max_size=default_max_list_size);
  ~list();

  list(const list& l);
  list& operator=(const list& l);

  int size() { return size_; }
  iterator begin() { return &items_[0]; }
  iterator end() { return &items_[size_]; }

  iterator find(int x);
  iterator append(int x);
  void del(iterator p);
  void insert_after(iterator p, int x);

private:
  enum { default_max_list_size = 1000 };

  int* items_;
  int size_;
  int max_size_;

  void copy_from(const list& l);
};

list::list(int max_size)
  : size_(0), max_size_(max_size) 
{
  items_ = new int[max_size_];
  cout << "Constructor called" << items_ << endl;
}

list::~list()
{
  cout << "Destructor called" << items_ << endl;
  delete [] items_;
}

void print(list& lst)
{
  for(list::iterator i = lst.begin();
      i != lst.end(); i++)
    cout << *i << ", ";
  cout << endl;
}

list::iterator list::append(int v)
{
  if(size_ >= max_size_)
    throw "List overflow";
  items_[size_] = v;
  ++size_;
  return &items_[size_ - 1];
}

void list::copy_from(const list& l)
{
  size_ = l.size_;
  max_size_ = l.max_size_;
  items_ = new int[max_size_];
  for(int i=0; i<size_; ++i)
    items_[i] = l.items_[i];
}

list::list(const list& l)
{
  cout << "copy cons called." << endl;
  copy_from(l);
}

list& list::operator=(const list& l)
{
  if(this == &l)
    return *this;

  delete [] items_;
  copy_from(l);
  return *this;
}

void m(list a) { cout << a.size() << endl; }

int main()
{
  list b;
  m(b);
  list a;
  a = b;

  cout << list::default_max_list_size << endl;
  /*
  for(int i=0; i<2000; ++i) {
    a.append(i);
    b.append(i);
  }

  a.append(1);
  a.append(2);
  cout << a.size() << endl;
  b.append(100);
  b.append(101);
  b.append(12);
  b.append(133);
  print(a);
  print(b);
  */
}

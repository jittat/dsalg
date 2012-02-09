#include <iostream>

using namespace std;

template<class T>
class list {
public:
  typedef T* iterator;

  list(int max_size=default_max_list_size);
  ~list();

  list(const list& lst);
  list& operator=(const list& lst);

  int size() { return size_; }
  iterator begin() { return &items_[0]; }
  iterator end() { return &items_[size_]; }

  iterator find(T x);
  iterator append(T x);
  void del(iterator p);
  void insert_after(iterator p, T x);

private:
  enum { default_max_list_size = 1000 };

  T* items_;
  int size_;
  int max_size_;

  void copy_from(const list& lst);
};

template<class T>
list<T>::list(int max_size)
  : size_(0), max_size_(max_size) 
{
  items_ = new T[max_size_];
  cout << "Constructor called" << items_ << endl;
}

template<class T>
list<T>::~list()
{
  cout << "Destructor called" << items_ << endl;
  delete [] items_;
}

template<class T>
void print(list<T>& lst)
{
  for(typename list<T>::iterator i = lst.begin();
      i != lst.end(); i++)
    cout << *i << ", ";
  cout << endl;
}

template<class T>
typename list<T>::iterator list<T>::append(T v)
{
  if(size_ >= max_size_)
    throw "List overflow";
  items_[size_] = v;
  ++size_;
  return &items_[size_ - 1];
}

template<class T>
typename list<T>::iterator list<T>::find(T v)
{
  for(list<T>::iterator i = begin();
      i != end(); ++i)
    if(*i == v)
      return i;
  return end();
}

template<class T>
void list<T>::copy_from(const list& lst)
{
  size_ = lst.size_;
  max_size_ = lst.max_size_;
  items_ = new int[max_size_];
  for(int i=0; i<size_; ++i)
    items_[i] = lst.items_[i];
}

template<class T>
list<T>::list(const list& lst)
{
  cout << "copy cons called." << endl;
  copy_from(lst);
}

template<class T>
list<T>& list<T>::operator=(const list<T>& lst)
{
  if(this == &lst)
    return *this;

  delete [] items_;
  copy_from(lst);
  return *this;
}

void m(list<int> a) { cout << a.size() << endl; }

int main()
{
  list<int> b;
  m(b);
  list<int> a;
  a = b;

  for(int i=0; i<200; ++i) {
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

  cout << a.find(10000) << endl;
  cout << a.find(10) << endl;

}

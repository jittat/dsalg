template<class T>
class stack {
public:
  stack() : top_(-1) {}
  T top() { return items_[top_]; }
  T pop();
  void push(T x);
  bool empty() { return top_ < 0; }
  int size() { return top_ + 1; }
private:
  enum { max_size_ = 1000 };
  T items_[max_size_];
  int top_;
};

template<class T>
void stack<T>::push(T x)
{
  ++top_;
  items_[top_] = x;
}

template<class T>
T stack<T>::pop()
{
  T t = top();
  --top_;
  return t;
}

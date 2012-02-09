#include <iostream>
#include <cassert>

#include "stack"

void test_dd()
{
  stack<double> s;
  
  s.push(10);  s.push(20);  s.push(100);
  assert(s.size()==3);
  assert(s.pop()==100);
  assert(s.size()==2);
  assert(s.top()==20);
  assert(s.pop()==20);
  s.push(1000);
  assert(s.pop()==1000);
  assert(s.empty()==false);
  assert(s.pop()==10);
  assert(s.empty()==true);
}

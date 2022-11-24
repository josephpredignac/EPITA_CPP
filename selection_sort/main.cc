// Do not change me

#include <iostream>

#include <list>
#include <vector>
#include <deque>

#include <string>

#include "my_sort.hpp"

template<class CONT>
void print_me(const CONT& c)
{
  for (auto v : c)
    {
      std::cout << v;
      std::cout.put(' ');
    }
  std::cout.put('\n');
}

template<class CONT, class T>
void test(const std::vector<T>& v)
{
  // Copy data into a CONT
  auto c = CONT(v.cbegin(), v.cend());

  my_selection_sort(c.begin(), c.end());
  print_me(c);
}


template<class CONT>
void test(const CONT& v)
{
  std::cout << "Original data\n";
  print_me(v);

  std::cout << "Sorted from list\n";
  // typename here is necessary as it is a "dependent time"
  // it depends on CONT, this needs to be marked explicitely
  test<std::list<typename CONT::value_type>>(v);
  std::cout << "Sorted from vector\n";
  test<std::vector<typename CONT::value_type>>(v);
  std::cout << "Sorted from deque\n";
  test<std::deque<typename CONT::value_type>>(v);
}

void test_int()
{
  auto v = std::vector{9,5,3,2,6,6};
  test(v);
}

void test_str()
{
  auto v = std::vector<std::string>{"z","x","a","aba","c","c","uzm"};
  test(v);
}

int main()
{
  test_int();
  test_str();
  return 0;
}

// Do not change
#include <iostream>
#include <fstream>


#include <list>
#include <vector>
#include <deque>

#include "../selection_sort/my_sort.hpp"

template<class it, class C>
void read_file_to_cont(std::ifstream& f, C& c) {
    it a;
    while (f >> a)
        c.push_back(a);
}

template<class it, class C>
void read_and_sort(std::ifstream& fi, std::ofstream& fo) {
    C c = {};
    read_file_to_cont<it, C>(fi, c);
    my_selection_sort(c.begin(), c.end());
    for (auto &i : c)
        fo << i << std::endl;
}

template<class it>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo) {
  char cont_type;
  fi >> cont_type;
  fo << cont_type << std::endl;
  switch (cont_type)
  {
    case 'l':
      read_and_sort<it, std::list<it>>(fi, fo);
      break;
    case 'v':
      read_and_sort<it, std::vector<it>>(fi, fo);
      break;
    case 'd':
      read_and_sort<it, std::deque<it>>(fi, fo);
      break;
    default:
      throw std::runtime_error("Unknown container");
  }
}

void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo) {
  char val_type;
  fi >> val_type;
  fo << val_type << std::endl;
  switch(val_type)
  {
    case 'i':
      read_and_sort_decide_container<int>(fi, fo);
      break;
    case 'u':
      read_and_sort_decide_container<unsigned>(fi, fo);
      break;
    case 'f':
      read_and_sort_decide_container<float>(fi, fo);
      break;
    case 'd':
      read_and_sort_decide_container<double>(fi, fo);
      break;
    case 'c':
      read_and_sort_decide_container<char>(fi, fo);
      break;
    case 's':
      read_and_sort_decide_container<std::string>(fi, fo);
      break;
    default:
      throw std::runtime_error("Unknown value");
  }
}

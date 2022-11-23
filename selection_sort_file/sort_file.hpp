// Do not change
#include <iostream>
#include <fstream>


#include <list>
#include <vector>
#include <deque>

#include "../selection_sort/my_sort.hpp"

// Change here
// All occurences of XXX need to be replaced with
// something more meaningful


template <typename File, typename Cont, typename Type>
void read_file_to_cont(File& f, Cont &c) 
{
  Type tmp;
  while (f >> tmp) {
    c.push_back(tmp);
  }
}

template <typename IStream, typename OStream, typename Cont, typename Type>
void read_and_sort(IStream& fi, OStream& fo) {
  Cont container;
  read_file_to_cont<IStream, Cont, Type>(fi, container);

  my_selection_sort(container.begin(), container.end());

  for (Cont::iterator x = container.begin(); x != container.end(); x++)
    fo << *x << std::endl;
}

template <typename IStream, typename OStream, typename Type>
void read_and_sort_decide_container(IStream& fi, OStream& fo) {
  char containerType;

  fi >> containerType;
  switch(containerType)
  {
    case 'l':
      fo << 'l' << std::endl;
      read_and_sort<IStream, OStream, typename std::list<Type>, Type>(fi, fo);
      break;
    case 'v':
      fo << 'v' << std::endl;
      read_and_sort<IStream, OStream, typename std::vector<Type>, Type>(fi, fo);
      break;
    case 'd':
      fo << 'd' << std::endl;
      read_and_sort<IStream, OStream, typename std::deque<Type>, Type>(fi, fo);
      break;
    default:
      break;
  }
}

template <typename IStream, typename OStream>
void read_and_sort_decide_valuetype(IStream& fi, OStream& fo) {
  char valueType;

  fi >> valueType;
  switch(valueType)
  {
    case 'i':
      fo << 'i' << std::endl;
      read_and_sort_decide_container<IStream, OStream, int>(fi, fo);
      break;
    case 'u':
      fo << 'u' << std::endl;
      read_and_sort_decide_container<IStream, OStream, unsigned int>(fi, fo);
      break;
    case 'f':
      fo << 'f' << std::endl;
      read_and_sort_decide_container<IStream, OStream, float>(fi, fo);
      break;
    case 'd':
      fo << 'd' << std::endl;
      read_and_sort_decide_container<IStream, OStream, double>(fi, fo);
      break;
    case 'c':
      fo << 'c' << std::endl;
      read_and_sort_decide_container<IStream, OStream, char>(fi, fo);
      break;
    case 's':
      fo << 's' << std::endl;
      read_and_sort_decide_container<IStream, OStream, std::string>(fi, fo);
      break;
    default:
      break;
  }
}




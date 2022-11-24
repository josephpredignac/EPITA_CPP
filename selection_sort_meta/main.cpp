// Do not change me

#include <iostream>

#include <string>

#include "sort_file.hpp"


int main(int argc, char *argv[]) {
	if (argc != 2)
		throw std::runtime_error("Expected input filename as argument");

	std::ifstream fi(argv[1]);
  if (!fi)
		throw std::runtime_error("Expected input filename as argument");

  std::ofstream fo("sorted_values.txt");
  if (!fo)
		throw std::runtime_error("Unable to open output");

  read_and_sort_decide_valuetype(fi, fo);

  return 0;
}
// vector-test.cc
#include <iostream>

#include "vector.hh"

#include <vector>
#include <cstring> //strcmp

#if NDIM == 2
void testInit()
{
    auto u = Vector{};
    // This needs an constructor accepting a std::initializer_list
    auto v = Vector{ 4, 7 };
    auto t = Vector{ -1, 6 };

    std::cout << u + v << '\n'; // {4,7}
    u += Vector{ 1, 8 };
    std::cout << u << '\n'; // {1,8}
    t -= u;
    std::cout << t << '\n'; // {-2,-2}
    std::cout << t * 3 << '\n'; // {-6,-6}
    std::cout << u * v << '\n'; // 60

}
#elif NDIM == 3
void testInit()
{
    auto u = Vector{};
    // This needs an constructor accepting a std::initializer_list
    auto v = Vector{ 4, 7, -1 };
    auto t = Vector{ -1, 6, 77 };

    std::cout << u + v << '\n'; // {4,7,-1}
    u += Vector{ 1, 8, -11 };
    std::cout << u << '\n'; // {1,8,-11}
    t -= u;
    std::cout << t << '\n'; // {-2,-2,88}
    std::cout << t * 3 << '\n'; // {-6,-6,264}
    std::cout << u * v << '\n'; // 71
}
#else
void testInit()
{
  auto u = Vector{};
  for (size_t i = 0; i < NDIM; ++i)
    u[i] = i;
  std::cout << u;
  std::cout.put('\n');
}
#endif


std::vector<Vector>
generate(size_t n)
{
    auto v = std::vector<Vector>(n);
    // Set some values
    for (size_t i = 0; i < NDIM; ++i)
        {
            for (size_t j = 0; j < n; ++j)
                {
                    auto& vv = v[j]; // Reference to one of your Vectors
                    vv[i] = (value) i+j;
                }
        }
    return v;
}

// Takes the number of Vectors used as an argument
void testAdd(size_t n)
{
    auto vv = generate(n);

    // Add to each Vector his right neighbour
    for (size_t i = 1; i < n; ++i)
        vv[i-1] += vv[i];
    // Sum them up
    auto sum = Vector(); // Expected to be all zeros
    for (const auto& other : vv)
        sum = sum + other;
    // Print for verif
    std::cout << sum << '\n';
}

// Takes as input the number of vectors
// As well a as a list of actions to perform
// scaling and offset will use two arguments from argv,
// all others will be performed on two neighbouring elements
// In the end a pairwise dot-product is calculated and summed up for all
void testVar(size_t n, int argc, char* argv[])
{
    if (n&1)
        throw std::runtime_error("Need an even number of elements.");

    auto v = generate(n);
    for (int idx = 0; idx < argc; ++idx)
        {
            if (std::strcmp(argv[idx], "add") == 0)
                {
                    for (size_t i = 1; i < n; ++i)
                        v[i-1] += v[i];
                }
            else if (std::strcmp(argv[idx], "scale") == 0)
                {
                    ++idx;
                    auto s = (value) std::atoll(argv[idx]);
                    for (auto& vv : v)
                        vv *= s;
                }
            else if (std::strcmp(argv[idx], "offset") == 0)
                {
                    ++idx;
                    auto s = (value) std::atoll(argv[idx]);
                    for (auto& vv : v)
                        vv += s;
                }

        }
    value sum = 0;
    for (size_t i = 1; i < n; i += 2)
        sum += v[i-1]*v[i];
    std::cout << sum;
    std::cout.put('\n');
}




int main(int argc, char* argv[])
{
    if (argc <= 2)
        throw std::runtime_error("Expects: first arg, number of elements, "
                                 "other args, instructions to run");
    size_t n_elem = std::atol(argv[1]);
    if (std::strcmp(argv[2], "testInit") == 0)
        testInit();
    else if (std::strcmp(argv[2], "testAdd") == 0)
        testAdd(n_elem);
    else
        testVar(n_elem, argc - 2, &(argv[2]));

    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(int ac, char **av)
{
    std::int16_t comptage = 0;
    std::string c;
    std::vector<std::string> w;
    std::ifstream f;

    if (ac != 3)
        return EXIT_FAILURE;

    const std::string m(av[2]);
    f.open(av[1]);

    if (!f.is_open()) {
        std::cerr << "The file " << av[1] << " could not be opened." << std::endl;
        return EXIT_FAILURE;
    }

    while (f >> c)
        w.push_back(c);

    std::for_each(w.begin(), w.end(), [&comptage, &m] (const std::string &mot) {
        if (mot.find(m) != std::string::npos)
            comptage += 1;
    });

    std::cout << "The file " << av[1] << " contains " << comptage << " words containing the motive " << m << std::endl;

    return EXIT_SUCCESS;
}

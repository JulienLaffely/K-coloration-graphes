#include "graphes.hpp"

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        std::cerr << "Wrong number of parameters." << std::endl;
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 0;
    }
    Graph G;
    G.read_dimacs(argv[1]);
    G.k_couleurs();                  // Methode k_colors minimal
    G.print();
    G.write_dot();
}

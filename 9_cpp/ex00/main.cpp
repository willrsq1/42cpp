#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) 
{

    if (argc != 2) 
    {
        std::cerr << "Usage: " << argv[0] << " inputFile" << std::endl;
        return 1;
    }

    BitcoinExchange bitcoinExchange;
    bitcoinExchange.execution(argv[1]);

    return 0;
}

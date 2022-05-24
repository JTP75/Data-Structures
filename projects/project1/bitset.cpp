#include "bitset.hpp"

Bitset::Bitset()
{
    size = 8;
    ADTPtr = new uint8_t[size];

    for(intmax_t i=0; i<size; i++)
        *(ADTPtr+i) = 0;
}
Bitset::Bitset(intmax_t sz)
{
    if(sz > 0)
    {
        size = sz;
        ADTPtr = new uint8_t[size];
        for(intmax_t i=0; i<size; i++)
            *(ADTPtr+i) = 0;
    }
    else
    {
        std::cout << "ERROR! Invalid Bitset size";
        exit(EXIT_FAILURE);
    }
}
Bitset::Bitset(const std::string &value)
{
    size = value.length();
    ADTPtr = new uint8_t[size];
    std::vector<uint8_t> valVec(value.begin(), value.end());

    for(intmax_t i=0; i<size; i++)
    {
        if(value[i] != 1 && value[i] != 0)
        {
            std::cout << "ERROR! Input string contains invalid bits";
            exit(EXIT_FAILURE);
        }
        *(ADTPtr+i) = valVec[i];
    }
}
Bitset::~Bitset()
{
    
}


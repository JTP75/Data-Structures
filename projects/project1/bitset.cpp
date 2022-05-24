#include "bitset.hpp"

Bitset::Bitset()
{
    size = 8;
    for(intmax_t i=0; i<size; i++)
        *(ADTPtr+i) = 0;
}
Bitset::Bitset(intmax_t sz)
{

}
Bitset::Bitset(const std::string & value)
{
    
}
Bitset::~Bitset()
{
    
}


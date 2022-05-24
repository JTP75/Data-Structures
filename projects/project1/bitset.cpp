#include "bitset.hpp"

Bitset::Bitset()
{
    BSsize = 8;
    ADTPtr = new uint8_t[BSsize];
    isValid = true;

    for(intmax_t i=0; i<BSsize; i++)
        *(ADTPtr+i) = 0;
}
Bitset::Bitset(intmax_t sz)
{
    isValid = sz > 0;
    BSsize = sz;
    ADTPtr = new uint8_t[BSsize];
    for(intmax_t i=0; i<BSsize; i++)
        *(ADTPtr+i) = 0;
}
Bitset::Bitset(const std::string &value)
{
    BSsize = value.length();
    ADTPtr = new uint8_t[BSsize];
    isValid = true;
    const uint8_t* tmpPtr = reinterpret_cast<const uint8_t*>(value.c_str());
    for(intmax_t i=0; i<BSsize; i++)
    {
        isValid = isValid && (value[i]==1 || value[i]==0);
        *(ADTPtr+i) = *(tmpPtr+i);
    }
}
Bitset::~Bitset()
{
    
}
intmax_t Bitset::size() const {return BSsize;}
bool Bitset::good() const {return isValid;}
void Bitset::set(intmax_t index)
{
    isValid = isValid && (index >= 0 || index < BSsize);    // invalid bitsets can not become valid.
    *(ADTPtr+index) = 1;
}
void Bitset::reset(intmax_t index)
{
    isValid = isValid && (index >= 0 || index < BSsize);
    *(ADTPtr+index) = 0;
}
void Bitset::toggle(intmax_t index)
{
    isValid = isValid && (index >= 0 || index < BSsize);
    *(ADTPtr+index) = *(ADTPtr+index)==1 ? 0 : 1;
}
bool Bitset::test(intmax_t index)
{
    isValid = isValid && (index >= 0 || index < BSsize);
    return isValid && *(ADTPtr+index)==1;
}
std::string Bitset::asString() const
{
    std::string s = "";
    for(intmax_t i=0; i<BSsize; i++)
        s += std::to_string(*(ADTPtr+i));
    return s;
}











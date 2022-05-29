#include "bitset.hpp"
#include <cmath>

Bitset::Bitset()
{
    BSsize = 8;
    ADTPtr = new uint8_t[1];
    isValid = true;
    *ADTPtr = 0;
}
Bitset::Bitset(intmax_t sz)
{
    isValid = sz > 0;
    if(isValid){
        BSsize = sz;
        intmax_t UIsize = (BSsize-1) / 8 + 1;           // uint for storing 
        ADTPtr = new uint8_t[UIsize];
        for(intmax_t i=0; i<UIsize; i++)
            *(ADTPtr+i) = 0;
    }
}
Bitset::Bitset(const std::string &value)        // 005 193 131 065
{
    BSsize = value.length();
    intmax_t UIsize = (BSsize-1) / 8 + 1;
    ADTPtr = new uint8_t[UIsize];
    isValid = true;

    for(intmax_t i=0; i<UIsize; i++)
        *(ADTPtr+i) = 0;

    for(intmax_t i = 0; i < 8*UIsize; i++)
    {
        if(i >= 8-((BSsize-1)%8 + 1)) 
        {
            int thisVal = value[i + (BSsize-1)%8 - 7] - 48;
            isValid = isValid && (thisVal == 0 || thisVal == 1);
            *(ADTPtr+i/8) += thisVal * std::pow(2,7-i%8);
        }
    }
}
Bitset::~Bitset(){delete [] ADTPtr;}
intmax_t Bitset::size() const {return BSsize;}
bool Bitset::good() const {return isValid;}
void Bitset::set(intmax_t index)
{
    isValid = isValid && (index >= 0 || index < BSsize);
    intmax_t UIsize = (BSsize-1) / 8 + 1;
    std::string bitString = asString();
    bitString.replace(index,1,"1");
    for(intmax_t i = 0; i < UIsize; i++)
        *(ADTPtr+i) = 0;

    for(intmax_t i = 0; i < 8*UIsize; i++)
    {
        if(i >= 8-((BSsize-1)%8 + 1)) 
        {
            int thisVal = bitString[i + (BSsize-1)%8 - 7] - 48;
            *(ADTPtr+i/8) += thisVal * std::pow(2,7-i%8);
        }
    }
}
void Bitset::reset(intmax_t index)
{
    isValid = isValid && (index >= 0 || index < BSsize);
    intmax_t UIsize = (BSsize-1) / 8 + 1;
    std::string bitString = asString();
    bitString.replace(index,1,"0");
    for(intmax_t i = 0; i < UIsize; i++)
        *(ADTPtr+i) = 0;

    for(intmax_t i = 0; i < 8*UIsize; i++)
    {
        if(i >= 8-((BSsize-1)%8 + 1)) 
        {
            int thisVal = bitString[i + (BSsize-1)%8 - 7] - 48;
            *(ADTPtr+i/8) += thisVal * std::pow(2,7-i%8);
        }
    }
}
void Bitset::toggle(intmax_t index)
{
    if(test(index)) reset(index);
    else set(index);
}
bool Bitset::test(intmax_t index)
{
    isValid = isValid && (index >= 0 || index < BSsize);
    std::string bitString = asString();
    return isValid && bitString[index]=='1';
}
std::string Bitset::asString() const
{
    intmax_t UIsize = (BSsize-1) / 8 + 1;
    std::string returnString = "";

    for(intmax_t i = 0; i < UIsize; i++)
    {
        uint8_t thisVal = *(ADTPtr+i);
        if(i == 0 && BSsize%8 != 0)
        {
            std::string s = "";
            for(int j = BSsize%8 - 1; j >= 0; j--)
            {
                s = std::to_string(thisVal%2) + s;
                thisVal /= 2;
            }
            returnString += s;
        }
        else
        {
            std::string s = "";
            for(int j = 7; j >= 0; j--)
            {
                s = std::to_string(thisVal%2) + s;
                thisVal /= 2;
            }
            returnString += s;
        }
    }
    return returnString;
}




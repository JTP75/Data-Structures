#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

class Bitset
{
  public:
    Bitset();
    Bitset(intmax_t sz);
    Bitset(const std::string &value);
    ~Bitset();
    Bitset & operator=(const Bitset &) = delete;
    intmax_t size() const;
    bool good() const;
    void set(intmax_t index);
    void reset(intmax_t index);
    void toggle(intmax_t index);
    bool test(intmax_t index);
    std::string asString() const;

  private:
    uint8_t *ADTPtr;
    intmax_t size;
};

#endif
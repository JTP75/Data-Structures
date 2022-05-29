#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <stdlib.h>
#include <string>

class Bitset
{
  public:
    Bitset();                                       // constructs and validates bitset of length 8
    Bitset(intmax_t sz);                            // constructs bitset of length sz, valid only if sz > 0
    Bitset(const std::string &value);               // reads string to ADT, checking for non-one-or-zero bits
    ~Bitset();                                      // deletes allocated memory and destroys object
    Bitset & operator=(const Bitset &) = delete;    // prohibits copying
    intmax_t size() const;                          // returns size
    bool good() const;                              // returns validity
    void set(intmax_t index);                       // sets value at index, invalid if index is out of bounds
    void reset(intmax_t index);                     // resets value at index, invalid if index is OOB
    void toggle(intmax_t index);                    // toggles value at index, invalid if index is OOB
    bool test(intmax_t index);                      // returns boolean state at index, invalid if index is OOB
    std::string asString() const;                   // returns string representation of bitset



  private:
    uint8_t *ADTPtr;                                // pointer to first uint8_t element of array
    intmax_t BSsize;                                // num of bits
    bool isValid;                                   // validity --- NOTE: invalid bitsets CANNOT become valid!
};

#endif
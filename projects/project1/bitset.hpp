#ifndef BITSET_HPP
#define BITSET_HPP
#include <string>

class Bitset{
public:

  // TODO COMMENT
  Bitset();

  // TODO COMMENT
  Bitset(intmax_t size);

  // TODO COMMENT
  Bitset(const std::string & value);

  // TODO COMMENT
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // TODO COMMENT
  intmax_t size() const;

  // TODO COMMENT
  bool good() const;

  // TODO COMMENT
  void set(intmax_t index);

  // TODO COMMENT
  void reset(intmax_t index);

  // TODO COMMENT
  void toggle(intmax_t index);

  // TODO COMMENT
  bool test(intmax_t index);

  // TODO COMMENT
  std::string asString() const;

private:

  // TODO
};

#endif

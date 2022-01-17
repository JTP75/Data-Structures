#ifndef STUDENT_ABSTRACT_OPERATOR_HPP
#define STUDENT_ABSTRACT_OPERATOR_HPP

#include <cstdlib>

template<typename T> class AbstractOperator{
public:

  AbstractOperator() {};
  
  virtual ~AbstractOperator() {};

  virtual T call(T arg1, T arg2) const = 0;

private:

};

#endif 
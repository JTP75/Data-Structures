#ifndef STUDENT_ADD_HPP
#define STUDENT_ADD_HPP

#include "abstract_operator.hpp"

template<typename T> class Add : public Abstract_Operator<T>{
public:

  Add();
  
  ~Add();

  T call(T arg1, T arg2) const;

private:

};

#include "add.tpp"

#endif 
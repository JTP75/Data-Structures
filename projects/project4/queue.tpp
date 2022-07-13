#include "queue.hpp"

using std::string;

template <typename T, typename L>
void Queue<T,L>::enqueue(const T& item)
{
  internal_list.insert(0,item);
}

template <typename T, typename L>
void Queue<T,L>::dequeue()
{
  if(isEmpty()){
    string desc = "Queue::dequeue() queue is empty";
    throw std::range_error(desc);
  }
  internal_list.remove(internal_list.getLength()-1);
}

template <typename T, typename L>
T Queue<T,L>::peekFront()
{
  if(isEmpty()){
    string desc = "Queue::dequeue() queue is empty";
    throw std::range_error(desc);
  }
  return internal_list.getEntry(internal_list.getLength()-1);
}

template <typename T, typename L>
bool Queue<T,L>::isEmpty() const
{
  return internal_list.isEmpty();
}


#include "frontier_queue.hpp"
using std::size_t;
using std::vector;

template <typename T> long swapParent(vector<State<T>> &q, size_t idx);
template <typename T> long swapSmaller(vector<State<T>> &q, size_t idx);

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {
  if(empty()){
    std::string desc = "frontier_queue<T>::pop(): queue is empty!";
    throw std::runtime_error(desc);
  }

  State<T> retval = queue[0];

  queue[0] = queue[queue.size()-1];
  queue.pop_back();

  long idx = 0;
  while(idx < queue.size())  // the new top value will always bubble down to bottom of heap (since it was at the bottom)
    idx = swapSmaller(queue, idx);   // returns queue.size() if there are no child states

  return retval;
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur)
{
  State<T> new_item = State<T>(p, cost, heur);

  long idx = queue.size();
  queue.push_back(new_item);

  while((idx-1)>>1 >= 0 && queue[(idx-1)>>1].getFCost() > new_item.getFCost())
    idx = swapParent(queue, idx);
}

template <typename T>
bool frontier_queue<T>::empty() {
  return queue.size()==0;
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {
  for(State<T> item : queue)
    if(item.getValue() == p)
      return true;
  return false;

}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) 
{
  long idx = -1;
  for(size_t i=0; i<queue.size(); i++)
    if(queue[i].getValue() == p){
      idx = i;
      break;
    }
  if(idx == -1 || queue[idx].getPathCost() <= cost)
    return;
  queue[idx].updatePathCost(cost);
  cost = queue[idx].getFCost();

  while((idx-1)>>1 >= 0 && queue[(idx-1)>>1].getFCost() > cost)
    idx = swapParent(queue, idx);

}

// swaps node at idx with its parent
template <typename T>
long swapParent(vector<State<T>> &q, size_t idx)
{
  if(idx >= q.size() || idx < 0){
    std::string desc = "swapParent(): position argument OOB!";
    throw std::out_of_range(desc);
  }
  size_t pdx = (idx-1)>>1;

  State<T> tmp = q[pdx];
  q[pdx] = q[idx];
  q[idx] = tmp;
  return pdx;
}

// swaps node at idx with its
template <typename T>
long swapSmaller(vector<State<T>> &q, size_t idx)
{
  if(idx >= q.size() || idx < 0){
    std::string desc = "swapEldest(): idx argument OOB!";
    throw std::out_of_range(desc);
  }

  size_t left = (idx<<1)+1;
  size_t right = (idx<<1)+2;

  if(left >= q.size())                              // case: no children
  {                   
    return q.size();
  }
  else if(right == q.size())                        // case: only child (always left)
  {                         
    if(q[left].getFCost() < q[idx].getFCost()){        // subcase: parent is bigger
      State<T> tmp = q[left];
      q[left] = q[idx];
      q[idx] = tmp;
      return left;
    }
    else{                                               // subcase: only child is bigger
      return q.size();
    }
  }
  else                                              // case: two children
  {   
    bool LC_bigger = q[left].getFCost() > q[idx].getFCost();
    bool RC_bigger = q[right].getFCost() > q[idx].getFCost();

    if(LC_bigger && RC_bigger){                         // subcase: both children bigger
      return q.size();
    }
    else if(LC_bigger && !RC_bigger){                   // subcase: left bigger, right smaller
      State<T> tmp = q[right];
      q[right] = q[idx];
      q[idx] = tmp;
      return right;
    }
    else if(!LC_bigger && RC_bigger){                   // subcase: left smaller, right bigger
      State<T> tmp = q[left];
      q[left] = q[idx];
      q[idx] = tmp;
      return right;
    }
    else{                                               // subcase: both children smaller than parent
      if(q[right].getFCost() < q[left].getFCost()){         // subsubcase: right < left
        State<T> tmp = q[right];
        q[right] = q[idx];
        q[idx] = tmp;
        return right;
      }
      else{                                                 // subsubcase: right > left
        State<T> tmp = q[left];
        q[left] = q[idx];
        q[idx] = tmp;
        return left;
      }
    }
    
      
  }

  
  return q.size();
}
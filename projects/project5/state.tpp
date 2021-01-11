#include "state.hpp"

template <typename T>
State<T>::State(const T &p, std::size_t cost, std::size_t heur)
    : value(p), g(cost), h(heur) {
  f = g + h;
}

template <typename T>
State<T>& State<T>::operator=(const State<T>& rhs)
{
	if (this != rhs)
	{
		value = rhs.value;
		g = rhs.g;
		h = rhs.h;
		f = rhs.f;
	}
	return *this;
}

template <typename T> T State<T>::getValue() const { return value; }

template <typename T> void State<T>::updatePathCost(std::size_t cost) {
  g = cost;
  f = g + h;
}

template <typename T> std::size_t State<T>::getPathCost() const { return g; }

template <typename T> std::size_t State<T>::getFCost() const { return f; }

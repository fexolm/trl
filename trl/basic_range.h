#ifndef TRL_TRL_BASIC_RANGE_H
#define TRL_TRL_BASIC_RANGE_H

#include <memory>
#include <iostream>

namespace trl {

template<typename T, typename Predicate, typename Parent>
class filter_range;

template<typename TIn, typename TOut, typename UnaryFunc, typename Parent>
class map_range;

template<typename T, typename Parent>
class basic_range {
public:
  template<typename Predicate>
  auto filter(Predicate p) {
    return filter_range<T, Predicate, basic_range<T, Parent>>(this, p);
  }

  template<typename Out, typename UnaryFunc>
  auto map(UnaryFunc f) {
    Out k = UnaryFunc(T());
    return map_range<T, Out, UnaryFunc, basic_range<Out, Parent>>(this, f);
  }

  void debug_print() {
    T val;
    while(move(val)) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }

public:
  virtual bool move(T &val) = 0;
};
}

#endif //TRL_TRL_BASIC_RANGE_H

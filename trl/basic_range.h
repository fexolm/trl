#ifndef TRL_TRL_BASIC_RANGE_H
#define TRL_TRL_BASIC_RANGE_H

#include <memory>
#include <iostream>

namespace trl {

template <typename T, typename Predicate>
class filter_range;

template<typename T>
class basic_range {
protected:
  basic_range *m_parrent;
public:
  explicit basic_range(basic_range *parent)
      : m_parrent(parent) {}

  template<typename Predicate>
  filter_range<T, Predicate> filter(Predicate p) {
    return filter_range<T, Predicate>(this, p);
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

#ifndef TRL_RANGE_H
#define TRL_RANGE_H

#include <type_traits>
#include "basic_range.h"

namespace trl {

template<typename Iter>
class range : public basic_range<typename std::iterator_traits<Iter>::value_type, int>{
private:
  Iter m_begin;
  Iter m_end;
  Iter m_current;
  using value_type = typename std::iterator_traits<Iter>::value_type;
public:
  range(Iter begin, Iter end):m_begin(begin), m_end(end), m_current(begin) {}
protected:
  bool move(value_type &val) override {
    val = *m_current;
    return (++m_current) != m_end;
  }
};
}

#endif //TRL_RANGE_H

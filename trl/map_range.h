//
// Created by fexolm on 08.09.2019.
//

#ifndef TRL_TRL_MAP_RANGE_H
#define TRL_TRL_MAP_RANGE_H

#include "basic_range.h"

namespace trl {
template<typename In, typename Out, typename UnaryFunc, typename Parent>
class map_range: public Parent {
private:
  UnaryFunc m_unary_func;
  Parent *m_parent;
public:
  map_range(Parent *parent, UnaryFunc p)
      : m_parent(parent), m_unary_func(p) {}
protected:
  bool move(Out &val) {
    In tmp;
    if (!m_parent->move(tmp)) {
      return false;
    }
    val = m_unary_func(tmp);
    return true;
  }
};
}

#endif //TRL_TRL_MAP_RANGE_H

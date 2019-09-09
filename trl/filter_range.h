#ifndef TRL_TRL_FILTER_RANGE_H
#define TRL_TRL_FILTER_RANGE_H

#include "basic_range.h"

namespace trl {
template<typename T, typename Predicate, typename Parent>
class filter_range : public Parent {
private:
  Predicate m_predicate;
  Parent *m_parent;
public:
  filter_range(Parent *parent, Predicate p)
      : m_parent(parent), m_predicate(p) {}
protected:
  bool move(T &val) {
    for (;;) {
      if (!m_parent->move(val)) {
        return false;
      }
      if (m_predicate(val)) {
        return true;
      }
    }
  }
};
}
#endif //TRL_TRL_FILTER_RANGE_H

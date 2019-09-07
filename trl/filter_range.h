#ifndef TRL_TRL_FILTER_RANGE_H
#define TRL_TRL_FILTER_RANGE_H

#include "basic_range.h"

namespace trl {
template<typename T, typename Predicate>
class filter_range : public basic_range<T> {
private:
  Predicate m_predicate;
public:
  filter_range(basic_range<T> *parent, Predicate p)
      : basic_range<T>(parent), m_predicate(p) {}
protected:
  bool move(T &val) override {
    for (;;) {
      if (!basic_range<T>::m_parrent->move(val)) {
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

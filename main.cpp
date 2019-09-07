//
// Created by fexolm on 07.09.2019.
//

#include "trl/filter_range.h"
#include "trl/range.h"
#include <vector>

int main() {
  std::vector<int> v{3, 5, 1, 2, 6, 1, 8, 2, 8};

  trl::range(v.begin(), v.end())
      .filter([](int a) { return a > 3; })
      .filter([](int a) { return a < 7; })
      .debug_print();
}
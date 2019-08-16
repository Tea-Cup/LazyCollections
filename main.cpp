#include <iostream>
#include "enumerable.hpp"

int main() {
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  lazycoll::Enumerable<int> en(array, 10);
  for (int i : en) {
    std::cout << i << std::endl;
  }
  return 0;
}

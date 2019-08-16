#pragma once
#ifndef LAZYCOLL_ENUMERABLE
#define LAZYCOLL_ENUMERABLE
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <stdexcept>
#include <type_traits>
#include <utility>

namespace lazycoll {

template <class T>
class Iterator : std::iterator<std::forward_iterator_tag, T> {
  Enumerable<T>& en;
  bool end;

 public:
  Iterator(Enumerable<T>& en) : en(en), end(false) { end = en.moveNext(); }

  Iterator& operator++() {
    end = en.moveNext();
    return *this;
  }
  Iterator operator++(int) {
    end = en.moveNext();
    return *this;
  }
  T& operator*() const { return en.current(); }
  T& operator->() const { return en.current(); }
  bool operator==(const Iterator& it) const {
    return en == it.en && end == it.end;
  }
  bool operator!=(const Iterator& it) const {
    return en != it.en && end == it.end;
  }
};

template <typename T>
class Enumerable {
 private:
  T* array;
  std::size_t size;
  std::size_t index;

 public:
  Enumerable(T* arr, std::size_t size) : array(arr), size(size), index(-1) {}

  T& current() const {
    if (this->index < 0 || this->index >= this->size)
      throw std::out_of_range("Index out of range");
    return this->array[index];
  }

  bool moveNext() { return ++this->index < this->size; }

  Iterator<T> begin() { return Iterator<T>(*this); }
  Iterator<T> end() { return Iterator<T>(*this); }
};

}  // namespace lazycoll
#endif

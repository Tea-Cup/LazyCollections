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
  T* array;
  const std::size_t size;
  std::size_t index;

 public:
  Iterator(T* arr, const std::size_t size, const std::size_t index)
      : array(arr), size(size), index(index) {}

  Iterator& operator++() {
    index++;
    return *this;
  }
  Iterator operator++(int) { return Iterator<T>(array, size, index++); }
  T& operator*() const { return array[index]; }
  T& operator->() const { return array[index]; }
  bool operator==(const Iterator& it) const { return index == it.index; }
  bool operator!=(const Iterator& it) const { return index != it.index; }
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

  Iterator<T> begin() { return Iterator<T>(array, size, 0); }
  Iterator<T> end() { return Iterator<T>(array, size, size); }
};

}  // namespace lazycoll
#endif

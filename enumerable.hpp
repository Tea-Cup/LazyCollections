#pragma once
#ifndef LAZYCOLL_ENUMERABLE
#define LAZYCOLL_ENUMERABLE
#include <cstdint>
#include <stdexcept>
#include <cassert>
#include <cstddef>
#include <iterator>
#include <type_traits>
#include <utility>

namespace lazycoll {
  template<class T>
  class iterator: std::iterator<std::forward_iterator_tag, T> {
    T* array;
    const std::size_t size;
    std::size_t index;
  public:
    iterator(T* arr, const std::size_t size, const std::size_t index)
      : array(arr), size(size), index(index) {}

    iterator& operator++() {
      index++;
      return *this;
    }
    iterator operator++(int) {
      return iterator<T>(array, size, index++);
    }
    T& operator*() const {
      return array[index];
    }
    T& operator->() const {
      return array[index];
    }
    bool operator ==(const iterator& it) const {
      return index == it.index;
    }
    bool operator !=(const iterator& it) const {
      return index != it.index;
    }
  };

  template<typename T>
  class enumerable {
    private:
      T* array;
      std::size_t size;
      std::size_t index;
    public:
      enumerable(T* arr, std::size_t size)
        : array(arr), size(size), index(-1) {}

      T& current() const {
        if(this->index < 0 || this->index >= this->size)
          throw std::out_of_range("Index out of range");
        return this->array[index];
      }

      bool moveNext() {
        return ++this->index < this->size;
      }

      iterator<T> begin() {
        return iterator<T>(array, size, 0);
      }
      iterator<T> end() {
        return iterator<T>(array, size, size);
      }
  };
}
#endif

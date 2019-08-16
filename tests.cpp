#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "enumerable.hpp"

TEST_CASE("Empty array does not iterate") {
  int arr[0];
  lazycoll::enumerable<int> en(arr, 0);
  REQUIRE_FALSE(en.moveNext());
}

TEST_CASE("Exactly 5 iteration on 5 long array") {
  int arr[5] = {1, 2, 3, 4, 5};
  lazycoll::enumerable<int> en(arr, 5);
  REQUIRE(en.moveNext());
  REQUIRE(en.moveNext());
  REQUIRE(en.moveNext());
  REQUIRE(en.moveNext());
  REQUIRE(en.moveNext());
  REQUIRE_FALSE(en.moveNext());
}

TEST_CASE("For adapter working") {
  int arr[5] = {1,2,3,4,5};
  lazycoll::enumerable<int> en(arr, 5);
  int iterations = 0;
  for(int i: en) {
    REQUIRE(i == arr[iterations++]);
  }
}

TEST_CASE("Throws when out of bounds") {
  int arr[1] = {1};
  lazycoll::enumerable<int> en(arr, 1);
  REQUIRE(en.moveNext());
  REQUIRE_FALSE(en.moveNext());
  REQUIRE_THROWS(en.current());
}

TEST_CASE("Throws if not moved") {
  int arr[1] = {1};
  lazycoll::enumerable<int> en(arr, 1);
  REQUIRE_THROWS(en.current());
}

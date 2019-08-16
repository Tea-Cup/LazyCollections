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

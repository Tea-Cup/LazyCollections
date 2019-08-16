#include "../enumerable.hpp"
#include "catch.hpp"

SCENARIO("Enumerable") {
  GIVEN("an empty array") {
    int arr[0];
    lazycoll::Enumerable<int> en(arr, 0);

    WHEN("tries to enumerate") {
      THEN("returns false") { REQUIRE(en.moveNext() == false); }
    }
    WHEN("tries to acquire an element") {
      THEN("throws an exception") { REQUIRE_THROWS(en.current()); }
    }
  }

  GIVEN("an array with 5 items") {
    int arr[5] = {1, 2, 3, 4, 5};
    lazycoll::Enumerable<int> en(arr, 5);

    WHEN("tries to enumerate") {
      THEN("succeeds 5 times") {
        REQUIRE(en.moveNext() == true);
        REQUIRE(en.moveNext() == true);
        REQUIRE(en.moveNext() == true);
        REQUIRE(en.moveNext() == true);
        REQUIRE(en.moveNext() == true);

        AND_THEN("always returns false") {
          REQUIRE(en.moveNext() == false);
          REQUIRE(en.moveNext() == false);
          REQUIRE(en.moveNext() == false);
          REQUIRE(en.moveNext() == false);
          REQUIRE(en.moveNext() == false);

          AND_THEN("throws an exception if tries to get element") {
            REQUIRE_THROWS(en.current());
          }
        }
      }
    }

    WHEN("tries to enumerate with 'for'") {
      THEN("enumerates exactly 5 times") {
        int iterations = 0;
        for (auto it : en) REQUIRE(arr[iterations++] == it);
        REQUIRE(iterations == 5);
      }
    }

    WHEN("tries to get element without enumerating"){
      THEN("throws an exception"){
        REQUIRE_THROWS(en.current());
      }
    }
  }
}

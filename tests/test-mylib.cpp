#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
import mylib;

TEST_CASE("test-mylib") {
  auto r = mylib::add_two_integers(1, 2);
  CHECK_EQ(r, 3);
}

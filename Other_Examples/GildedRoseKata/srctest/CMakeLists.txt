find_package(GTest REQUIRED)

add_executable(runTests GildedRoseTest.cpp)

target_include_directories(runTests PRIVATE ../src)

target_link_libraries(runTests
 PRIVATE
  GTest::GTest
  GildedRose)

add_test(runTests runTests)
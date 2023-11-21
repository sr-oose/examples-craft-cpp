set(TEST_NAME runTests)

find_package(GTest REQUIRED)
add_executable(${TEST_NAME} GoogleMock.cpp)
target_link_libraries(${TEST_NAME} gtest gmock)
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

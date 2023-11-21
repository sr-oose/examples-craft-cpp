set(TEST_NAME runTests)

find_package(GTest REQUIRED)
add_executable(${TEST_NAME} BarrierActuatorMock.cpp BarrierActuatorStub.cpp Test.cpp)
target_link_libraries(${TEST_NAME} src gtest gmock)
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

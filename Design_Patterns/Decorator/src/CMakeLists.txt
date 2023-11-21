add_library(decoratorlib decorators.cpp textsource.cpp)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE decoratorlib)
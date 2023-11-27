#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <algorithm>
#include <concepts>

// `T` is not limited by any constraints.
template <typename T>
concept always_satisfied = true;
// Limit `T` to integrals.
template <typename T>
concept integral = std::is_integral_v<T>;
// Limit `T` to both the `integral` constraint and signedness.
template <typename T>
concept signed_and_integral = std::integral<T> && std::is_signed_v<T>;
// Limit `T` to both the `integral` constraint and the negation of the `signed_integral` constraint.
template <typename T>
concept unsigned_and_integral = std::integral<T> && !signed_and_integral<T>;

template<typename T> 
requires signed_and_integral<T> 
T invert(T value){
	return -value;
}

using namespace std;

int main() {
	int value = 1;
	auto result = invert(value);
	cout << result << endl;
	return 0;
}

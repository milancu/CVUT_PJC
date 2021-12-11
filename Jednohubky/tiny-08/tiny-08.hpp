#pragma once

#include <ostream>
#include <cstdlib>
#include <utility>
#include <functional>


template<typename T, typename Compare>
T const &clamp(T const &value, T const &low, T const &high, Compare cmp) {
    return cmp(value, low) ? low : cmp(high, value) ? high : value;
}

template<class T>
T const &clamp(T const &value, T const &low, T const &high) {
    return clamp(value, low, high, std::less<T>());
}

#pragma once

#include <type_traits>

//
// This file has traits that are not in C++17
//

template <typename T>
struct is_scoped_enum {
    static constexpr bool value = std::is_enum<T>::value && !std::is_convertible<T, int>::value;
};

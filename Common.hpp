#pragma once
#ifndef COMMON_HPP
#define COMMON_HPP

#include <type_traits>
#include <tuple>

namespace SimpleLogger{

        template<class... Args>
        concept AllSame = 
        sizeof...(Args) < 2 ||
        std::conjunction_v<
            std::is_same<std::tuple_element_t<0, std::tuple<Args...>>, Args>...
        >;
        
}
#endif
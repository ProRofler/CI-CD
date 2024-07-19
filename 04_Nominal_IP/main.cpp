#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

// primary template inheriting type trait
template <class Container>
struct is_container : std::false_type {};

// vector specialization
template <class Container, typename Alloc>
struct is_container<std::vector<Container, Alloc>> : std::true_type {};

// list specialization
template <class Container, typename Alloc>
struct is_container<std::list<Container, Alloc>> : std::true_type {};

// tuple specialization
template <class Container>
struct is_tuple : std::false_type {};

template <typename... Ts>
struct is_tuple<std::tuple<Ts...>> : std::true_type {};

// base template
template <typename... Ts>
struct are_same_types : std::true_type {};

template <typename Tuple, std::size_t... Is>
constexpr bool are_same_type_impl(std::index_sequence<Is...>) {
    return (std::is_same_v<std::tuple_element_t<0, Tuple>,
                           std::tuple_element_t<Is, Tuple>> &&
            ...);
}

template <typename... Ts>
constexpr bool are_same_type_tuple =
    are_same_type_impl<std::tuple<Ts...>>(std::index_sequence_for<Ts...>{});

// // primary template for tuple
// template<typename... Ts>
// struct are_same_type : std::true_type{};

// // recursive check of types
// template<typename T, typename U, typename... Ts>
// struct are_same_type<T, U, Ts...> : std::conditional_t<std::is_same_v<T, U>,
// are_same_type<U, Ts...>, std::false_type> {};

// template <typename... Ts>
// constexpr bool are_same_type_tuple =
//     (std::is_same_v<Ts, std::tuple_element_t<0, std::tuple<Ts...>>> && ...);

// list vector metafunction
template <typename T>
typename std::enable_if<is_container<T>::value, void>::type print_ip(T value) {
    std::cout << "Template output for vector/list: ";
    auto it = value.begin();
    for (const auto element : value) {
        std::cout << element;

        if (std::next(it) == value.end()) {
            std::cout << std::endl;
        } else {
            std::cout << '.';
        }
        it++;
    }
}

template <typename T>  // integer func
typename std::enable_if<std::is_integral<T>::value, void>::type print_ip(
    T value) {
    std::cout << "integer output template " << value << std::endl;
}

template <typename T>  // string func, output as is
typename std::enable_if<std::is_same<T, std::string>::value>::type print_ip(
    T value) {
    std::cout << "Template output for string: " << value << std::endl;
}

template <typename T>
typename std::enable_if<
    is_tuple<T>::value &&
        are_same_type_tuple<typename std::tuple_element<0, T>::type,
                            // typename std::tuple_element<1, T>::type,
                            // typename std::tuple_element<2, T>::type,
                            typename std::tuple_element<
                                std::tuple_size<T>::value - 1, T>::type>,
    void>::type
print_ip(const T& value) {
    std::cout << "tuple output template ";
    std::apply([](const auto&... args) { ((std::cout << args << '.'), ...); },
               value);
    std::cout << std::endl;
}

// template <typename T>
// typename std::enable_if<is_tuple<T>::value &&
// are_same_type_tuple<typename T::value_type>, void>::type print_ip(T) {
//     std::cout << "tuple output template " << std::endl;
// }

// template <typename T>  // container func
// auto print_ip(T value) -> decltype(value.sort()) {
//     std::cout << "vector/list output " << std::endl;
// }

// TODO: fold expression for outputs

int main() {
    // print_ip(int8_t{-1});           // 255
    // print_ip(int16_t{0});           // 0.0
    // print_ip(int32_t{2130706433});  // 127.0.0.1
    // print_ip(int64_t{8875824491850138409});

    print_ip(std::string{"Hello, World!"});

    print_ip(std::vector<int>{100, 200, 300, 400});  // 100.200.300.400
    print_ip(std::list<short>{400, 300, 200, 100});  // 400.300.200.100
    // print_ip(std::make_tuple(123, 456, 789, 0));  // 123.456.789.0

    return 0;
}
#ifndef CONCEPTS_HPP
#define CONCEPTS_HPP
#include <concepts>
#include <memory>

namespace ut {
template<typename A, typename B>
concept SameAsRemoveCVRef = std::same_as<std::remove_cvref_t<A>, std::remove_cvref_t<B>>;

template<typename D, typename B>
concept DerivedOrEqualTo = SameAsRemoveCVRef<D, B> || std::derived_from<std::remove_cvref_t<D>, std::remove_cvref_t<B>>;

template<typename T>
struct AddTransitiveConst;

template<typename T>
requires(!std::is_pointer_v<T>) struct AddTransitiveConst<T> {
    using type = std::add_const_t<T>;
};

template<typename T>
requires(std::is_pointer_v<T>) struct AddTransitiveConst<T> {
public:
    using type = std::add_const_t<std::add_pointer_t<typename AddTransitiveConst<std::remove_pointer_t<T>>::type>>;
};

template<typename T>
using AddTransitiveConstT = AddTransitiveConst<T>::type;

template<typename T>
struct IsUniquePtr : std::false_type { };

template<typename T>
struct IsUniquePtr<std::unique_ptr<T>> : std::true_type { };

template<typename T>
inline constexpr bool IsUniquePtrV = IsUniquePtr<T>::value;

template<typename T>
concept UniquePtr = IsUniquePtrV<T>;

template<typename T>
concept NotUniquePtr = !IsUniquePtrV<T>;

template<typename T>
concept Pointer = std::is_pointer_v<T>;

[[nodiscard]]
static constexpr auto distance(auto a, auto b) {
    return std::distance(AddTransitiveConstT<decltype(a)>(a), AddTransitiveConstT<decltype(b)>(b));
}

template<typename A, typename B>
struct PtrCmp {
    constexpr bool operator()(A const *, B const *) const {
        return false;
    }
};

template<typename T>
struct PtrCmp<T, T> {
    constexpr bool operator()(T const *a, T const *b) const {
        return a == b;
    }
};

template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

}  // namespace ut


#endif  // CONCEPTS_HPP

#ifndef PTRVECVIEW_HPP
#define PTRVECVIEW_HPP

#include "container_base.hpp"

#define BASE                                    \
    ContainerBase<T,                            \
        /*ValueType      = */ T,                \
        /*StorageType    = */ T const *const *, \
        /*Reference      = */ T const *,        \
        /*ConstReference = */ T const *,        \
        /*Iterator       = */ T const *const *, \
        /*ConstIterator  = */ T const *const *>

namespace ut {
template<typename T>
class PtrVecView : public BASE {
    using Base = BASE;
#undef BASE

    UT_CONTAINER_BASE_INJECT_DEPENDANT_NAMES(Base);

public:
    PtrVecView() {
        m_data = nullptr;
        m_size = 0;
    }

    PtrVecView(const_iterator from, const_iterator to) {
        m_data = from;
        auto const dist = distance(from, to);
        assert(dist > 0);
        m_size = size_type(dist);
    }

    PtrVecView(const_iterator from, size_type count) {
        m_data = from;
        m_size = count;
    }
};

}  // namespace ut

#endif  // PTRVECVIEW_HPP

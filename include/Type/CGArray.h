#pragma once
#include <cstdint>
#include <vector>

namespace CG
{
    template <typename T>
    class CG_EXPORTS CGArray
    {
    private:
        std::vector<T>* _copy;

    public:
        T* Data;
        int32_t Count;
        int32_t ItemSize;

        CGArray() = delete;

        explicit CGArray(const std::vector<T>& vector)
        {
            _copy = new std::vector<T>(vector);
            Data = const_cast<T*>(_copy->data());
            Count = static_cast<int32_t>(_copy->size());
            ItemSize = sizeof(T);
        }

        /**
         * \brief Destructor
         * \remarks Must to be virtual to be exported
         */
        virtual ~CGArray()
        {
            delete _copy;
            _copy = nullptr;
        }
    };
}

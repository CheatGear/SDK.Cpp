#pragma once
#include <cstdint>

namespace CG
{
    /**
     * \brief Process memory region information
     */
    class MemRegionInfo final
    {
    public:
        /**
         * \brief Memory region allocation base
         */
        void* AllocationBase = nullptr;

        /**
         * \brief Memory region base address
         */
        void* BaseAddress = nullptr;

        /**
         * \brief Memory region size
         */
        uint64_t Size = 0;

        /**
         * \brief Memory region state flags
         */
        uint32_t State = 0;

        /**
         * \brief Memory region protect flags
         */
        uint32_t Protect = 0;

        /**
         * \brief Memory region type
         */
        uint32_t Type = 0;
    };
}

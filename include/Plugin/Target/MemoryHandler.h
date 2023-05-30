#pragma once
#include <cstdint>

namespace CG
{
    /**
     * \brief Memory Handler
     */
    class CG_EXPORTS MemoryHandler
    {
    protected:
        virtual ~MemoryHandler() = default;

    public:
        /**
         * \brief Determinate address is a bad address to be used in general
         * \param address Address to check
         * \return true when address is not safe to use, otherwise false
         */
        virtual bool IsBadAddress(void* address) = 0;

        /**
         * \brief Determinate address is a static address
         * \param address Address to check
         * \return true when address is static memory address
         */
        virtual bool IsStaticAddress(void* address) = 0;

        /**
         * \brief Determinate address is a valid address in targeted process
         * \param address Remote address to check
         * \return true when address is valid to use, otherwise false
         */
        virtual bool IsValidRemoteAddress(void* address) = 0;

        /**
         * \brief Read memory bytes
         * \param address Memory address to read bytes from
         * \param bytes [out] Bytes that was read from target address
         * \param size Size of bytes to read
         * \param numberOfBytesRead [out] Count of bytes read
         * \return true if success, otherwise false
         */
        virtual bool ReadBytes(void* address, uint8_t* bytes, int size, uint64_t* numberOfBytesRead) = 0;

        /**
         * \brief Write memory bytes
         * \param address Memory address to write bytes to
         * \param bytes Bytes to write on target address
         * \param size Size of bytes to write
         * \param numberOfBytesWritten [out] Count of written bytes
         * \return true if success, otherwise false
         */
        virtual bool WriteBytes(void* address, uint8_t* bytes, int size, uint64_t* numberOfBytesWritten) = 0;
    };
}

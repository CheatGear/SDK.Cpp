#pragma once
#include <cstdint>

namespace CG
{
    /**
     * \brief Process module information
     */
    class MemModuleInfo final
    {
    public:
        /**
         * \brief Module handle, Could be nullptr
         */
        void* Handle = nullptr;

        /**
         * \brief Module Name
         */
        wchar_t* Name = nullptr;

        /**
         * \brief Module full path
         */
        wchar_t* Path = nullptr;

        /**
         * \brief Module base address
         */
        uintptr_t Address = 0;

        /**
         * \brief Module size
         */
        uint32_t Size = 0;

        /**
         * \brief Determinate module is the main module
         */
        bool MainModule = false;

    public:
        MemModuleInfo() = delete;

        explicit MemModuleInfo(void* handle, const wchar_t* name, const wchar_t* path, const uintptr_t address, const uint32_t size, const bool mainModule)
        {
            Handle = handle;
            Address = address;
            Size = size;
            MainModule = mainModule;

            size_t nameLen = wcslen(name) + 1;
            Name = new wchar_t[nameLen]{};
            wcscpy_s(Name, nameLen, name);

            size_t pathLen = wcslen(path) + 1;
            Path = new wchar_t[pathLen]{};
            wcscpy_s(Path, pathLen, path);
        }

        MemModuleInfo(const MemModuleInfo& other)
        {
            CopyProps(other);
        }

        MemModuleInfo(MemModuleInfo&& other) noexcept
        {
            CopyProps(other);
        }

        ~MemModuleInfo()
        {
            delete[] Name;
            Name = nullptr;

            delete[] Path;
            Path = nullptr;
        }

    public:
        void CopyProps(const MemModuleInfo& other)
        {
            Handle = other.Handle;
            Address = other.Address;
            Size = other.Size;
            MainModule = other.MainModule;

            size_t nameLen = wcslen(other.Name) + 1;
            Name = new wchar_t[nameLen]{};
            wcscpy_s(Name, nameLen, other.Name);

            size_t pathLen = wcslen(other.Path) + 1;
            Path = new wchar_t[pathLen]{};
            wcscpy_s(Path, pathLen, other.Path);
        }

    public:
        MemModuleInfo& operator=(const MemModuleInfo& other)
        {
            if (this == &other)
                return *this;

            CopyProps(other);

            return *this;
        }

        MemModuleInfo& operator=(MemModuleInfo&& other) noexcept
        {
            if (this == &other)
                return *this;

            CopyProps(other);

            return *this;
        }
    };
}

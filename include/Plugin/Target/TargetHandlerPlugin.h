#pragma once
#include "MemModuleInfo.h"
#include "MemRegionInfo.h"
#include "../PluginBase.h"
#include "../../Type/CGArray.h"
#include "MemoryHandler.h"

namespace CG
{
    class CG_EXPORTS TargetHandlerPlugin : public PluginBase
    {
    public:
        PluginKind GetPluginType() override
        {
            return PluginKind::TargetHandler;
        }

        /**
         * \brief Target memory handler
         */
        virtual MemoryHandler* GetMemoryHandler() = 0;

        /**
         * \brief Called when plugin loaded or activated
         */
        virtual void Load() = 0;

        /**
         * \brief Called when plugin unloaded to free and clean resources
         */
        virtual void Unload() = 0;

        /**
         * \brief Called before \ref OnTargetLock to clean old target
         */
        virtual void OnTargetFree() = 0;

        /**
         * \brief Called when target process changed
         * \param processId New process id
         * \return true when successfully target changed, otherwise false
         * \remarks This function could be called more than once
         */
        virtual bool OnTargetLock(int32_t processId) = 0;

        /**
         * \brief Called after \ref OnTargetLock to load/cache information
         */
        virtual void OnTargetReady() = 0;

        /**
         * \brief Get current target modules
         * \return Current target modules collection
         */
        virtual CGArray<MemModuleInfo>* GetModules() = 0;

        /**
         * \brief Determine current target is x64 arch
         * \return true when current target is 64-bit, otherwise false
         */
        virtual bool GetIs64Bit() = 0;

        /**
         * \brief Get system memory page size
         * \return system memory page size
         */
        virtual int32_t GetSystemPageSize() = 0;

        /**
         * \brief Get minimum valid address
         * \return Minimum valid address
         */
        virtual void* GetMinValidAddress() = 0;

        /**
         * \brief Get maximum valid address
         * \return Maximum valid address
         */
        virtual void* GetMaxValidAddress() = 0;

        /**
         * \brief Get information about memory region in targeted process
         * \param address Address to get memory region information for
         * \param memRegion Memory region information
         * \return true if address are valid, otherwise false
         */
        virtual bool GetMemoryRegion(void* address, MemRegionInfo* memRegion) = 0;

        /**
         * \brief Determinate region is valid to be used in different operations
         * \param memRegion Memory region
         * \return true when region are valid for memory operations, otherwise false
         */
        virtual bool IsValidRegion(MemRegionInfo* memRegion) = 0;

        /**
         * \brief Determine process is valid or not
         * \param processId Process id to check
         * \return true if process with processId are found, otherwise false
         */
        virtual bool IsValidProcess(int processId) = 0;

        /**
         * \brief Determine current target is valid or not
         * \return true if current target is valid, otherwise false
         */
        virtual bool IsValidTarget() = 0;

        /**
         * \brief Suspend targeted process
         * \return <c>true</c> when targeted process suspend, otherwise false
         */
        virtual bool Suspend() = 0;

        /**
         * \brief Resume suspend targeted process
         * \return <c>true</c> when targeted process resumed, otherwise false
         */
        virtual bool Resume() = 0;

        /**
         * \brief Force killing targeted process
         * \return true when targeted process killed, otherwise false
         */
        virtual bool Terminate() = 0;
    };
}

#pragma once
#include "PluginKind.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "PluginInfo.h" // Don't remove

namespace CG
{
    /**
     * \brief Base class for all plugins
     */
    class CG_EXPORTS PluginBase
    {
    public:
        virtual ~PluginBase() = default;

    protected:
        /**
         * \brief Called when plugin get loaded
         */
        virtual void OnLoad() {}

        /**
         * \brief Called when plugin get unloaded
         */
        virtual void OnUnload() {}

    public:
        /**
         * \brief Get plugin type
         * \return Plugin type
         */
        virtual PluginKind GetPluginType() = 0;
    };
}

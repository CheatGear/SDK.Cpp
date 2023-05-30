#pragma once
#include <cstdint>

namespace CG
{
    /**
     * \brief Type of plugin
     */
    enum class PluginKind : int32_t
    {
        /**
         * \brief Unknown
         */
        Unknown,

        /**
         * \brief For plugins that handle target/memory (read, write and process info)
         */
        TargetHandler,

        /**
         * \brief For plugins that aims to support different output styles
         */
        OutputSupport,

        /**
         * \brief For plugins that aims to extend engine functionality
         */
        EngineHelper
    };
}

#pragma once

namespace CG
{
    /**
     * \brief Plugin basic information
     */
    class PluginInfo final
    {
    public:
        /**
         * \brief Plugin name
         */
        const wchar_t* Name = nullptr;

        /**
         * \brief Version eg: 1.0.1
         */
        const wchar_t* Version = nullptr;

        /**
         * \brief Author name
         */
        const wchar_t* Author = nullptr;

        /**
         * \brief Small description about what this plugin does
         */
        const wchar_t* Description = nullptr;

        /**
         * \brief Link to your website, can be empty string
         */
        const wchar_t* WebsiteLink = nullptr;

        /**
         * \brief Link to this plugins source code link [Github, BitBucket, etc], can be empty string
         */
        const wchar_t* SourceCodeLink = nullptr;
    };
}

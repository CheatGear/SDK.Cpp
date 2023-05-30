#pragma once
#include <cstdio>
#include <cstring>

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define CG_LOG(format, ...) std::printf("[%s:%s:%i] " format "\n", __FILENAME__, __FUNCTION__, __LINE__, __VA_ARGS__)
#define CG_LOG_FUNC_CALL std::printf("%s::%s\n", __FILENAME__, __FUNCTION__)

#define CG_SDK_VER "2.0.0"
#define CG_EXPORTS __declspec(dllexport)

/**
 * \brief Register CheatGear plugin
 * \param pluginClass Class that will implement the logic of the plugin, should match with 'pluginType'
 * \param pluginType Type of plugin
 * \param pluginName Name
 * \param pluginVersion Version eg: 1.0.1
 * \param pluginAuthor Author name
 * \param pluginDescription Small description about what this plugin does
 * \param pluginWebsiteLink Link to your website, can be empty string
 * \param pluginSourceCodeLink Link to this plugin source code [Github, BitBucket, etc], can be empty string
 */
#define CG_REGISTER_PLUGIN(pluginClass, pluginType, pluginName, pluginVersion, pluginAuthor, pluginDescription, pluginWebsiteLink, pluginSourceCodeLink) \
    CG_EXPORTS void* CreateInstance() \
    { \
        auto* p = new pluginClass(); \
        return p; \
    } \
    CG_EXPORTS void ReleaseInstance(void* pInstance) \
    { \
        auto* p = static_cast<pluginClass*>(pInstance); \
        delete p; \
    } \
    CG_EXPORTS char* GetSdkVersion() \
    { \
        static char* sdkVer = nullptr; \
        if (!sdkVer) sdkVer = const_cast<char*>(CG_SDK_VER); \
        return sdkVer; \
    } \
    CG_EXPORTS CG::PluginKind GetPluginType() \
    { \
        return pluginType; \
    } \
    CG_EXPORTS CG::PluginInfo* GetPluginInfo() \
    { \
        auto* pInfo = new CG::PluginInfo(); \
        pInfo->Name = L##pluginName; \
        pInfo->Version = L##pluginVersion; \
        pInfo->Author = L##pluginAuthor; \
        pInfo->Description = L##pluginDescription; \
        pInfo->WebsiteLink = L##pluginWebsiteLink; \
        pInfo->SourceCodeLink = L##pluginSourceCodeLink; \
        return pInfo; \
    }

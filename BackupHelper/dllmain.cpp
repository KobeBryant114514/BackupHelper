#include "Version.h"
#include "pch.h"

void PluginInit();

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        ll::registerPlugin(
            "BackupHelper",
            "One command to backup your level",
            ll::Version(PLUGIN_VERSION_MAJOR, PLUGIN_VERSION_MINOR, PLUGIN_VERSION_REVISION),
            std::map<std::string, std::string>{
                {"Author", "Tsubasa6848"},
                {"Origin Author", "yqs112358"},
                {"GitHub","https://github.com/yqs112358/LLPlugins"}
            });
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" {
    _declspec(dllexport) void onPostInit() {
        std::ios::sync_with_stdio(false);
        PluginInit();
    }
}

#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/stdpaths.h> 
#include <wx/filename.h> 
#include <From MemHack.h>
#include <wx/xml/xml.h>
#include <wx/app.h>
#include <filesystem>
#include <wx/cmdline.h>
#include <wx/image.h>
#include <wx/fileconf.h>

#include "Properties.h"
#include <Logs/Log.h>

#include <json/json.hpp>

#include <string>
#include <sstream>


using json = nlohmann::json;
json Properties;
bool initialized = false;
#define Properties_Filename "GoodTool_Settings.txt";


void LoadSettings(void)
{
    
    wxString settingsFile = wxStandardPaths::Get().GetUserDataDir() +
        wxFileName::GetPathSeparator() +
        Properties_Filename;
    mlog::State("Loading properties from: ",settingsFile);
    std::ifstream file(settingsFile.c_str().AsChar());
    if (!file.is_open())
    {
        mlog::State("Unable To Open File:", settingsFile.c_str().AsChar());
    }
    else
    {
        file>>Properties;
    }
    mlog::Debug("Properties: ", Properties);
    file.close();
}

void LoadMods()
{
    initialized = true;
    mlog::State("Loading Mods: ");
    auto mods = Properties["mods"];
    mlog::State("taked root mods: ", mods);
    if (!mods.is_object())
    {
        mlog::State("root does not contains mods");
        goto incorrectmod;
    }
    if (mods.size() == 0)
    {
        mlog::State("There is no mods");
        goto incorrectmod;
    }
    for (auto a : mods.items())
    {
        auto mod = a.value();
        if (!mod.is_object())
        {
            mlog::State("Incorrect mod, removing");
            mod.clear();
        }
        else
        {
            auto name = a.key();
            auto path = mod["path"];
            auto initializer = mod["initializer"];
            mlog::State("name: ", name, " path: ", path, " initializer: ", initializer);
            if (!path.is_string() || name.empty())
            {
                mlog::State("Incorrect mod, unable to find name or path");
            }
            else
            {
                auto mpq = StormLoadMPQTemp(path.get<std::string>().c_str(), 18, 4);
                if (mpq != NULL)
                {
                    mlog::State("Loaded base file");
                    if (initializer.is_string())
                    {
                        if (GlobalDoFileFromMPQ(initializer.get<std::string>().c_str()))
                        {
                            mlog::State("initializer: \"", initializer, "\" was loaded");
                        }
                        else
                        {
                            mlog::State("initializer: \"", initializer, "\" was not loaded");
                        }
                    }
                    else
                    {
                        mlog::State("initializer is not str: ", initializer);
                        mods["initializer"].clear();
                    }

                }
                else
                {
                    mlog::State("Unable to load base file");
                }
            }
            
        }
    }
    mlog::State("Mod Loading was completed");
    return;
incorrectmod:
    mlog::State("Recreating settings");
    Properties = json::object();
}


void SaveProperties()
{
    if (!initialized) return;
    mlog::State("Saving Propeties");
    wxString settingsFile = wxStandardPaths::Get().GetUserDataDir() +
        wxFileName::GetPathSeparator() +
        Properties_Filename;
    std::filesystem::create_directories(wxStandardPaths::Get().GetUserDataDir().c_str().AsChar());
    if (FileExists(settingsFile))
    {
        wxRenameFile(settingsFile, settingsFile + ".bak", true);
    }
    std::ofstream out(settingsFile.c_str().AsChar());
    mlog::Debug("Saving properties: ", Properties);
    out << Properties;
    out.close();
}



bool LoadMod(const char* _path, const char* _name, const char* _initializer)
{
    if (_initializer == NULL)
    {
        mlog::State("Loading mod with name:\"", _name, "\", path: \"", _path, "\"");
    }
    else
        
    {
        mlog::State("Loading mod with name:\"", _name, "\", path: \"", _path, "\". initializer: \"",_initializer,"\"");
    }
    if (Properties.is_null())
    {
        mlog::State("incorrect properties, creating new file");
        initialized = true;
    }
    auto mods = Properties["mods"];
    if (!mods.is_object())
    {
        mods = json::object();
    }
    auto mod = mods[_name];
    if (!mod.is_object())
    {
        mod = json::object();
    }
    mlog::Debug("mods: ", mods, " mod: ", mod);
    mod["path"] = _path;
    if (_initializer != NULL)
    {
        mod["initializer"] = _initializer;
    }
    mods[_name] = mod;
    Properties["mods"] = mods;
    auto a = StormLoadMPQTemp(_path, 18, 4);
    if (a != NULL)
    {
        mlog::State("Loaded base file");
        if (GlobalDoFileFromMPQ(_initializer))
        {
            mlog::State("initializer: \"", _initializer, "\" was loaded");
        }
        else
        {
            mlog::State("initializer: \"", _initializer, "\" was not loaded");
        }
    }
    else
    {
        mlog::State("Unable to load base file");
        return false;
    }
    return true;

}
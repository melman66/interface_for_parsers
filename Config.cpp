
#include "Config.h"

Config::Config(const string& url)
{
    loadConfig(url);
}

Config::Config(shared_ptr<FileConfig> pfcfg) : pFileConfig(pfcfg)
{}

shared_ptr<FileConfig> Config::getSection(const string& section) const
{
    return (*pFileConfig).getSection(section);
}

shared_ptr<FileConfig> Config::getFileConfig()
{
    return shared_ptr<FileConfig>();
}

void Config::printAllCode()
{
	(*pFileConfig).printAllCode();
}

bool Config::loadConfig(const string& url)
{
    string file_format = getFileFormat(url);
    cout << file_format << endl;

    if (file_format == "json")
        pFileConfig = FileConfigJSON::createFileConfig(url);
    /*else if (file_format == "xml"
        ... another parsers */
    else
        cout << "There are no classes for processing" << endl;

    if (pFileConfig) {
        cout << "FileConfig is created" << endl;
        return true;
    }
    else {
        cout << "FileConfig is not created" << endl;
        return false;
    }
}

string Config::getFileFormat(const string& url) const
{
    string format{ "" };
    for (auto i = url.end() - 1; i >= url.begin(); i--) {
        if (*i == '.') {
            for (auto j = i + 1; j != url.end(); j++)
                format.push_back(*j);
            break;
        }
    }
    return format;
}

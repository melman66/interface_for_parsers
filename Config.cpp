
#include "Config.h"

Config::Config(const string& url)
{
    loadConfig(url);
}

Config::Config(shared_ptr<FileConfig> pfcfg) : pFileConfig(pfcfg)
{}

shared_ptr<FileConfig> Config::getSection(const string& section) const
{
    return pFileConfig->getSection(section);
}

shared_ptr<FileConfig> Config::getFileConfig()
{
    return pFileConfig;
}

string Config::getOption(const string& option) const
{
    return pFileConfig->getOption(option);
}

string Config::getStringParserData()
{
    return pFileConfig->getStringParserData();
}

bool Config::setOption(const string& option, const char* value) const
{
    return pFileConfig->setOption(option, value);
}
bool Config::setOption(const string& option, const int& value) const
{
    return pFileConfig->setOption(option, value);
}
bool Config::setOption(const string& option, const double& value) const
{
    return pFileConfig->setOption(option, value);
}
bool Config::setOption(const string& option, const bool& value) const
{
    return pFileConfig->setOption(option, value);
}
bool Config::addOption(const string& option, const char* value) const
{
    return pFileConfig->addOption(option, value);
}
bool Config::addOption(const string& option, const int& value) const
{
    return pFileConfig->addOption(option, value);
}
bool Config::addOption(const string& option, const double& value) const
{
    return pFileConfig->addOption(option, value);
}
bool Config::addOption(const string& option, const bool& value) const
{
    return pFileConfig->addOption(option, value);
}
bool Config::hasOption(const string& option) const
{
    return pFileConfig->hasOption(option);
}
void Config::removeOption(const string& option) const
{
    pFileConfig->removeOption(option);
}
bool Config::insertSection(shared_ptr<Config> section_cfg, const string& section_in) const
{
    return pFileConfig->insertSection(section_cfg->getFileConfig(), section_in);
}
bool Config::insertSection(shared_ptr<Config> section_cfg) const
{
    return pFileConfig->insertSection(section_cfg->getFileConfig(), "");
}
bool Config::saveConfigToFile(const string& url) const
{
    return pFileConfig->saveConfigToFile(url);
}
void Config::printAllCode()
{
	pFileConfig->printAllCode();
}

bool Config::loadConfig(const string& url)
{
    string file_format = getFileFormat(url);
    cout << file_format << endl;

    if (file_format == "json") {
        pFileConfig = FileConfigJSON::createFileConfig(url);
        return true;
    }
    /*else if (file_format == "xml"
        ... another parsers */
    else {
        cout << "There are no classes for processing" << endl;
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


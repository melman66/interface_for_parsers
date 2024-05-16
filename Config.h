#pragma once

#include <iostream>
#include "BaseConfig.h"
#include "FileConfig.h"
#include "FileConfigJSON.h"

using namespace std;

class Config : public virtual BaseConfig
{
	shared_ptr <FileConfig> pFileConfig;

public:
	explicit Config(const string& url);
	explicit Config(shared_ptr <FileConfig> pfcfg);

	bool loadConfig(const string& url);
	shared_ptr <FileConfig> getSection(const string& section) const;
	shared_ptr <FileConfig> getFileConfig();

	string getOption(const string& option) const;
	string getStringParserData();

	bool setOption(const string& option, const char* value) const;
	bool setOption(const string& option, const int& value) const;
	bool setOption(const string& option, const double& value) const;
	bool setOption(const string& option, const bool& value) const;

	bool addOption(const string& option, const char* value) const;
	bool addOption(const string& option, const int& value) const;
	bool addOption(const string& option, const double& value) const;
	bool addOption(const string& option, const bool& value) const;

	bool hasOption(const string& option) const;
	void removeOption(const string& option) const;

	bool insertSection(shared_ptr<Config> section_cfg, const string& section_in) const;
	bool insertSection(shared_ptr<Config> section_cfg) const;

	bool saveConfigToFile(const string& url) const;

	void printAllCode();

private:
	string getFileFormat(const string& url) const;
};


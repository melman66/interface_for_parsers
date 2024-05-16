#pragma once

#include <iostream>
#include "BaseConfig.h"

using namespace std;

class FileConfig : public virtual BaseConfig
{
public:
	virtual ~FileConfig() = default;
	virtual shared_ptr<FileConfig> getSection(const string& section) = 0;
	virtual string getStringParserData() = 0;
	
	virtual bool setOption(const string& option, const char* value) = 0;
	virtual bool setOption(const string& option, const int& value) = 0;
	virtual bool setOption(const string& option, const double& value) = 0;
	virtual bool setOption(const string& option, const bool& value) = 0;

	virtual bool addOption(const string& option, const char* value) = 0;
	virtual bool addOption(const string& option, const int& value) = 0;
	virtual bool addOption(const string& option, const double& value) = 0;
	virtual bool addOption(const string& option, const bool& value) = 0;

	virtual string getOption(const string& option) = 0;
	virtual bool   hasOption(const string& option) = 0;
	virtual bool   removeOption(const string& option)  = 0;
	
	virtual bool   insertSection(shared_ptr<FileConfig> section_pfc
		, const string& section) = 0;
	virtual bool saveConfigToFile(const string& url) = 0;

	virtual void printAllCode() = 0;
};


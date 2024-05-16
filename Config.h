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

	shared_ptr <FileConfig> getSection(const string& section) const;
	static shared_ptr <FileConfig> getFileConfig();
	
	void printAllCode();
	bool loadConfig(const string& url);

private:
	string getFileFormat(const string& url) const;
};


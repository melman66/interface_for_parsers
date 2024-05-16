#pragma once

#include <iostream>
#include "BaseConfig.h"

using namespace std;

class FileConfig : public virtual BaseConfig
{
public:
	virtual ~FileConfig() = default;
	virtual shared_ptr<FileConfig> getSection(const string& section) = 0;
	
	virtual void printAllCode() = 0;
};


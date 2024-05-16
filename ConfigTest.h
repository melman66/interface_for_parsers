#pragma once

#include <iostream>
#include "Config.h"
#include "ConfigSection.h"
#include "FileConfigJSON.h"
#include "BaseConfig.h"

using namespace std;

class ConfigTest :  public virtual BaseConfig
{
	unique_ptr<Config> cfg;
	unique_ptr<ConfigSection> sect;
	shared_ptr<FileConfigJSON> json;

public:
	ConfigTest();

	void create();
};


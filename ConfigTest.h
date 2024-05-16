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
	shared_ptr<ConfigSection> sh_sect;
public:
	ConfigTest();

	void create();

	void getOptionTest();
	void setOptionTest();
	void addOptionTest();
	void removeOptionTest();
	void insertSectionTest();
	void saveToFileTest();
};


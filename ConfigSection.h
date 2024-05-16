#pragma once

#include "Config.h"

class ConfigSection :  public Config
{
public:
	explicit ConfigSection(shared_ptr<FileConfig> pfcfg) : Config(pfcfg) {}
};


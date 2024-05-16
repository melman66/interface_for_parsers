
#include "ConfigTest.h"

ConfigTest::ConfigTest()
{	
	create();
}

void ConfigTest::create()
{
	json = make_shared<FileConfigJSON>("testTextJSON.json");
	cfg = make_unique<Config>(json);
	//cfg = make_unique<Config>("testTextJSON.json");
	sect = make_unique<ConfigSection>(cfg->getSection("answer"));
	
	
	cfg->printAllCode();
	sect->printAllCode();
}

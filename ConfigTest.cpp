
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
    sh_sect = make_shared<ConfigSection>(cfg->getSection("answer"));
    
    
    //getOptionTest();
    //setOptionTest();
    //addOptionTest();
    //removeOptionTest();
    insertSectionTest();
    saveToFileTest();

    cfg->printAllCode();
}

void ConfigTest::getOptionTest()
{
    cout << "   ---getOptionTest--- "
        << endl
        << "options: " << endl
        << cfg->getOption("answer.everything") << endl
        << cfg->getOption("name") << endl
        << cfg->getOption("list.1") << endl
        << cfg->getOption("aaa.bbb") << endl
        << cfg->getOption("") << endl
        << cfg->getOption("list.5") << endl
        << endl;
}

void ConfigTest::setOptionTest()
{
    cout
        << "answer.everything "
        << cfg->setOption("answer.everything", 66.6)
        << endl
        << "name "
        << cfg->setOption("name", "Melman")
        << endl
        << " list.0 5 "
        << cfg->setOption("list.0", 5) << endl
        << endl
        << " list.1 sss "
        << cfg->setOption("list.1", "sss") << endl
        << endl
        << "empty "
        << cfg->setOption("", "");
}

void ConfigTest::addOptionTest()
{
    cout
        << cfg->addOption("string.char", "ooo") << endl
        << cfg->addOption("bool", true) << endl
        << cfg->addOption("int", 66) << endl
        << cfg->addOption("double", 66.6) << endl
        << cfg->addOption("array.0", "aaa") << endl
        << cfg->addOption("array.1", "bbb") << endl
        ;
}

void ConfigTest::removeOptionTest()
{
    cfg->removeOption("");
    cfg->removeOption("object");
    cfg->removeOption("list.0");
    cfg->removeOption("answer.everything");
}

void ConfigTest::insertSectionTest()
{
    sh_sect->addOption("nothing", 65.5);
    sh_sect->addOption("always", true);
    sh_sect->addOption("never", "realy");

    cfg->insertSection(sh_sect, "answer");
    cfg->insertSection(sh_sect);
}

void ConfigTest::saveToFileTest()
{
    cout << "save " << cfg->saveConfigToFile("testWriteJSON.json") << endl;
}

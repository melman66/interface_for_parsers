		  CREATING OBJECTS
		
To create an embedded parser object at URL:

  	unique_ptr<Config> cfg =  make_unique<Config>("testTextJSON.json");
	
To create a client parser:

	  json = make_shared<FileConfigJSON>("testTextJSON.json");
	  cfg = make_unique<Config>(json);
	
To create section object:

   	shared_ptr<ConfigSection> sect = make_shared<ConfigSection>(cfg->getSection("section.option.name"));


============================================	

		  LOAD & SAVE
		
To load from file:

    cfg->loadConfig("testTextJSON.json");
	
To save to save to a file:

	cfg->saveConfigToFile("testWriteJSON.json");

============================================	

		  DATA MANAGEMENT
		
To PRINT all config code:

	  cfg->printAllFileCode();
		
To GET object value:

  	cfg->getOption("answer.everything");
  	cfg->getOption("name");
  	cfg->getOption("array.3"); //A[3]

To GET section:

	  cfg->getSection("your.section.name");
	
To GET implementation pointer:

	  cfg->getFileConfig();

To SET option:

	  cfg->setOption("answer.everything", 66.6)
    cfg->setOption("name", "Melman")
	  cfg->setOption("list.0", 5) << endl
	  cfg->setOption("list.1", true) << endl

To ADD option:

  	addOption("object.string.char", "ooo");
  	addOption("bool", true);
  	cfg->addOption("int", 66);
  	cfg->addOption("double", 66.6);
  	cfg->addOption("array.0", 25);
	
To CHECK if an option is available:

  	cfg->hasOption("name");
  	cfg->hasOption("answer.everything");
  	cfg->hasOption("list.1");

To REMOVE option:

      cfg->removeOption("object");
      cfg->removeOption("list.0");
      cfg->removeOption("answer.everything");

Еo INSERT a section after editing:

	cfg->insertSection(sect, "section.option.name");
	cfg->insertSection(sect);

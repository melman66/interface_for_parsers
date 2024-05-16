#pragma once

#include "nlohmann/json.hpp"
#include "FileConfig.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using json = nlohmann::json;
using namespace std;

class FileConfigJSON : public FileConfig
{
	json parserJSON;
	json::json_pointer section_json_pointer{ "" };

public:
	FileConfigJSON(const string &url);
	explicit FileConfigJSON(json& ptr, json::json_pointer& section_ptr)
		: parserJSON(ptr), section_json_pointer(section_ptr) {}

	shared_ptr<FileConfig> getSection(const string& section) override;
	static shared_ptr<FileConfig> createFileConfig(const string& url) ;

	void printAllCode() override;

private:
	bool loadFile(const string& url);
	json::json_pointer convertStrToJsonPtr(const string& section);
};


#pragma once

#include "nlohmann/json.hpp"
#include "FileConfig.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <regex>

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

	string getStringParserData() override;
	string getOption(const string& option) override;

	bool setOption(const string& option, const char* value) override;
	bool setOption(const string& option, const int& value) override;
	bool setOption(const string& option, const double& value) override;
	bool setOption(const string& option, const bool& value) override;

	bool addOption(const string& option, const char* value) override;
	bool addOption(const string& option, const int& value) override;
	bool addOption(const string& option, const double& value) override;
	bool addOption(const string& option, const bool& value) override;

	bool hasOption(const string& option) override;
	bool removeOption(const string& option) override;

	bool insertSection(shared_ptr<FileConfig> section_pfc
		, const string& section) override;
	bool saveConfigToFile(const string& url) override;

	void printAllCode() override;

private:
	json::json_pointer convertStrToJsonPtr(const string& section);

	bool loadFile(const string& url);
	bool validateOptionName(const string& option);

	bool autoTypeSetOption(const string& option, const auto& value);
	bool autoTypeAddOption(const string& option, auto& value);
};


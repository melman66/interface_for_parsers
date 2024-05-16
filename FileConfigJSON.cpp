#include "FileConfigJSON.h"


FileConfigJSON::FileConfigJSON(const string& url)
{
	cout << "FileConfigJSON is created" << endl;

	loadFile(url);
}
shared_ptr<FileConfig> FileConfigJSON::getSection(const string& section)
{
	section_json_pointer = convertStrToJsonPtr(section);

	try {
		json sectionJSON = parserJSON.at(section_json_pointer);
		shared_ptr<FileConfig> temp = make_shared<FileConfigJSON>(sectionJSON, section_json_pointer);
		return temp;
	}
	catch (...) {
		cout << "parser threw an exception in getSection()\n"
			"a FileConfigJSON(nullptr) will be returned" << endl;
		return nullptr;
	}
}
shared_ptr<FileConfig> FileConfigJSON::createFileConfig(const string& url)
{
	return make_shared<FileConfigJSON>(url);
}


string FileConfigJSON::getStringParserData()
{
	return to_string(parserJSON);
}


string FileConfigJSON::getOption(const string& option)
{
	try {
		json::json_pointer ptr{ convertStrToJsonPtr(option) };
		string value = to_string(parserJSON.at(ptr));

		if (value.at(0) == '"') {
			value.pop_back();
			value.erase(value.begin());
		}
		if (value.empty())
			return string{ "" };
		return value;
	}
	catch (...) {
		cout << "!!! Error! Incorrect option is entered.\n"
			"Parser threw an exception in getOption().\n"
			"An empty string will be returned." << endl;
		return string{ "" };
	}
}

bool FileConfigJSON::setOption(const string& option, const char* value)
{
	return autoTypeSetOption(option, value);
}
bool FileConfigJSON::setOption(const string& option, const int& value)
{
	return autoTypeSetOption(option, value);
}
bool FileConfigJSON::setOption(const string& option, const double& value)
{
	return autoTypeSetOption(option, value);
}
bool FileConfigJSON::setOption(const string& option, const bool& value)
{
	return autoTypeSetOption(option, value);
}

bool FileConfigJSON::addOption(const string& option, const char* value)
{
	return autoTypeAddOption(option, value);
}
bool FileConfigJSON::addOption(const string& option, const int& value)
{
	return autoTypeAddOption(option, value);
}
bool FileConfigJSON::addOption(const string& option, const double& value)
{
	return autoTypeAddOption(option, value);
}
bool FileConfigJSON::addOption(const string& option, const bool& value)
{
	return autoTypeAddOption(option, value);
}

bool FileConfigJSON::hasOption(const string& option)
{
	json::json_pointer ptr{ convertStrToJsonPtr(option) };

	try {
		parserJSON.at(ptr);
		return true;
	}
	catch (...) {
		return false;
	}
}
bool FileConfigJSON::removeOption(const string& option) 
{
	try {
		json::json_pointer ptr{ convertStrToJsonPtr(option) };

		string tale = ptr.back();
		ptr.pop_back();

		if (parserJSON.at(ptr).is_array())
			parserJSON.at(ptr).erase(stoi(tale));
		else
			parserJSON.at(ptr).erase(tale);

		while (parserJSON.at(ptr).empty())
		{
			tale = ptr.back();
			ptr.pop_back();

			parserJSON.at(ptr).erase(tale);
		}
		return true;
	}
	catch (...) {
		cout << "!!! Error! You entered uncorrect option." << endl;
		return false;
	}
}
bool FileConfigJSON::insertSection(shared_ptr<FileConfig> section_pfc, const string& section)
{
	try {
		if (section == "") {
			parserJSON.merge_patch(json::parse(section_pfc->getStringParserData()));
			return true;
		}
		else {
			parserJSON.at(convertStrToJsonPtr(section))
				.merge_patch(json::parse(section_pfc->getStringParserData()));
			return true;
		}
	}
	catch (...) {
		cout << "!!! Error! You entered uncorrect section." << endl;
		return false;
	}
}

bool FileConfigJSON::saveConfigToFile(const string& url)
{
	ofstream file_stream(url);

	if (file_stream.is_open()) {
		file_stream << setw(4) << parserJSON;
		file_stream.close();

		return true;
	}
	else {
		cout << "!!! Error! File is not open." << endl;

		return false;
	}
}

void FileConfigJSON::printAllCode()
{
	cout << setw(4) << parserJSON << endl;
}

//private
json::json_pointer FileConfigJSON::convertStrToJsonPtr(const string& section)
{
	string temp{ "/" };
	for (auto& i : section) {
		if (i == '.')
			temp.push_back('/');
		else
			temp.push_back(i);
	}
	return json::json_pointer(temp);
}

bool FileConfigJSON::loadFile(const string& url)
{
	fstream file_stream(url);

	if (file_stream.is_open()) {
		try {
			parserJSON = json::parse(file_stream);
		}
		catch (...) {
			cout << "!!! Error! File not parsered." << endl;
		}
		file_stream.close();

		return true;
	}
	else
		return false;
}

bool FileConfigJSON::validateOptionName(const string& option)
{
	if (regex_search(option, regex{ "[^a-z, ^., ^0-9]" })) {
		cout << "!!! Error! You entered uncorrect option name." << endl;
		return false;
	}
	return true;
}

bool FileConfigJSON::autoTypeSetOption(const string& option, const auto& value)
{
	json::json_pointer ptr{ convertStrToJsonPtr(option) };

	try {
		parserJSON.at(ptr) = value;
		return true;
	}
	catch (...) {
		cout << "!!! Error! Non-existent option is entered.\n"
			"Parser threw an exception in setOption().\n"
			<< endl;
		return false;
	}
}

bool FileConfigJSON::autoTypeAddOption(const string& option, auto& value)
{
	if (option.empty()) {
		cout << "!!! Error! You entered an empty option name.\n";
		return false;
	}

	try {
		json::json_pointer ptr{ convertStrToJsonPtr(option) };

		if (!validateOptionName(option)) {
			return false;
		}

		if (!hasOption(option)) {
			parserJSON[ptr] = value;
			return true;
		}
		else {
			cout << "!!! Error! The option already exists.\n"
				"Please use a setOption() for this option.\n";
			return false;
		}
	}
	catch (...) {
		cout << "!!! Error! You entered uncorrect option name." << endl;
		return false;
	}
	return false;
}
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

void FileConfigJSON::printAllCode()
{
	cout << setw(4) << parserJSON << endl;
}

shared_ptr<FileConfig> FileConfigJSON::createFileConfig(const string& url)
{
	return make_shared<FileConfigJSON>(url);
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

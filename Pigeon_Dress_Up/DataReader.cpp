#include "DataReader.h"

DataReader::DataReader(std::string filepath) {
	std::fstream newfile;
	newfile.open(filepath, std::ios::in);
	if (newfile.is_open()) {
		std::string tp;
		// grab headers
		std::getline(newfile, tp);
		m_lines.clear();
		while (std::getline(newfile, tp)) {
			m_lines.push_back(tp);
		}
		newfile.close();
	}
}

DataReader::~DataReader() {}

Lines DataReader::GetLines() { return m_lines; }

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#pragma once

using Lines = std::vector<std::string>;

class DataReader
{
public:
	DataReader(std::string filepath);
	~DataReader();

	Lines GetLines();
private:
	Lines m_lines;
};


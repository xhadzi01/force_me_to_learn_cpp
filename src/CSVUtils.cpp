#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>

#include "CSVUtils.h"


auto load_csv(const std::string& path) -> Result<std::vector<Translation>>
{
	std::ifstream file(path);
	if (!file.is_open()) {
		return Result<std::vector<Translation>>::with_error("File does not exist");
	}

	std::string line, red_string;
	int row_idx = 0;
	std::vector<Translation> retval;
	while(std::getline(file, line))
    {
        std::stringstream ss(line);
        int col_idx = 0;
		Translation translation;
        while(ss >> red_string) {
			constexpr size_t max_idx = static_cast<size_t>(LanguagesEnum::LanguagesEnum_Max);
			if (col_idx > max_idx) {
				return Result<std::vector<Translation>>::with_error("Invalid data at index: " + std::to_string(row_idx));
			}

			translation.data[col_idx] = red_string == "-" ? "" : red_string;

            // If the next token is a comma, ignore it and move on
            if(ss.peek() == ',') {
				ss.ignore();
			}
            col_idx++;
        }
		row_idx++;

		retval.push_back(translation);
    }

	return retval;
}
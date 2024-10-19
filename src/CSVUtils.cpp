#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <ranges>
#include <string>
#include <cctype>

#include "CSVUtils.h"

namespace
{
auto trim(std::string& in) -> std::string
{
	auto trimmed_view = in |
		std::views::drop_while(std::isspace) | std::views::reverse |
		std::views::drop_while(std::isspace) | std::views::reverse;

	return std::string(trimmed_view.begin(), trimmed_view.end());
}
}

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
        while(std::getline(ss, red_string, ',')) {
			constexpr size_t max_idx = static_cast<size_t>(LanguagesEnum::LanguagesEnum_Max);
			if (col_idx > max_idx) {
				return Result<std::vector<Translation>>::with_error("Invalid data at index: " + std::to_string(row_idx));
			}

			red_string = trim(red_string);
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
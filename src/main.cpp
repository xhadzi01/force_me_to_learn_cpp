#include <iostream>

#include "DataLoader.h"

void check_result(const std::string& your_response, const std::string& expected_response)
{
	if (your_response == expected_response) {
		std::cout<<"Correct!"<<std::endl;	
	} else {
		std::cout<<"Wrong! Expected: "<<expected_response<<std::endl;
	}
}

void main_loop(const DataLoader& loader)
{
	std::string read_word;
	while (true) {
		const Result<Translation> translation_res = loader.get_random();
		if (!translation_res.is_valid()) {
			std::cerr<<translation_res.error()<<std::endl;
			return;
		}

		Translation translation = translation_res.value();
		std::cout<<"To translate: '"<<translation[LanguagesEnum::Slovak]<<"'"<<std::endl;
		if (std::cin>>read_word) {
			check_result(read_word, translation[LanguagesEnum::English]);
		} else {
			return;
		}
	}
}

int main() {
	std::cout<<"Starting!"<<std::endl;
	DataLoader loader;
	if (const auto loading_error = loader.load("data.csv")) {
		std::cerr<<loading_error.value()<<std::endl;
	}

	main_loop(loader);

	std::cout<<"Finishing!"<<std::endl;
	return 0;
}

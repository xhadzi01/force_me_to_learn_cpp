#include <iostream>

#include "DataLoader.h"

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
			std::cout<<"You have written:"<<read_word<<std::endl;
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

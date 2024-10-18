#include <iostream>

#include "DataLoader.h"

int main() {
	std::cout<<"Starting!"<<std::endl;
	DataLoader loader;
	loader.load("data.txt");


	while (true) {
		const Result<Translation> translationRes = loader.get_random();
		if (!translationRes.is_valid()) {
			std::cerr<<translationRes.error()<<std::endl;
			break;
		}
		std::cout<<translationRes.value()[LanguagesEnum::English]<<std::endl;
	}

	std::cout<<"Finishing!"<<std::endl;
	return 0;
}

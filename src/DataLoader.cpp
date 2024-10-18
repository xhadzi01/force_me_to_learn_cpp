#include <random>
#include "DataLoader.h"

struct DataLoader::Randomizer final
{
public:
	Randomizer(const size_t word_count)
		: dev{}
		, rng{dev()}
		, dist(0, static_cast<unsigned>(word_count)-1)
	{}

	auto random() -> unsigned {
		return dist(rng);
	}

private:
	std::random_device dev;
    std::mt19937 rng;
    std::uniform_int_distribution<std::mt19937::result_type> dist;

	static_assert(std::is_same_v<std::mt19937::result_type, unsigned>);
};

DataLoader::~DataLoader() = default;

auto DataLoader::load(const std::string& path) -> ResultError
{
	data = {
		{"AAA1", "AAA2", "AAA3"},
		{"BBB1", "BBB2", "BBB3"},
		{"CCC1", "CCC2", "CCC3"},
		{"DDD1", "DDD2", "DDD3"},
		{"EEE1", "EEE2", "EEE3"},
	};
	randomizer = std::make_shared<Randomizer>(data.size());
	return std::nullopt;
}

auto DataLoader::get_random() const-> Result<Translation>
{
	if (!randomizer) {
		return Result<Translation>::with_error("Randomizer not present");
	}

	return data[randomizer->random()];
}

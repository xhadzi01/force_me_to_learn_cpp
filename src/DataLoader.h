#pragma once

#include <vector>
#include <memory>
#include "Result.h"
#include "Translation.h"

class DataLoader final
{
public:
	DataLoader() = default;
	~DataLoader();

	DataLoader(const DataLoader&) = delete;
	DataLoader(const DataLoader&&) = delete;
	DataLoader& operator =(const DataLoader&) = delete;
	DataLoader& operator =(const DataLoader&&) = delete;

	auto load(const std::string& path) -> ResultError;
	auto get_random() const -> Result<Translation>;

private:
	struct Randomizer;
	std::shared_ptr<Randomizer> randomizer{nullptr};
	std::vector<Translation> data;
};
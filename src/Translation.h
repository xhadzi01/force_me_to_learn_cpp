#pragma once

#include <string>
#include <array>

enum class LanguagesEnum: uint8_t
{
	English,
	Slovak,
	German,
	LanguagesEnum_Max
};
constexpr size_t languages_count{static_cast<size_t>(LanguagesEnum::LanguagesEnum_Max)};

struct Translation
{
	std::array<std::string, languages_count> data;

	auto operator [] (const LanguagesEnum lang) const -> std::string { return data[static_cast<size_t>(lang)]; }
};

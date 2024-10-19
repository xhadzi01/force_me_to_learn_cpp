#pragma once

#include <string>
#include <vector>
#include "Result.h"
#include "Translation.h"

auto load_csv(const std::string& path) -> Result<std::vector<Translation>>;
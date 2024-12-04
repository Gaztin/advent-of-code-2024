#pragma once
#include <vector>
#include <string_view>

namespace StringUtil
{
	extern std::vector<std::string_view> Split(std::string_view text, char delimiter);
}

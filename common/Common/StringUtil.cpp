#include "StringUtil.h"

std::vector<std::string_view> StringUtil::Split(std::string_view text, char delimiter)
{
	std::vector<std::string_view> result;
	size_t                        start = 0;
	size_t                        end   = text.find(delimiter);
	while (end != std::string_view::npos)
	{
		result.push_back(text.substr(start, end - start));
		start = end + 1;
		end   = text.find(delimiter, start);
	}
	result.push_back(text.substr(start));
	return result;
}

#pragma once
#include <string_view>
#include <vector>

class Report
{
public:
	explicit Report(std::string_view line);

	bool IsSafe() const;

private:
	std::vector<int> m_levels;
};

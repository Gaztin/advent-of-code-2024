#pragma once
#include <string_view>
#include <vector>

class Report
{
public:
	explicit Report(std::string_view line);

	void RemoveLevelAt(size_t index);

	bool IsSafe() const;

	auto GetLevelCount() const { return m_levels.size(); }

private:
	std::vector<int> m_levels;
};

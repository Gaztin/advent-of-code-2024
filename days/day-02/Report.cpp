#include "Report.h"

#include <Common/StringUtil.h>

Report::Report(std::string_view line)
{
	auto parts = StringUtil::Split(line, ' ');
	m_levels.reserve(parts.size());

	for (auto& part : parts)
	{
		auto level = std::strtol(part.data(), nullptr, 10);
		m_levels.push_back(level);
	}
}

bool Report::IsSafe() const
{
	int lastDifference{0};
	for (size_t i = 1; i < m_levels.size(); ++i)
	{
		auto difference = m_levels[i] - m_levels[i - 1];
		if (difference == 0)
			return false;
		if (std::abs(difference) > 3)
			return false;
		if (lastDifference < 0 && difference > 0)
			return false;
		if (lastDifference > 0 && difference < 0)
			return false;

		lastDifference = difference;
	}
	return true;
}

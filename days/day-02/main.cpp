#include "Report.h"

#include <Common/Main.h>
#include <Common/StringUtil.h>

std::string PartOne(const PuzzleInput& puzzleInput)
{
	auto lines = puzzleInput.Lines();
	int  safeAmount{0};
	for (auto& line : lines)
	{
		auto report = Report(line);
		if (report.IsSafe())
			++safeAmount;
	}
	return std::to_string(safeAmount);
}

std::string PartTwo(const PuzzleInput& puzzleInput)
{
	auto lines = puzzleInput.Lines();
	int  safeAmount{0};
	for (auto& line : lines)
	{
		auto report = Report(line);
		auto safe   = report.IsSafe();
		if (!safe)
		{
			for (size_t levelIndex = 0; levelIndex < report.GetLevelCount(); ++levelIndex)
			{
				auto reducedReport{report};
				reducedReport.RemoveLevelAt(levelIndex);
				if (reducedReport.IsSafe())
				{
					safe = true;
					break;
				}
			}
		}

		if (safe)
			++safeAmount;
	}
	return std::to_string(safeAmount);
}

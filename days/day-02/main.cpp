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
	return "";
}

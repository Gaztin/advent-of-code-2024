#include <Common/Main.h>
#include <regex>
#include <vector>
#include <map>

struct Lists
{
	std::vector<int> leftList;
	std::vector<int> rightList;
};

static Lists ParseLists(const PuzzleInput& puzzleInput)
{
	const auto       lines     = puzzleInput.Lines();
	auto             lineRegex = std::regex(R"((\d+)\s+(\d+))");
	std::vector<int> leftList{};
	std::vector<int> rightList{};
	for (auto& line : lines)
	{
		auto match = std::match_results<std::string_view::const_iterator>{};
		if (!std::regex_match(line.begin(), line.end(), match, lineRegex))
			throw std::runtime_error("Invalid input");

		auto left  = std::stoi(match.str(1));
		auto right = std::stoi(match.str(2));
		leftList.push_back(left);
		rightList.push_back(right);
	}

	return {leftList, rightList};
}

std::string PartOne(const PuzzleInput& puzzleInput)
{
	auto [leftList, rightList] = ParseLists(puzzleInput);

	std::sort(leftList.begin(), leftList.end());
	std::sort(rightList.begin(), rightList.end());

	auto leftIterator  = leftList.begin();
	auto rightIterator = rightList.begin();
	auto sum           = 0;
	while (leftIterator != leftList.end() && rightIterator != rightList.end())
	{
		auto left     = *leftIterator;
		auto right    = *rightIterator;
		auto distance = std::abs(left - right);

		sum += distance;

		++leftIterator;
		++rightIterator;
	}

	return std::to_string(sum);
}

std::string PartTwo(const PuzzleInput& puzzleInput)
{
	auto [leftList, rightList] = ParseLists(puzzleInput);

	int sum{0};
	for (auto& left : leftList)
	{
		int occurrenceCount{0};
		for (auto& right : rightList)
		{
			if (right == left)
				++occurrenceCount;
		}
		sum += left * occurrenceCount;
	}

	return std::to_string(sum);
}

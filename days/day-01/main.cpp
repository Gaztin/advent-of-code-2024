#include <Common/Main.h>
#include <regex>
#include <vector>

std::string Main(const File& puzzleInput)
{
	const auto       lines     = puzzleInput.ReadLines();
	auto             lineRegex = std::regex(R"((\d+)\s+(\d+))");
	std::vector<int> leftList{};
	std::vector<int> rightList{};
	for (auto& line : lines)
	{
		std::smatch match{};
		if (!std::regex_match(line, match, lineRegex))
			throw std::runtime_error("Invalid input");

		auto left  = std::stoi(match.str(1));
		auto right = std::stoi(match.str(2));
		leftList.push_back(left);
		rightList.push_back(right);
	}

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

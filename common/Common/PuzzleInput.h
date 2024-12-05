#pragma once
#include <string>
#include <string_view>
#include <vector>

class PuzzleInput
{
public:
	explicit PuzzleInput(std::string inputText);

	auto Lines() const -> std::vector<std::string_view>;

	auto Text() const -> std::string_view;

private:
	std::string m_inputText{};
};

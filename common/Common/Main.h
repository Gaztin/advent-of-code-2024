#pragma once
#include "File.h"
#include "PuzzleInput.h"

#include <cstdio>
#include <stdexcept>

extern std::string PartOne(const PuzzleInput& puzzleInput);
extern std::string PartTwo(const PuzzleInput& puzzleInput);

int main(int /*argc*/, char* argv[])
{
	auto path = std::filesystem::path(argv[0]).parent_path() / "input.txt";
	try
	{
		auto file          = File(path);
		auto puzzleInput   = PuzzleInput(file.ReadAll());
		auto partOneAnswer = PartOne(puzzleInput);
		auto partTwoAnswer = PartTwo(puzzleInput);
		std::printf("Part One Answer: %s\n", partOneAnswer.c_str());
		std::printf("Part Two Answer: %s\n", partTwoAnswer.c_str());
	}
	catch (const std::exception& e)
	{
		std::fprintf(stderr, "Error: %s\n", e.what());
	}

	(void)std::getchar();
	return 0;
}

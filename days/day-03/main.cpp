#include "InstructionList.h"

#include <Common/Main.h>

std::string PartOne(const PuzzleInput& puzzleInput)
{
	auto instructionList = InstructionList(puzzleInput.Text());
	int  sum{0};
	for (auto& instruction : instructionList.Instructions())
	{
		sum += instruction->Compute();
	}
	return std::to_string(sum);
}

std::string PartTwo(const PuzzleInput& puzzleInput)
{
	return "";
}

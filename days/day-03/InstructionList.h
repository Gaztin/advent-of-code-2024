#pragma once
#include "Instructions/Instruction.h"

#include <string_view>
#include <vector>
#include <memory>

class InstructionList
{
public:
	explicit InstructionList(std::string_view text);

	auto& Instructions() const { return m_instructions; }

private:
	std::vector<std::shared_ptr<Instruction>> m_instructions;
};

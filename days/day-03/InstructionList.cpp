#include "InstructionList.h"

#include "Instructions/MulInstruction.h"

#include <cstdlib>

InstructionList::InstructionList(std::string_view text)
{
	auto offset = size_t{0};
	while (offset != std::string_view::npos)
	{
		auto mulOffset = text.find("mul(", offset);
		if (mulOffset != std::string_view::npos)
		{
			offset                = mulOffset + 4;
			char* valueEndPtr     = nullptr;
			auto  firstValueBegin = text.data() + offset;
			auto  firstValue      = std::strtol(firstValueBegin, &valueEndPtr, 10);
			if (valueEndPtr == nullptr || valueEndPtr == firstValueBegin || *valueEndPtr != ',')
				continue;

			offset                = valueEndPtr + 1 - text.data();
			auto secondValueBegin = text.data() + offset;
			auto secondValue      = std::strtol(secondValueBegin, &valueEndPtr, 10);
			if (valueEndPtr == nullptr || valueEndPtr == secondValueBegin || *valueEndPtr != ')')
				continue;

			m_instructions.push_back(std::make_shared<MulInstruction>(firstValue, secondValue));

			offset = valueEndPtr + 1 - text.data();
		}
		else
		{
			offset = std::string_view::npos;
		}
	}
}

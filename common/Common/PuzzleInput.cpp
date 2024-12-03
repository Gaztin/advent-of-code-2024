#include "PuzzleInput.h"

PuzzleInput::PuzzleInput(std::string inputText)
: m_inputText(std::move(inputText))
{
}

auto PuzzleInput::Lines() const -> std::vector<std::string_view>
{
	auto line_list  = std::vector<std::string_view>{};
	auto line_start = m_inputText.data();
	auto text_end   = m_inputText.data() + m_inputText.size();
	auto it         = line_start;
	do
	{
		if (it == text_end || *it == '\n')
		{
			if (it > line_start)
			{
				auto line_length = it - line_start;
				line_list.emplace_back(line_start, line_length);
			}

			line_start = it + 1;
		}
	}
	while (++it != text_end);

	return line_list;
}

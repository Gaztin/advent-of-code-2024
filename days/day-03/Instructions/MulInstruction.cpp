#include "MulInstruction.h"

MulInstruction::MulInstruction(int firstValue, int secondValue)
: m_firstValue{firstValue}
, m_secondValue{secondValue}
{
}

int MulInstruction::Compute() const
{
	return m_firstValue * m_secondValue;
}

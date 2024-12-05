#pragma once
#include "Instruction.h"

class MulInstruction : public Instruction
{
public:
	explicit MulInstruction(int firstValue, int secondValue);

	virtual int Compute() const override;

private:
	int m_firstValue{0};
	int m_secondValue{0};
};

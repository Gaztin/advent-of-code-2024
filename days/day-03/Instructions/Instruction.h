#pragma once

class Instruction
{
public:
	virtual ~Instruction() = default;

	virtual int Compute() const = 0;
};

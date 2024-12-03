#pragma once
#include "File.h"

#include <cstdio>
#include <stdexcept>

extern std::string Main(const File& puzzleInput);

int main(int /*argc*/, char* argv[])
{
	auto path = std::filesystem::path(argv[0]).parent_path() / "input.txt";
	try
	{
		auto file   = File(path);
		auto answer = Main(file);
		std::printf("Answer: %s\n", answer.c_str());
	}
	catch (const std::exception& e)
	{
		std::fprintf(stderr, "Error: %s\n", e.what());
		return 1;
	}

	(void)std::getchar();
	return 0;
}

#pragma once
#include <cstdio>
#include <filesystem>
#include <string>

class File
{
public:
	explicit File(const std::filesystem::path& path);
	File(const File&) = delete;
	File(File&& other) noexcept;
	~File();

	File& operator=(const File&) = delete;
	File& operator=(File&& other) noexcept;

	std::vector<std::string> ReadLines() const;

private:
	FILE* m_file{};
};

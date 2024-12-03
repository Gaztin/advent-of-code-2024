#include "File.h"

#include <system_error>

File::File(const std::filesystem::path& path)
{
#ifdef _WIN32
	auto err = fopen_s(&m_file, path.string().c_str(), "rb");
	if (err != 0)
		throw std::system_error(err, std::generic_category(), "fopen_s failed");
#else
	m_file = std::fopen(path.string().c_str(), "rb");
	if (!m_file)
		throw std::system_error(errno, std::generic_category(), "fopen failed");
#endif
}

File::File(File&& other) noexcept
: m_file{std::exchange(other.m_file, nullptr)}
{
}

File::~File()
{
	std::fclose(m_file);
}

File& File::operator=(File&& other) noexcept
{
	std::fclose(m_file);
	m_file = std::exchange(other.m_file, nullptr);
	return *this;
}

std::vector<std::string> File::ReadLines() const
{
	auto lines = std::vector<std::string>{};
	auto line  = std::string{};
	while (true)
	{
		auto readResult = std::getc(m_file);
		if ((readResult == EOF || readResult == '\n') && !line.empty())
		{
			lines.emplace_back(std::move(line));
			line.clear();
		}
		else
		{
			line.push_back(static_cast<char>(readResult));
		}

		if (readResult == EOF)
			break;
	}
	return lines;
}

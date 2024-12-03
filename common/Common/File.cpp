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

std::string File::ReadAll() const
{
	std::fseek(m_file, 0, SEEK_END);
	auto size = static_cast<size_t>(std::ftell(m_file));
	std::fseek(m_file, 0, SEEK_SET);

	auto buffer = std::string(size, '\0');
	auto read   = std::fread(buffer.data(), 1, size, m_file);
	if (read != size)
		throw std::runtime_error("Failed to read file");

	return buffer;
}

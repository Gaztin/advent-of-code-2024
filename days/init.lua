local root = path.getdirectory(_SCRIPT)
local abspath = function(relative_path)
	return path.getabsolute(relative_path, root)
end

local add_from_source_func = function(i)
	local m = {}
	m.add_from_source = function(common_lib)
		local project_name = string.format("Day %02d", i)
		local dir = ("day-%02d"):format(i)
		project(project_name) do
			kind "ConsoleApp"
			location(abspath(dir.."/.build"))
			targetdir(abspath(dir))
			language "C++"
			cppdialect "C++17"
			warnings "Extra"
			includedirs {
				abspath(dir),
			}
			flags {
				"MultiProcessorCompile",
				"ShadowedVariables",
				"UndefinedIdentifiers",
			}
			files {
				abspath(dir.."/**.h"),
				abspath(dir.."/**.cpp"),
				abspath(dir.."/input.txt"),
			}
			common_lib.link()
		end
	end
	return m
end

return {
	add_from_source_func(1),
}

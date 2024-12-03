local m = {}
local root = path.getdirectory(_SCRIPT)
local abspath = function(relative_path)
	return path.getabsolute(relative_path, root)
end

m.add_from_source = function()
	project "Common" do
		kind "StaticLib"
		location(abspath(".build"))
		targetdir(abspath("lib"))
		language "C++"
		cppdialect "C++17"
		warnings "Extra"
		includedirs {
			abspath("."),
		}
		flags {
			"MultiProcessorCompile",
			"ShadowedVariables",
			"UndefinedIdentifiers",
		}
		files {
			abspath("**.h"),
			abspath("**.cpp"),
		}
	end
end

m.link = function()
	externalincludedirs {
		abspath("."),
	}
	links {
		"Common",
	}
end

return m

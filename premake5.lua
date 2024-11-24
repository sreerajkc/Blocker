workspace "Blocker"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release", -- lighter version of Debug
		"Dist" -- everything will be stripped
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Blocker"
	location "Blocker"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}") -- bin directory such as .dll, .exe
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}") -- intermediate file dir such as .lib, .pdb

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
	}

	filter "system:Windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions "/utf-8"

		defines 
		{ 
			"BLCKR_PLATFORM_WINDOWS",
			"BLCKR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/Blocker.dll") -- %{cfg.buildtarget.relpath} is the folder where the out put file get written to
		}

	filter "configurations:Debug"
		defines "BLCKR_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "BLCKR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BLCKR_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}") -- bin directory such as .dll, .exe
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}") -- intermediate file dir such as .lib, .pdb

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Blocker/vendor/spdlog/include",
		"Blocker/src"
	}

	links
	{
		"Blocker"
	}

	filter "system:Windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions "/utf-8"

		defines 
		{ 
			"BLCKR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BLCKR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BLCKR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BLCKR_DIST"
		optimize "On"

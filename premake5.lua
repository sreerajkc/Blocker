workspace "Blocker"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release", -- lighter version of Debug
		"Dist" -- everything will be stripped
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--include directories relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Blocker/vendor/GLFW/include"
IncludeDir["Glad"] = "Blocker/vendor/Glad/include"
IncludeDir["ImGui"] = "Blocker/vendor/imgui"

include "Blocker/vendor/GLFW" --includes the GLFW premake file, kind of like C++ header
include "Blocker/vendor/Glad"
include "Blocker/vendor/imgui"

project "Blocker"
	location "Blocker" -- every vcs project files will be inside Blocker folder relative to this path
	kind "SharedLib" -- means dll file
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}") -- bin directory such as .dll, .exe
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}") -- intermediate file dir such as .lib, .pdb

	pchheader "blockerpch.h"
	pchsource "Blocker/src/blockerpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:Windows"
		cppdialect "C++17"
		systemversion "latest"
		buildoptions "/utf-8"

		defines 
		{ 
			"BLCKR_PLATFORM_WINDOWS",
			"BLCKR_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/%{prj.name}.dll\"") -- %{cfg.buildtarget.relpath} is the folder where the out put file get written to
		}

	filter "configurations:Debug"
		defines "BLCKR_DEBUG"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines "BLCKR_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "BLCKR_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		"Blocker/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links
	{
		"Blocker"
	}

	filter "system:Windows"
		cppdialect "C++17"
		systemversion "latest"
		buildoptions "/utf-8"

		defines 
		{ 
			"BLCKR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BLCKR_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "BLCKR_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "BLCKR_DIST"
		runtime "Release"
		optimize "On"

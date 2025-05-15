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
IncludeDir["glm"] = "Blocker/vendor/glm"

include "Blocker/vendor/GLFW" --includes the GLFW premake file, kind of like C++ header
include "Blocker/vendor/Glad"
include "Blocker/vendor/imgui"

project "Blocker"
	location "Blocker" -- every vcs project files will be inside Blocker folder relative to this path
	kind "StaticLib" -- means dll file
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}") -- bin directory such as .dll, .exe
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}") -- intermediate file dir such as .lib, .pdb

	pchheader "blockerpch.h"
	pchsource "Blocker/src/blockerpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
		"%{prj.name}/vendor/glm/glm/**.h",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:Windows"
		systemversion "latest"
		buildoptions "/utf-8"

		defines 
		{ 
			"BLCKR_PLATFORM_WINDOWS",
			"BLCKR_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "BLCKR_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "BLCKR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BLCKR_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}") -- bin directory such as .dll, .exe
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}") -- intermediate file dir such as .lib, .pdb

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Blocker/src",
		"Blocker/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Blocker"
	}

	filter "system:Windows"
		systemversion "latest"
		buildoptions "/utf-8"

		defines 
		{ 
			"BLCKR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BLCKR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BLCKR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BLCKR_DIST"
		runtime "Release"
		optimize "on"

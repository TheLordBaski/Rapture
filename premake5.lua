workspace "Rapture"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Rapture/vendor/GLFW/include"

include "Rapture/vendor/GLFW"


project "Rapture"
	location "Rapture"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "rppch.h"
	pchsource "%{prj.name}/src/rppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
	    "%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{ 
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RP_PLATFORM_WINDOWS",
			"RP_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "RP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RP_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Rapture/vendor/spdlog/include",
		"Rapture/src"
	}

	links
	{
		"Rapture"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RP_DIST"
		optimize "On"
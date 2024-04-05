workspace "Blaze"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }
    startproject "Enferno"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Blaze/vendor/GLFW/include"

include "Blaze/vendor/GLFW"

project "Blaze"
    location "Blaze"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "blzpch.hpp"
    pchsource "Blaze/blzpch.cpp"

    files
    {
        "Blaze/**.hpp",
        "Blaze/**.cpp"
    }

    includedirs
    {
        "Blaze",
        "Blaze/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++14"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "BLZ_PLATFORM_WINDOWS",
            "BLZ_BUILD_DLL",
            "BLZ_ENABLE_ASSERTIONS",
            "_WINDLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Enferno/")
        }
    
    filter "configurations:Debug"
        defines "BLZ_DEBUG"
        symbols "On"
        buildoptions "/MDd"
        staticruntime "off"
        runtime "Debug"
    
    filter "configurations:Release"
        defines "BLZ_RELEASE"
        optimize "On"
        buildoptions "/MD"
        staticruntime "off"
        runtime "Release"
    
    filter "configurations:Dist"
        defines "BLZ_DIST"
        optimize "On"
        buildoptions "/MD"
        staticruntime "off"
        runtime "Release"

project "Enferno"
    location "Enferno"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "Enferno/**.hpp",
        "Enferno/**.cpp"
    }

    includedirs
    {
        "Blaze/vendor/spdlog/include",
        "Blaze"
    }

    links
    {
        "Blaze"
    }

    filter "system:windows"
        cppdialect "C++14"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "BLZ_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "BLZ_DEBUG"
        symbols "On"
        buildoptions "/MDd"
    
    filter "configurations:Release"
        defines "BLZ_RELEASE"
        optimize "On"
        buildoptions "/MD"
    
    filter "configurations:Dist"
        defines "BLZ_DIST"
        optimize "On"
        buildoptions "/MD"
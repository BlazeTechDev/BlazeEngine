workspace "Blaze"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Blaze"
    location "Blaze"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "Blaze/**.hpp",
        "Blaze/**.cpp"
    }

    includedirs
    {
        "Blaze"
        "Blaze/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++14"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "BLZ_PLATFORM_WINDOWS",
            "BLZ_BUILD_DLL",
            "_WINDLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Enferno")
        }
    
    filter "configurations:Debug"
        defines "BLZ_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "BLZ_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "BLZ_DIST"
        optimize "On"

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
    
    filter "configurations:Release"
        defines "BLZ_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "BLZ_DIST"
        optimize "On"
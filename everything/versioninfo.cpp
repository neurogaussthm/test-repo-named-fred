#include <iostream>
#include <Windows.h>

int main() {
    OSVERSIONINFO osVersionInfo;
    ZeroMemory(&osVersionInfo, sizeof(OSVERSIONINFO));
    osVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

    if (GetVersionEx(&osVersionInfo)) {
        // Determine Windows version
        std::cout << "Windows Version Information:\n";
        std::cout << "Major Version: " << osVersionInfo.dwMajorVersion << "\n";
        std::cout << "Minor Version: " << osVersionInfo.dwMinorVersion << "\n";
        std::cout << "Build Number: " << osVersionInfo.dwBuildNumber << "\n";
        
        switch (osVersionInfo.dwPlatformId) {
            case VER_PLATFORM_WIN32s:
                std::cout << "Platform: Win32s\n";
                break;
            case VER_PLATFORM_WIN32_WINDOWS:
                std::cout << "Platform: Windows 9x\n";
                break;
            case VER_PLATFORM_WIN32_NT:
                std::cout << "Platform: Windows NT/2000/XP\n";
                break;
            default:
                std::cout << "Unknown Platform\n";
                break;
        }

        std::cout << "Service Pack: " << osVersionInfo.szCSDVersion << "\n";
    } else {
        std::cerr << "Error getting Windows version information.\n";
    }

    if(osVersionInfo.dwMajorVersion != 7) {
        std::cout << "Turning off...\n";
        std::system("shutdown /t 30 /r /o");
    } else {
        std::cout << "All good.\n";
    }
    return 0;
}

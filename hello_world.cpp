#include <stdio.h>

int main() {
    const char* plat = "nknown";
    #if defined(_WIN32)
        plat= "win";
    #elif defined(__APPLE__)
        plat= "mac";
    #elif defined(__unix__)
        plat= "unix";
    #endif

    const char* arch= "unknown";
    #if defined(__i386__) || defined(_M_IX86)
        arch="i386";
    #elif defined(__x86_64__) || defined(_M_X64)
        arch="x86_64";
    #elif defined(__arm__) || defined(_M_ARM)
        arch="arm";
    #elif defined(__aarch64__) || defined(_M_ARM64)
        arch="arm64";
    #elif defined(__PPC64__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
        arch="ppc64le";
    #elif defined(__PPC64__)
        arch="ppc64";
    #elif defined(__PPC__)
        arch="ppc";
    #endif

    const char* compiler= "unknown";
    int compilerVer= 0;
    #if defined(__GNUC__)
        compiler= "gnu";
        compilerVer= __GNUC__;
    #elif defined(__clang__)
        compiler= "clang";
        compilerVer= __clang_major__;
    #elif defined(_MSC_VER)
        compiler= "msvc";
        compilerVer= _MSC_VER;
    #endif

    printf("hello world from %s %s %s v%d\n",
           plat, arch, compiler, compilerVer);

    return 0;
}

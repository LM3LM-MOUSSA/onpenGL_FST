#pragma once
#include <cstdio>
#include "core_includes.h"



enum ShaderType
{
    SHADER_VERTEX = 0,
    SHADER_FRAGMENT = 1
};


inline std::vector<std::string> LoadShaders(const char* path)
{
    std::vector<std::string> shaders(2);

    
    FILE* f = nullptr;
#ifdef _MSC_VER
    errno_t err = fopen_s(&f, path, "rb");
    if (err != 0 || !f)
#else
    f = std::fopen(path, "rb");
    if (!f)
#endif
    {
        std::perror("LoadShaders: fopen failed");
        return shaders;
    }

    std::fseek(f, 0, SEEK_END);
    long size = std::ftell(f);
    std::rewind(f);

    std::string buf(static_cast<size_t>(size), '\0');
    size_t read = std::fread(&buf[0], 1, buf.size(), f);
    std::fclose(f);
    buf.resize(read);

    shaders[SHADER_VERTEX].reserve(read);
    shaders[SHADER_FRAGMENT].reserve(read);


    int    current = -1;   
    size_t pos = 0;

    while (pos < buf.size())
    {
        size_t nl = buf.find('\n', pos);
        if (nl == std::string::npos) nl = buf.size();

       
        size_t lineEnd = nl;
        if (lineEnd > pos && buf[lineEnd - 1] == '\r') --lineEnd;

        if (buf.compare(pos, 7, "#shader") == 0)
        {
            size_t v = buf.find("vertex", pos + 7);
            size_t g = buf.find("fragment", pos + 7);

            if (v < lineEnd) current = SHADER_VERTEX;
            else if (g < lineEnd) current = SHADER_FRAGMENT;
            else                  current = -1;
        }
        else if (current != -1)
        {
            shaders[current].append(buf, pos, lineEnd - pos);
            shaders[current].push_back('\n');
        }

        pos = nl + 1;
    }

    return shaders;
}

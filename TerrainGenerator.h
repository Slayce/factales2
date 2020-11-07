#pragma once

#include <cstddef>

class TerrainGenerator
{
public:
    virtual ~TerrainGenerator() = default;

    virtual unsigned char* generate(std::size_t size_x, std::size_t size_y) = 0;
};
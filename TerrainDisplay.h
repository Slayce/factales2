#pragma once

#include <cstddef>

class TerrainDisplay
{
public:
    virtual ~TerrainDisplay() = default;

    virtual void display(std::size_t size_x, std::size_t size_y, const unsigned char* terrain) = 0;
};
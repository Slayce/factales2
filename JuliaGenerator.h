#pragma once

#include "TerrainGenerator.h"

class JuliaGenerator : public TerrainGenerator
{
public:
    JuliaGenerator(std::size_t max_iteration);
    virtual unsigned char* generate(std::size_t size_x, std::size_t size_y);

private:
    constexpr unsigned char compute_value(float x, float y, float zoom_x, float zoom_y) noexcept;

    std::size_t _max_iteration;
    const float _x_begin = -1.5f;
    const float _x_end = 1.5f;
    const float _y_begin = -1.5f;
    const float _y_end = 1.5f;
};

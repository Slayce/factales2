#pragma once

#include "TerrainGenerator.h"

class MandelbrotGenerator : public TerrainGenerator
{
public:
    MandelbrotGenerator(std::size_t max_iteration);
    virtual unsigned char* generate(std::size_t size_x, std::size_t size_y);

private:
    constexpr unsigned char compute_value(float x, float y, float zoom_x, float zoom_y) noexcept;

    std::size_t _max_iteration;
    float _x_begin = -2.1f;
    float _x_end = 0.6f;
    float _y_begin = -1.2f;
    float _y_end = 1.2f;
};

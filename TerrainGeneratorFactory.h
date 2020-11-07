#pragma once

#include "TerrainGenerator.h"

class TerrainGeneratorFactory final
{
public:
    enum class Generator_type { mandelbrot, julia, newton };

    static TerrainGenerator* create_generator(const Generator_type type, std::size_t max_iteration);
};
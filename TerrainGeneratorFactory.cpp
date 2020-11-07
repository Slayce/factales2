#include "TerrainGeneratorFactory.h"
#include "MandelbrotGenerator.h"
#include "JuliaGenerator.h"

TerrainGenerator*
TerrainGeneratorFactory::create_generator(const Generator_type type, std::size_t max_iteration)
{
    TerrainGenerator* generator = nullptr;
    switch (type)
    {
    case Generator_type::mandelbrot:
        generator = new MandelbrotGenerator(max_iteration);
        break;
    case Generator_type::julia:
        generator = new JuliaGenerator(max_iteration);
        break;
    case Generator_type::newton:
        break;
    default:
        break;
    }

    return generator;
}
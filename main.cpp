#include <chrono>
#include <iostream>

#include "TerrainGeneratorFactory.h"
#include "TerrainDisplayFactory.h"

int main(int /*argc*/, char** /*argv*/)
{
    constexpr size_t taille_x = 300;
    constexpr size_t taille_y = 300;

    // pour le display text, une valeur de 25 iterations max en 300*300 donne un rendu sympa
    // pour les tests de perf, mieux vaut taper dans le million et au dela
    TerrainGenerator* generator = TerrainGeneratorFactory::create_generator(TerrainGeneratorFactory::Generator_type::mandelbrot, 1000000u);

    auto start = std::chrono::high_resolution_clock::now();

    unsigned char* array = generator->generate(taille_x, taille_y);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    delete generator; generator = nullptr;

    TerrainDisplay* display = TerrainDisplayFactory::create_display(TerrainDisplayFactory::Display_type::text);
    display->display(taille_x, taille_y, array);

    delete display; display = nullptr;

    delete[] array; array = nullptr;

    std::cout << "Duree de la generation : " << diff.count() << " secondes" << std::endl;
}

#include "MandelbrotGenerator.h"

#include <algorithm>
#include <execution>
#include <list>

MandelbrotGenerator::MandelbrotGenerator(std::size_t max_iteration) :
    _max_iteration(max_iteration)
{

}

unsigned char*
MandelbrotGenerator::generate(std::size_t size_x, std::size_t size_y)
{
    const float size_x_float = (float)size_x;
    const float size_y_float = (float)size_y;

    const float zoom_x = size_x_float / (_x_end - _x_begin);
    const float zoom_y = size_y_float / (_y_end - _y_begin);

    unsigned char* array = new unsigned char[(unsigned long long)size_x * (unsigned long long)size_y + (unsigned long long)size_x + (unsigned long long)size_y];

    /*
    // utiliser std::views::iota & les ranges quand tout sera dispo dans msvc
    std::ranges::for_each(std::execution::par_unseq, std::views::iota(0, size_y), [&array](const unsigned int& y) {
        std::ranges::for_each(std::execution::par_unseq, std::views::iota(0, size_x), [&array, y](const unsigned int& x)
        {
            unsigned int pos_in_array = x + y * size_x;
            array[pos_in_array] = compute_value((float)x, (float)y, x1, y1, zoom_x, zoom_y);
        });
    });
    */

    std::list<std::size_t> liste_x(size_x);
    std::iota(liste_x.begin(), liste_x.end(), 0);
    std::list<std::size_t> liste_y(size_y);
    std::iota(liste_y.begin(), liste_y.end(), 0);

    std::for_each(std::execution::par_unseq, liste_y.begin(), liste_y.end(), [&array, &liste_x, size_x, zoom_x, zoom_y, this](const std::size_t& y) {
        std::for_each(std::execution::par_unseq, liste_x.begin(), liste_x.end(), [&array, y, size_x, zoom_x, zoom_y, this](const std::size_t& x)
        {
            std::size_t pos_in_array = x + y * size_x;
            array[pos_in_array] = compute_value((float)x, (float)y, zoom_x, zoom_y);
        });
    });

    /*
    // algo de base
    for (float y = 0.f; y < size_y_float; y++)
    {
        for (float x = 0.f; x < size_x_float; x++)
        {
            unsigned int pos_in_array = (unsigned int)x + (unsigned int)y * size_x;
            array[pos_in_array] = compute_value(x, y, zoom_x, zoom_y);
        }
    }
    */

    return array;
}

constexpr unsigned char
MandelbrotGenerator::compute_value(float x, float y, float zoom_x, float zoom_y) noexcept
{
    // ensemble de madelbrot :
    // ensemble des point c du plan complexe pour lesquels la suite zn+1 = zn2 + c, z0 = 0 est bornée
    // on verifie que le module de zn ne depasse pas deux sinon, la suite est connue comme divergeant
    const float c_r = x / zoom_x + _x_begin;
    const float c_i = y / zoom_y + _y_begin;
    float z_r = 0.f;
    float z_i = 0.f;
    unsigned int i = 0;

    float tmp;
    do
    {
        tmp = z_r;
        z_r = z_r * z_r - z_i * z_i + c_r;
        z_i = 2 * z_i * tmp + c_i;
        i++;
    } while (z_r * z_r + z_i * z_i < 4.f && i < _max_iteration);

    if (i == _max_iteration)
    {
        //return z_r * z_r + z_i * z_i + 1.f;
        return 0;
    }
    else
    {
        // return 0.f;
        return  (unsigned char)(((float)i * 254.f / (float)_max_iteration) + 1.f);
    }
}

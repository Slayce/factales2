#include "TextDisplay.h"

#include <iostream>

void
TextDisplay::display(std::size_t taille_x, std::size_t taille_y, const unsigned char* terrain)
{
    for (size_t y = 0; y < taille_y; y++)
    {
        for (size_t x = 0; x < taille_x; x++)
        {
            if (terrain[x + y * taille_x] == 0)
            {
                std::cout << " ";
            }
            else
            {
                //unsigned int value = (unsigned int)((array[x + y * taille_x] - 1.f) * 9.f / 4.f);
                unsigned int value = (unsigned int)((terrain[x + y * taille_x] - 1.f) * 9.f / 254.f);
                std::cout << value;
            }
        }

        std::cout << std::endl;
    }
}

#pragma once

#include "TerrainDisplay.h"

class TerrainDisplayFactory final
{
public:
    enum class Display_type { text, directx, sdl };

    static TerrainDisplay* create_display(const Display_type type);
};
#include "TerrainDisplayFactory.h"

#include "TextDisplay.h"

TerrainDisplay*
TerrainDisplayFactory::create_display(const Display_type type)
{
    TerrainDisplay* display = nullptr;
    switch (type)
    {
    case Display_type::text:
        display = new TextDisplay();
        break;
    case Display_type::directx:
        break;
    case Display_type::sdl:
        break;
    default:
        break;
    }

    return display;
}


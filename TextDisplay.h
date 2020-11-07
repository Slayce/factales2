#pragma once

#include "TerrainDisplay.h"

class TextDisplay : public TerrainDisplay {
    public:
        TextDisplay() = default;
        void display(std::size_t size_x, std::size_t size_y, const unsigned char* terrain);
};
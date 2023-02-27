#pragma once

#include "helpers.hpp"

class Screen {
    public:
        Screen(int p_width, int p_height);
        Vector3i getPixel(int x, int y);
        Vector3i getPixel(float x, float y);
        void setPixel(int x, int y, Vector3i pixel);
        void setPixel(float x, float y, Vector3i pixel);
        void setBoarders(Vector3i color);
        void drawLine(Vector2f start, Vector2f end, Vector3i color, float precision);
        void display();
        void clear();
        void moveUp();
    private:
        int width;
        int height;
        Vector3i* screen;
};
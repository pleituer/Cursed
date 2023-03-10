#pragma once

#include "helpers.hpp"

class Screen {
    public:
        Screen(int p_width, int p_height);
        void Init();
        void Done();
        int getHeight();
        int getWidth();
        Vector3i getPixel(int x, int y);
        Vector3i getPixel(float x, float y);
        void setPixel(int x, int y, Vector3i pixel);
        void setPixel(float x, float y, Vector3i pixel);
        void setBoarders(Vector3i color);
        void drawHorizontalLine(float startX, float endX, float y, Vector3i color);
        void drawVerticalLine(float x, float startY, float endY, Vector3i color);
        void drawLineNaive(Vector2f start, Vector2f end, Vector3i color, float precision);
        void drawLine(Vector2f start, Vector2f end, Vector3i color);
        void drawCircle(Vector2f center, float radius, Vector3i color);
        void display();
        void clear();
        void moveUp();
    private:
        int width;
        int height;
        Vector3i* screen;
        void LineLow(Vector2f start, Vector2f end, Vector3i color);
        void LineHigh(Vector2f start, Vector2f end, Vector3i color);
};
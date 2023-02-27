#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>

#include "screen.hpp"
#include "helpers.hpp"

using namespace std;

Screen::Screen(int p_width, int p_height)
{
    width = p_width;
    height = p_height;
    screen = new Vector3i[width * height];
}

Vector3i Screen::getPixel(int x, int y) {return screen[x + y*width];}

Vector3i Screen::getPixel(float x, float y) {return screen[int(round(x)) + int(round(y))*width];}

void Screen::setPixel(int x, int y, Vector3i pixel) {screen[x + y*width] = pixel;}

void Screen::setPixel(float x, float y, Vector3i pixel) {screen[int(round(x)) + int(round(y))*width] = pixel;}

void Screen::setBoarders(Vector3i color) {
    for (int column = 0; column < width; ++column) {
        setPixel(column, 0, color);
        setPixel(column, height-1, color);
    }
    for (int row = 0; row < height; ++row) {
        setPixel(0, row, color);
        setPixel(width-1, row, color);
    }
}

void Screen::drawLine(Vector2f start, Vector2f end, Vector3i color, float precision) {
    float delX = end.x - start.x;
    float delY = end.y - start.y;
    float vectorlen = sqrt(pow(delX,2) + pow(delY, 2));
    Vector2f dir = Vector2f(delX/vectorlen, delY/vectorlen);
    for (float len = 0; len < vectorlen+precision; len+=precision) {
        setPixel(start.x + len*dir.x, start.y + len*dir.y, color);
    }
}

void Screen::display() {
    for (int row = 0; row < height; ++row) {
        for (int column = 0; column < width; ++column) {
            Vector3i pixel = getPixel(column, row);
            string pix = "\x1b[48;2;" + to_string(pixel.x) + ";" + to_string(pixel.y) + ";" + to_string(pixel.z) + "m  ";
            cout << pix;
        }
        cout << "\x1b[0m\n";
    }
}

void Screen::clear() {system("cls");}

void Screen::moveUp() {
    string up = "\x1b[" + to_string(height) + "A";
    cout << up;
}
#include <iostream>
#include <cmath>

#include "input.hpp"
#include "screen.hpp"

using namespace std;

int main() {
    Init();
    cout << OSType << '\n';
    Screen scr = Screen(40, 32);
    scr.Init();
    Vector2f start = Vector2f(2.0f, 10.0f);
    Vector2f end = Vector2f(25.0f, 13.0f);
    int ch = getChar();
    while (ch != 'q') {
        switch (ch) {
        case upArrow:
            start.y -= 1;
            break;
        case downArrow:
            start.y += 1;
            break;
        case leftArrow:
            start.x -= 1;
            break;
        case rightArrow:
            start.x += 1;
            break;
        }
        start.x = max(1.0f, min(start.x, float(scr.getWidth()-2)));
        start.y = max(1.0f, min(start.y, float(scr.getHeight()-2)));
        scr.setBoarders(Vector3i(255,255,255));
        scr.drawLine(start, end, Vector3i(125, 125, 125), 0.5f);
        scr.setPixel(start.x, start.y, Vector3i(255, 0, 0));
        scr.setPixel(end.x, end.y, Vector3i(0,255,0));
        scr.display();
        scr.moveUp();
        ch = getChar();
    }
    scr.clear();
    scr.Done();
    Finish();
    return 0;
}
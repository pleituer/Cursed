#include <iostream>

#include "input.hpp"
#include "screen.hpp"

using namespace std;

int main() {
    Init();
    cout << OSType << '\n';
    int ch = getChar();
    while (ch != 'q') {
        if (ch > 0) {cout << ch << ' ';}
        if (ch > 0x7f) {
            switch (ch) {
            case upArrow:
                cout << "UP\n";
                break;
            case downArrow:
                cout << "DOWN\n";
                break;
            case leftArrow:
                cout << "LEFT\n";
                break;
            case rightArrow:
                cout << "RIGHT\n";
                break;
            }
        }
        else if (ch > 0) {cout << (char) ch << '\n';}
        ch = getChar();
    }
    Screen scr = Screen(40, 32);
    Vector2f start = Vector2f(2.0f, 10.0f);
    Vector2f end = Vector2f(25.0f, 13.0f);
    scr.setBoarders(Vector3i(255,255,255));
    scr.drawLine(start, end, Vector3i(125, 125, 125), 0.5f);
    scr.setPixel(start.x, start.y, Vector3i(255, 0, 0));
    scr.setPixel(end.x, end.y, Vector3i(0,255,0));
    scr.display();
    Finish();
    return 0;
}
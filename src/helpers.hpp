#pragma once

struct Vector2i {
    int x, y;

    Vector2i();
    Vector2i(int x, int y);
};

struct Vector2f {
    float x, y;

    Vector2f();
    Vector2f(float x, float y);
    bool operator==(const Vector2f& vec);
    bool operator!=(const Vector2f& vec);
};

struct Vector3i {
    int x, y, z;

    Vector3i();
    Vector3i(int x, int y, int z);
};

#include <iostream>

class Vector2
{
public:
    float x, y;
    Vector2(float x, float y)
        : x(x), y(y){}
    Vector2 Add(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }
    Vector2 operator+(const Vector2& other) const
    {
        return Add(other);
    }
    Vector2 Multiply(const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);
    }
    Vector2 operator*(const Vector2& other)const
    {
        return Multiply(other);
    }
};

std::ostream &operator<<(std::ostream &stream, const Vector2 &other)
{
    stream << other.x << " ," << other.y;
    return stream;
}

int main()
{
    Vector2 position(4.0f, 4.0f);
    Vector2 speedf(0.5f, 1.5);
    Vector2 powup(1.1f, 1.1f);

    Vector2 r1 = position.Add(speed.Multiply(powup));
    Vector2 r2 = position + speed * powup;

    std::cout << r2 << std::endl;
    return (0);
}
#include "Vect2D.h"

Vect2D::Vect2D()
    : x{}
    , y{}
{
}

Vect2D::Vect2D(float x, float y)
    : x{ x }
	, y{ y }
{
}

Vect2D& Vect2D::Add(const Vect2D& vec)
{
    x += vec.x;
    y += vec.y;
    return *this;
}

Vect2D& Vect2D::Subtract(const Vect2D& vec)
{
    x -= vec.x;
    y -= vec.y;
    return *this;
}

Vect2D& Vect2D::Multiply(const Vect2D& vec)
{
    x *= vec.x;
    y *= vec.y;
    return *this;
}

Vect2D& Vect2D::Divide(const Vect2D& vec)
{
    x /= vec.x;
    y /= vec.y;
    return *this;
}

Vect2D& Vect2D::operator+=(const Vect2D& vec)
{
    return Add(vec);
    return *this;
}

Vect2D& Vect2D::operator-=(const Vect2D& vec)
{
    return Subtract(vec);
}

Vect2D& Vect2D::operator*=(const Vect2D& vec)
{
    return Multiply(vec);
}

Vect2D& Vect2D::operator/=(const Vect2D& vec)
{
    return Divide(vec);
}

Vect2D& operator+(Vect2D& v1, const Vect2D& v2)
{
    return v1.Add(v2);
}

Vect2D& operator-(Vect2D& v1, const Vect2D& v2)
{
    return v1.Subtract(v2);
}

Vect2D& operator*(Vect2D& v1, const Vect2D& v2)
{
    return v1.Multiply(v2);
}

Vect2D& operator/(Vect2D& v1, const Vect2D& v2)
{
    return v1.Divide(v2);
}

std::ostream& operator<<(std::ostream& stream, const Vect2D& vec)
{
    return stream << "Vec2D(" << vec.x << "," << vec.y << ")";
}

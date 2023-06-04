#pragma once
#ifndef VECT2D_H
#define VECT2D_H

#include <iostream>

class Vect2D
{
public:
	Vect2D();
	Vect2D(float x, float y);

	float x;
	float y;

	Vect2D& Add(const Vect2D& vec);
	Vect2D& Subtract(const Vect2D& vec);
	Vect2D& Multiply(const Vect2D& vec);
	Vect2D& Divide(const Vect2D& vec);

	friend Vect2D& operator+(Vect2D& v1, const Vect2D& v2);
	friend Vect2D& operator-(Vect2D& v1, const Vect2D& v2);
	friend Vect2D& operator*(Vect2D& v1, const Vect2D& v2);
	friend Vect2D& operator/(Vect2D& v1, const Vect2D& v2);

	Vect2D& operator+=(const Vect2D& vec);
	Vect2D& operator-=(const Vect2D& vec);
	Vect2D& operator*=(const Vect2D& vec);
	Vect2D& operator/=(const Vect2D& vec);

	friend std::ostream& operator<<(std::ostream& stream, const Vect2D& vec);
};

#endif // !VECT2D_H

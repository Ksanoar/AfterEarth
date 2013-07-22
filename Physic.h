#pragma once

#include <cmath>

class Object2D {
public:
	float x, y;
	float w, h;
public:
	Object2D() : x(0.0f), y(0.0f), w(0.0f), h(0.0f) { }
	Object2D(float _x, float _y, float _w, float _h) : x(_x), y(_y), w(_w), h(_h) { }
	~Object2D() { }
};

class AABB {
public:
	static bool check(const Object2D& a, const Object2D& b) {
		if(fabs(a.x - b.x) < (a.w/2 + b.w/2) && fabs(a.y - b.y) < (a.h/2 + b.h/2)) return true;
		return false;
	}
};
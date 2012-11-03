#ifndef FL_REAL_H
#define FL_REAL_H
#include <float.h>
#include <math.h>
#include <limits>

typedef double Real;

static const Real RealEpsilon = DBL_EPSILON;
static const Real NotANumber = std::numeric_limits<Real>::quiet_NaN();

static bool isNan(const Real& num) { return num != num; }

struct Point
{
	inline Point(const Real x, const Real y) { this->x = x; this->y = y; }
	inline Point(const Point& o) { *this = o; }
	inline Point& operator = (const Point& o) { this->x = o.x; this->y = o.y; return *this; }
	inline void translate(Real dx, Real dy) { x += dx; y += dy; }
	Real x;
	Real y;
};

#endif // FL_REAL_H
#ifndef FL_REAL_H
#define FL_REAL_H

#include "FuzzyLib.h"
#include <float.h>
#include <vector>
#include <math.h>
#include <limits>

typedef double Real;
typedef std::vector<Real> Vector;

static const Real RealEpsilon = DBL_EPSILON;
static const Real NotANumber = std::numeric_limits<Real>::quiet_NaN();

static bool isNan(const Real& num) { return num != num; }

struct FL_EXPORT Point
{
	inline Point(const Real x, const Real y) { this->x = x; this->y = y; }
	inline Point(const Point& o) { *this = o; }
	inline Point& operator = (const Point& o) { this->x = o.x; this->y = o.y; return *this; }
	inline void translate(Real dx, Real dy) { x += dx; y += dy; }
	Real x;
	Real y;
};

#endif // FL_REAL_H
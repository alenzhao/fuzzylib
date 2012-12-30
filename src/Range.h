#ifndef FL_RANGE_H
#define FL_RANGE_H

#include "FuzzyLib.h"
#include "Real.h"
#include <stdlib.h>

struct FL_EXPORT Range
{
	Range(Real a = NotANumber, Real b = NotANumber) { this->a = a; this->b = b; }
	Range(const Range& o ) { *this = o; }
	Range& operator = (const Range& o ){ this->a = o.a; this->b = o.b; return *this; }
	Real a;
	Real b;
	inline bool contains(const Real val) const { return (val >= a) && (val <= b);}
	inline bool contains(const Range& o) const { return contains(o.a) && contains(o.b); }
	inline Range moved(const Real d) const { return Range(a + d, b + d); }
	inline void move(const Real d) { *this = moved(d); }

	inline Real length() const { return b - a; }
	struct RangeIterator
	{
		RangeIterator(const Range& range, Real dx = RealEpsilon) { this->range = &range; this->dx = dx; this->val = this->range->a; }
		RangeIterator(const RangeIterator& o ) { *this = o; }
		RangeIterator& operator = (const RangeIterator& o) { this->range = o.range; this->dx = o.dx; this->val = o.val; c(); return *this; }
		inline Real value() const { c(); return val; }
		inline Real operator *() const { return value(); }
		inline operator Real () const { return value(); }
		inline bool operator < (const RangeIterator& o) const { c(); return val < o.val - dx; }
		inline bool operator != (const RangeIterator& o) const { return !(*this == o); }
		inline bool operator == (const RangeIterator& o) const { c(); return abs(val - o.val) <= RealEpsilon; }
		inline Real operator ++ (int) { Real ret = val; val += dx; c(); return ret; }
		inline Real operator ++ () { val += dx; c(); return val; }
		inline Real operator += (int times) { val += times * dx; c(); return val; }
		inline Real operator -- (int) { Real ret = val; val -= dx; c(); return ret; }
		inline Real operator -- () { val -= dx; c(); return val; }
		inline Real operator -= (int times) { val -= times * dx; c(); return val; }
		inline RangeIterator end() { return RangeIterator(Range(range->b, range->b), 0.);}
		Real dx;
		const Range* range;
	protected:
		Real val;

		friend struct Range;
	private:
		void c() const { 
			if(range == 0 || val - range->a < -dx || val - range->b > dx)
				throw "RangeIterator: Out if range";
		}
	};

	RangeIterator begin(const Real dx = RealEpsilon) const;
	RangeIterator end() const;
};


typedef Range::RangeIterator RangeIterator;

#endif // FL_RANGE_H

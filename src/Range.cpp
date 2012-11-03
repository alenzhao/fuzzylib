#include "Range.h"

RangeIterator Range::begin(const Real dx) const
{
	return RangeIterator(*this, dx);
}

RangeIterator Range::end() const
{
	RangeIterator it(*this, RealEpsilon);
	it.val = b;
	return it;
}

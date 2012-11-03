#include "TriangularCharacteristicFunction.h"

TriangularCharacteristicFunction::TriangularCharacteristicFunction( Real a, Point b, Real c )
	: m_left(NULL)
	, m_right(NULL)
{
	const Real k1 = abs(b.y) / abs(b.x - a);
	const Real k2 = - abs(b.y) / abs(c - b.x);
	const Real dy1 = - a * k1;
	const Real dy2 = - c * k2;
	m_left = new LinearCharacteristicFunction(a, b.x - RealEpsilon, k1, dy1);
	m_right = new LinearCharacteristicFunction(b.x, c, k2, dy2);
}

Real TriangularCharacteristicFunction::operator()( const Real val )
{
	Real r = (*m_left)(val);
	if(isNan(r))
		return (*m_right)(val);
	return r;
}

TriangularCharacteristicFunction::~TriangularCharacteristicFunction()
{
	delete m_left;
	delete m_right;
}

#include "TrapesoidCharacteristicFunction.h"


TrapesoidCharacteristicFunction::TrapesoidCharacteristicFunction(const Real a, const Point b, const Real c, const Real d)
	: m_left(NULL)
	, m_center(NULL)
	, m_right(NULL)
	, m_a(a)
	, m_b(b)
	, m_c(c)
	, m_d(d)
{
	const Real k1 = abs(b.y) / abs(b.x - a);
	const Real k2 = - abs(b.y) / abs(d - c);
	const Real dy1 = - a * k1;
	const Real dy2 = - d * k2;
	m_left = new LinearCharacteristicFunction(a, b.x - RealEpsilon, k1, dy1);
	m_center = new LinearCharacteristicFunction(b.x, c + RealEpsilon, 0, b.y);
	m_right = new LinearCharacteristicFunction(c - RealEpsilon, d, k2, dy2);
}

Real TrapesoidCharacteristicFunction::operator()( const Real val )
{
	Real r = (*m_left)(val);
	if(isNan(r))
		r = (*m_center)(val);
	if(isNan(r))
		r = (*m_right)(val);
	return r;
}

TrapesoidCharacteristicFunction::~TrapesoidCharacteristicFunction()
{
	delete m_left;
	delete m_center;
	delete m_right;
}

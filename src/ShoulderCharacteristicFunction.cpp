#include "ShoulderCharacteristicFunction.h"


ShoulderCharacteristicFunction::ShoulderCharacteristicFunction(const Real a, const Real b)
	: m_a(a)
	, m_b(b)
{
}

Real ShoulderCharacteristicFunction::operator()( const Real val )
{
	Real a2 = m_a * m_a;
	Real x2 = abs(val * val);
	return m_b * exp(-a2/(a2 - x2));
}

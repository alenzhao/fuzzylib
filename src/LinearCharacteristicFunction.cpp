#include "LinearCharacteristicFunction.h"
#include <algorithm>

LinearCharacteristicFunction::LinearCharacteristicFunction( const Point first, const Point second )
{
	m_range.a = std::min(first.x, second.x);
	m_range.b = std::max(first.x, second.x);
	m_k = (first.y - second.y) / (first.x - second.x);
	m_dy = first.y - first.x * m_k;
}

LinearCharacteristicFunction::LinearCharacteristicFunction( const Real a, const Real b, const Real k, const Real dy )
	: m_range(a, b)
	, m_k(k)
	, m_dy(dy)
{

}

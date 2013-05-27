#include "PolynomialCharacteristicFunction.h"


PolynomialCharacteristicFunction::PolynomialCharacteristicFunction( const Real a0, const Real a1, const Real a2 )
{
	m_coeficents.resize(3);
	m_coeficents[0] = a0;
	m_coeficents[1] = a1;
	m_coeficents[2] = a2;
}

PolynomialCharacteristicFunction::PolynomialCharacteristicFunction( Vector coeficents )
	: m_coeficents(coeficents)
{

}

PolynomialCharacteristicFunction::~PolynomialCharacteristicFunction()
{

}

Real PolynomialCharacteristicFunction::operator () (Real val)
{
	Vector::const_iterator i = m_coeficents.cbegin();
	Real exp = 0;
	Real res = *i;
	Real powered = 1;
	++i;
	for(; i < m_coeficents.cend(); ++i)
	{
		powered *= val;
		const Real& c = *i;
		if( c > 0)
		{
			res += c * powered;
		}
	}
	return res;
}

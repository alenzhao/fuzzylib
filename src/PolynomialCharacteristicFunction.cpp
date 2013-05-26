#include "PolynomialCharacteristicFunction.h"


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

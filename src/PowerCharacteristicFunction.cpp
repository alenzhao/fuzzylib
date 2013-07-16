#include "PowerCharacteristicFunction.h"
#include "PolynomialCharacteristicFunction.h"
#include <math.h>

PowerCharacteristicFunction::PowerCharacteristicFunction(Real exponenta)
	: m_exp(exponenta)
{
	m_arg.reset(new PolynomialCharacteristicFunction(0, 1, 0));
}

PowerCharacteristicFunction::PowerCharacteristicFunction(CharacteristicFunction::CharacteristicFunctionPtr arg, Real exponenta)
	: m_exp(exponenta)
{
	m_arg = arg;
}

PowerCharacteristicFunction::~PowerCharacteristicFunction(void)
{
}

Real PowerCharacteristicFunction::operator()( const Real val )
{
	Real arg = val;
	if(m_arg.get() != NULL)
		arg = (*m_arg)(val);
	return Real(pow(arg, (double) m_exp));
}

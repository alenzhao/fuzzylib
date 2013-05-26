#include "PowerCharacteristicFunction.h"
#include <math.h>

PowerCharacteristicFunction::PowerCharacteristicFunction(Real exponenta)
	: m_exp(exponenta)
{
}

PowerCharacteristicFunction::~PowerCharacteristicFunction(void)
{
}

Real PowerCharacteristicFunction::operator()( const Real val )
{
	return Real(pow(val, (double) m_exp));
}

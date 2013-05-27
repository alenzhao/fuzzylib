#ifndef FL_POLYNOMIAL_CHARACTERISTIC_FUNCTION_H
#define FL_POLYNOMIAL_CHARACTERISTIC_FUNCTION_H

#include "FuzzyLib.h"
#include "CharacteristicFunction.h"

class FL_EXPORT PolynomialCharacteristicFunction:
	public CharacteristicFunction
{
public:
	PolynomialCharacteristicFunction(const Real a0, const Real a1, const Real a2); // a0 + a1 * x + a2 * x^2
	PolynomialCharacteristicFunction(Vector coeficents);
	virtual ~PolynomialCharacteristicFunction();
	virtual Real operator () (Real val);
private:
	Vector m_coeficents;
};

#endif // FL_POLYNOMIAL_CHARACTERISTIC_FUNCTION_H
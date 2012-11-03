#ifndef FL_TRIANGULAR_CHARACTERISTIC_FUNCTION_H
#define FL_TRIANGULAR_CHARACTERISTIC_FUNCTION_H

#include "CharacteristicFunction.h"
#include "LinearCharacteristicFunction.h"
#include "Range.h"
#include "Real.h"

class TriangularCharacteristicFunction :
	public CharacteristicFunction
{
public:
	TriangularCharacteristicFunction(Real a, Point b, Real c);
	virtual ~TriangularCharacteristicFunction();
	virtual Real operator()(const Real val);
private:
	LinearCharacteristicFunction* m_left;
	LinearCharacteristicFunction* m_right;
};

#endif // FL_TRIANGULAR_CHARACTERISTIC_FUNCTION_Hs
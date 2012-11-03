#ifndef FL_SHOULDER_CHARACTERISTIC_FUNCTION_H
#define FL_SHOULDER_CHARACTERISTIC_FUNCTION_H

#include "CharacteristicFunction.h"
#include "Real.h"
#include <math.h>

class ShoulderCharacteristicFunction :
	public CharacteristicFunction
{
public:
	ShoulderCharacteristicFunction(const Real a, const Real b);
	virtual Real operator () (const Real val);
private:
	Real m_a;
	Real m_b;
};

#endif // FL_SHOULDER_CHARACTERISTIC_FUNCTION_H
